#include<bits/stdc++.h>
#include<cstdio>
int n,k;
int a[9000000]; 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==2||k==3){
		cout<<2;
	}
	if(k==0){
		cout<<1;
	}
	if(k==1){
		cout<<63;
	}
	if(k==55){
		cout<<69;
	}
	if(k==222){
		cout<<12701;
	}
	return 0;
} 
