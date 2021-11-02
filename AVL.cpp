#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int data;
	node *left;
	node *right;
	int height;
	int bf;
};
struct node*new_node(int k)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=k;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->height=0;
	newnode->bf=0;
	return newnode;
}
struct node left(struct node*nodel)
{
	struct  node*nodet1=nodel->right;
	struct  node*nodet2=nodet1->left;
	nodet1->left=nodel;
	nodet2=nodel->right;
	nodet1->height=1+max(getheight(nodet1-<left),getheight(node->right));	
	nodel->height=1+max(getheight(nodet1-<left),getheight(node->right));
	return nodet1;
}
int getbalance(struct node* nodeb)
{
		
	    if (nodeb->left!=NULL && nodeb->right!=NULL)
		{
			return (nodeb->left->height+1) - (nodeb->right->height +1);
		}
		else if(nodeb->left!=NULL){
			return 	nodeb->left->height+1;
		}
		else if(nodeb->right!=NULL){
			return 	nodeb->right->height+1;
		}
		else
		{
			return 0;
		}
		
}
int getheight(struct node*nodeh)
{
	if(nodeh==NULL)
	{
		return 0;
	}
	return (nodeh->height);
}
int max(int a,int b)
{
	return (a>b) ? a : b;
}
struct node*insert(struct node*node1,int k)
{
	if(node1==NULL)
	{
		return new_node(k);
	}
	if(node1->data <k)
	{
		node1->right=insert(node1->right,k);
	}
	else	
	{
		node1->left=insert(node1->left,k);
	}
	node1->height=1+max(getheight(node1->right),getheight(node1->left));
	node1->bf=getbalance(node1);
	
}
void inorder(struct node *node2)
{
	if(node2==NULL)
	{
		return;
	}
	inorder(node2->left);
	printf("\n%d\n",node2->data);

	printf("\n BF %d\n",node2->bf);
	inorder(node2->right);
}
int main()
{
	struct node*root=NULL;
	root=insert(root,11);
	insert(root,5);
	insert(root,6);
	insert(root,7);
	insert(root,8);
	inorder(root) ;

	return 0;
}

