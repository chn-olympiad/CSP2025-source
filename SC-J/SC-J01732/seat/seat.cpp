#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[19][19];
int n,m,t;
int b;
int main(){
	cin>>n>>m>>t;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k;k<=n*m-1;k++){
		if(a[i][j]>a[i+1][j+1]){
			b=a[i][j];
			a[i][j]=a[i+1][j+1];
			a[i+1][j+1]=b;
		}
		else
		continue;	
	}
		}
	}
	
	return 0;
} 