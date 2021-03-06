#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int max(int a, int b){
		return (a>b)?a:b;
}
int knapsack(int W, int w[],int p[],int n){
	if(n==0||W==0){
		return 0;
	}
	if(w[n-1]>W){
		return knapsack(W,w,p,n-1);
	}
	else{
		return max(p[n-1]+knapsack(W-w[n-1],w,p,n-1),knapsack(W,w,p,n-1));
	}
}
main(){
	int i,n,W;
	printf("Enter the number of items: ");
	scanf("%d",&n);
	int w[n],p[n];
	for(i=0;i<n;i++){
		printf("Enter the weight of item %d: ",i);
		scanf("%d",&w[i]);
		printf("Enter the profit of item %d: ",i);
		scanf("%d",&p[i]);
		printf("\n");
	}
	printf("\n");
	printf("Enter the weight of knapsack: ");
	scanf("%d",&W);
	printf("\nMax profit is: %d",knapsack(W,w,p,n));
}
