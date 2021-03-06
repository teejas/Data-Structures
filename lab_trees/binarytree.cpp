/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary tree
 *  is just the length of the longest path from the root to a leaf, and that the
 *  height of an empty tree is -1.
 */

#include <iostream>
using namespace std;


template <typename T>
int BinaryTree<T>::height() const
{
	// Call recursive helper function on root
	return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	// Base case
	if (subRoot == NULL)
        return -1;
	
	// Recursive definition
	return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that node
 *  itself, and everything to the right of a node will be printed out after that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
	// Call recursive helper function on the root
	printLeftToRight(root);

	// Finish the line
	cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node * subRoot) const
{
	// Base case - null node
	if (subRoot == NULL)
		return;

	// Print left subtree
	printLeftToRight(subRoot->left);

	// Print this node
	cout << subRoot->elem << ' ';

	// Print right subtree
	printLeftToRight(subRoot->right);
}
//***************MIRROR**********************************************************
/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
	// your code here
	mirror(root);
}

template <typename T>
typename BinaryTree<T>::Node * BinaryTree<T>::mirror(Node * subRoot)const
{
	if (subRoot == NULL)
		return NULL;
		
	Node * temp;
	temp = mirror(subRoot->left);
	subRoot->left = mirror(subRoot->right);
	subRoot->right = temp;
	return subRoot;		
}
//***************MIRROR**********************************************************











//***************isOrdered********************************************************
/**
 * @return True if an in-order traversal of the tree would produce a nondecreasing list
 *  output values, and false otherwise. This is also the criterion for a binary tree to be
 *  a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
	if (root == NULL)
		return 1;

	int nodes = 2;
	for (int i = 0; i < height(); i++)
	{
		nodes = nodes * nodes;
	}
	nodes--;
	
	T arr[nodes];
	for (int i = 0; i < nodes; i++)
	{
		arr[i] = NULL;
	}
	
	unsigned int counter = 0;
	isOrdered(root, arr, counter);
	
	for(int i = 1; i < counter; i++)
	{
		if (arr[i] < arr[i-1])
			return false;
	}
return true;
}

template <typename T>
void BinaryTree<T>::isOrdered(Node * subRoot, T arr[], unsigned int &counter)const
{	
	if(root == NULL)
		return;

	if(subRoot->left != NULL)
		isOrdered(subRoot->left, arr, counter);

	
		arr[counter] = subRoot->elem;
//		cout<<subRoot->elem<<" ";
		counter++;
	
	
	if(subRoot->right != NULL) 
		isOrdered(subRoot->right, arr, counter);

}


/*
{
	if (isOrdered(root))
		return 1;
	
	else
		return 0;	
}
	
	
template <typename T>
bool BinaryTree<T>::isOrdered(Node * subRoot)const	
{		
	if (subRoot == NULL)
		return 1;

	if (subRoot->left != NULL)
	{
		isOrdered(subRoot->left);
		
		if (((subRoot->elem) < (subRoot->left->elem)) || ((subRoot->elem) > (max_left(root)->elem)))
			return 0;
	}
	
	if (subRoot->right != NULL)
	{
		isOrdered(subRoot->right);
		
		if (((subRoot->elem) > (subRoot->right->elem)) || ((subRoot->elem) < (min_right(root)->elem)))
			return 0;
	}

	return 1;
}
	
template <typename T>
typename BinaryTree<T>::Node * BinaryTree<T>::max_left(Node * subRoot)const
{
	
	if (subRoot->left != NULL)
	{
		subRoot = subRoot->left;
		while (subRoot->right != NULL)
			subRoot = subRoot->right;

		return subRoot;
	}
	//here the value of subRoot if the max on the left sub tree
	else
		return root;	
}


template <typename T>
typename BinaryTree<T>::Node * BinaryTree<T>::min_right(Node * subRoot)const
{
		
	if (subRoot->right != NULL)
	{
		subRoot = subRoot->right;
		while (subRoot->left != NULL)
			subRoot = subRoot->left;
	
		return subRoot;
	}
	//here the value of subRoot if the max on the left sub tree
	else
		return root;	

}	 	
*/
//***************isOrdered********************************************************


//***************printPaths********************************************************
/**
 * Prints out all the possiccble paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards, ending at a
 *  leaf node. Paths ending in a left node should be printed before paths ending in a node
 *  further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
	if (root == NULL)
		return;
	unsigned int counter = 0;
	unsigned int nodes = height();
	T arr[nodes];
	for (int i = 0; i < nodes; i++)
	{
		arr[i] = NULL;
	}	 

	
	preorder(root, arr, 0);

}


	
template <typename T>
void BinaryTree<T>::preorder(Node *subRoot, T arr[], unsigned int counter)const	
{

	if (subRoot == NULL)
		return;

	
	arr[counter] = subRoot->elem;
		counter++;

	if (subRoot->left == NULL && subRoot->right == NULL)
		print_array(arr, counter);
		//
	
	else
	{
		if (subRoot->left != NULL)
			preorder(subRoot->left, arr, counter);
		
		if (subRoot->right != NULL)
			preorder(subRoot->right, arr, counter);
	}		

}
		
	
template <typename T>
void BinaryTree<T>::print_array(T arr[], unsigned int &counter)const	
{
	cout<<"Path: ";
	for(int i = 0; i < counter; i++)
	{
		cout<<arr[i];
		cout<<" ";
	}
	cout <<""<<endl;

}
















//***************printPaths********************************************************
/**
 * Each node in a tree has a distance from the root node - the depth of that node,
 *  or the number of edges along the path from that node to the root. This function returns
 *  the sum of the distances of all nodes to the root node (the sum of the depths of all
 *  the nodes). Your solution should take O(n) time, where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    if (root == NULL)
		return -1;

	unsigned int sum = 0;

	return sumDistances(root, sum);	
}

template <typename T>
int BinaryTree<T>::sumDistances(Node * subRoot, unsigned int sum)const
{	
	if(subRoot == NULL)
		return 0;

	sum = sum + sumDistances(subRoot->left, sum+1) + sumDistances(subRoot->right, sum+1);
	return sum;
}
