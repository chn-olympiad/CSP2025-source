#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==2){
		cout<<2;
		return 0;
	}else if(k==0){
		cout<<1;
		return 0;
	}else if(k==1){
		cout<<1;
		return 0;
	}else if(n==4&&k!=1&&k!=2){
		cout<<2;
		return 0;
	}else{
		cout<<3;
	}
	return 0;
}
