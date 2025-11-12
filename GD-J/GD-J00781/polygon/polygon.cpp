#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],maxn,ans;
int dp[10010];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maxn=2*a[n]+1;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		int need=2*a[i]+1;
		for(int j=maxn+a[i];j>=a[i];j--)
		{
			if(dp[j-a[i]]>0)
			{
				int num=min(j,maxn);
				if(num>=need)
				{
					ans=(ans+dp[j-a[i]])%998244353;
				}
				dp[num]=(dp[num]+dp[j-a[i]])%998244353;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
