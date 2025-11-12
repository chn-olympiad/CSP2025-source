#include <bits/stdc++.h>
int sz[5005];
using namespace std;
int qh(int a,int b){
	int c;
	for(int i=a;i<=b;i++){
		c+=sz[i];
	}
	return c;
}
int zd(int a,int b){
	int lt=a;
	for(int i=a;i<=b;i++){
		if(sz[lt]<sz[i]){
			lt=i;
		}
	}
	return lt;
}
int main(int argc, char** argv) {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>sz[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;i++){
			if(qh(i,j)>zd(i,j)*2){
					cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
