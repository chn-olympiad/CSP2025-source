#include<bits/stdc++.h>
int o;
int u;
int n,k;
int a[10009];
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			o++;
			u=1;
		}
	}
	if(u==1){
		cout<<o;
	}
	else{
		cout<<0;
	}
	return 0;
} 
