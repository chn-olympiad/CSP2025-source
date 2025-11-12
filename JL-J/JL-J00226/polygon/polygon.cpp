#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[505][50505],g[50505];
int a[1145141];
const int mod=998244353;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,a[i]);
	sort(a+1,a+1+n);
	g[0]=1ll;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		for(int j=sum;j>=a[i];j--)dp[i][j]=(dp[i][j]+g[j-a[i]])%mod;
		for(int j=sum;j>=a[i];j--)g[j]=(g[j]+dp[i][j])%mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]*2+1;j<=sum;j++)ans=(ans+dp[i][j])%mod;
	}
	cout<<ans;
	return 0;
}
