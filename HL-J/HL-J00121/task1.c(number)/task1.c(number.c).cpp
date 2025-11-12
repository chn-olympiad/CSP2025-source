#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int a[15] [15];
int n,m;
int main(){

	for(int i=1,i<n;i++){
		for(int j=m;j>=0;j--){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=m;j<n;j++){
			cout<<a[i][j]<<" ";
		}
	}
}

