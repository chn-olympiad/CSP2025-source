#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]!=k){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else if(n==2){
		ll temp=a[1]^a[2];
		if(a[1]==k&&a[2]==k){
			cout<<2;
		}
		else if((a[1]==k||a[2]==k)||temp==k){
			cout<<1;
		}
	}
	return 0;
}
