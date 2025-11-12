#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	bool zs=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1) zs=1;
	}
	if(!zs) cout<<n/2;
	return 0;
}
