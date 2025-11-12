#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[0]<a[i]) a[0]==a[i];
	} 
	cout<<a[0];
	return 0;
} 
