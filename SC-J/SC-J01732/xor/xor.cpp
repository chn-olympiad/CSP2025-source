#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int a[1000][1000];
int main(){
	cin>>n>>m;
	for(int i;i<n;i++){
		for(int j;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k;k<=n*m-1;k++){
				if(a[i][j]>a[i+1][j+1]){
					int b;
					b=a[i][j];
					a[i][j]=a[i+1][j];
					a[i+1][j]=b;
				}
			}
		} 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cout<<a[i][j];
		}
	}
	return 0;
}