#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	if(n%2==1){
		cout << -1;
	}
	int a[3][n]={};
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	int zd[n]={};
	int z=0;
	int y=0;
	int m=0;
	while(y=n-1){
		while(m=2){
			for(int f=0;f<n;f++){
				if(a[m][f]>z){
					z=a[m][f];
				}
			}	
			zd[y]=z;
		}
		y+=1;
	}
	int jieguo=0;
	for(int x=0;x<n;x++){
		jieguo=jieguo+zd[x];
	}
	cout << jieguo;
} 
