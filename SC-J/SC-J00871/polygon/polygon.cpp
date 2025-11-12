#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5,mod=998244353;
ll a[N],n,dp[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+1+n);
	ll ans=0;dp[0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=a[i]+1;j<=5001;j++)
			ans=(ans+dp[j])%mod;
		for(ll j=5001;j>=0;j--)
			if(dp[j]>0)
			dp[min(5001ll,j+a[i])]=(dp[min(5001ll,j+a[i])]+dp[j])%mod;
	}
	cout<<ans;
	return 0;
}