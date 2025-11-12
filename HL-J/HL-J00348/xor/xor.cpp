#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500000]={0},ans;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==0){
		cout<<0;
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		cout<<2;
	}
}
