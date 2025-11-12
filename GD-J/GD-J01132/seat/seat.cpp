#include<bits/stdc++.h>
using namespace std;
int a[10010];
int n,m,r,b;	
int mian(){
	cin>>n>>m;
	int map[n+10][m+10];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){
			b=a[i];
			a[i]=a[i+1];
			a[i+1]=b;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n*m;k++){
				map[i][j]=a[k];
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			}
		} 
	}
	return 0;
} 
