#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,z=0,x,o1,o2;
	cin>>n>>m;
	int a[n*m];
	int b[n][m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=a.size-1;j!=0;j--){
			if(a[i]<a[j]){
				a[i]==a[j];
				a[j]==a[i];
			}
		}
	}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
			if(i%2!=0){
				j=n-1;
			}else{
				j=0;
			}
				for(;z;){
					b[j][i]=a[z];
					cuntiune;
					z+=1;
					if(z==n*m){
						break;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(b[i][j]==x;
					o1=i,o2=j;
					break;
				}
		}
		cout<<o1<<" "<<o2;
		return 0;
}
