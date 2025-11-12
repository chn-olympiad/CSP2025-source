#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
ll n,a[5005],ans,dp[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll all=1;
	dp[0]=1;
	for(ll i=1;i<=n;i++){
		ll sum=0;
		for(ll j=a[n];j>=0;j--){
			if(j<=a[i]) sum=(sum+dp[j])%MOD;
			if(j>=a[i]) dp[j]=(dp[j]+dp[j-a[i]])%MOD;
//			cout<<i<<' '<<j<<' '<<dp[j]<<'\n';
		}
		if(i>=3) ans=(ans+all-sum+MOD)%MOD;
		all=all*2%MOD;
	}
	cout<<ans;
	return 0;
}
