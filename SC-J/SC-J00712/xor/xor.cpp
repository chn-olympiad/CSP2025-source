#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,k,ans=0;cin>>n>>k;
	vector<ll> a(n+1),b(n+1);
	for(ll i=1;i<=n;i++)cin>>a[i],b[i]=(a[i]^b[i-1]);
	for(ll l=1;l<=n;l++)
		for(ll r=l;r<=n;r++)if((b[r]^b[l-1])==k)ans++;
	cout<<ans;
	return 0;
}