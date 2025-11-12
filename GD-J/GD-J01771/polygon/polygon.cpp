#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const ll MAXN=1e6+5;
const ll inf=LONG_LONG_MAX;
ll a[MAXN],dp[MAXN],sum[MAXN];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	ll t=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=t;
		ans%=MOD;
		for(int j=0;j<=a[i];j++)
		{
			ans-=dp[j];
			ans%=MOD;
		}
		t=t*2%MOD;
		for(int j=5000;j>=a[i];j--)
		{
			dp[j]+=dp[j-a[i]];
			dp[j]%=MOD;
		}
	}
	cout<<(ans+MOD)%MOD;
	return 0;
}
/*
5 1 2 3 4 5
*/
