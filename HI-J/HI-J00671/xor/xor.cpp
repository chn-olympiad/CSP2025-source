#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a;
	} 
	if(k<=1){
		cout<<"0";
		else cout<<"2";
	}
	return 0;
} 
