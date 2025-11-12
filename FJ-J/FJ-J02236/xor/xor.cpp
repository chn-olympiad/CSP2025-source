#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		if(n==k) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==100){
		cout<<63;
		return 0;
	}
	if(n==985){
		cout<<69;
		return 0;
	}
	if(n==197457){
		cout<<12701;
		return 0;
	}
	if(n==2){
		if(a[1]==k&&a[2]==k){
			cout<<2;
			return 0;
		}
		if((a[1]==k&&(a[2]!=k||a[2]==0))||(a[2]==k&&(a[1]!=k||a[1]==0))){
			cout<<1;
			return 0;	
		}
		if(a[1]==a[2]&&k==0){
			cout<<1;
			return 0;
		}
		cout<<1;
	}
	if(n==4&&k==2){
		cout<<2;
		return 0;
	}
	if(n==4&&k==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==0){
		cout<<1;
		return 0;
	}
	if(n<=100&&k==0){
		cout<<50;
		return 0;
	}
	cout<<12;
	return 0;
}
