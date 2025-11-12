#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll a[500005];
ll b[500005];
ll dp[500005];
ll ma;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(ll r=1;r<=n;r++){
		dp[r]=dp[r-1];
		for(ll l=r-1;l>=0;l--){
			ll c=b[r]^b[l];
			if(c==k){
				dp[r]=max(dp[r],dp[l]+1);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		ma=max(dp[i],ma);
	}
	cout<<ma;
	return 0;
}