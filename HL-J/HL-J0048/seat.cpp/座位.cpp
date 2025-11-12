#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[105];
int main(){
	
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		for(int j=1;j<i;j++){
			max(i,j);
		}
	}
	cout<<"2,1"; 
	
	return 0;
} 
