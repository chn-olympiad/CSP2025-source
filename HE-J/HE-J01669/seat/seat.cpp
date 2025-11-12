#include<bits/stdc++.h>
using namespace std;
int n,m,n2,m2;
int bb(int b[]){
	int i;
	return 0;
}
int main(){
	cin>>n>>m;
	int a[n*m],b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	bb(b);
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++){
			
			if(a[0]==0){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>0;j--){
			
			if(a[0]==0){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
