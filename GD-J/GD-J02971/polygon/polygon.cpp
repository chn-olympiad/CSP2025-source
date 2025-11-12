#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int mod=998244353;
int n,a[5005],sum,dp[25000005][2];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		for (int j=sum;j>=a[i];j--)
		{
			if (j>2*a[i])
				dp[j][1]=(dp[j][1]+dp[j-a[i]][0])%mod;
			dp[j][0]=(dp[j][0]+dp[j-a[i]][0])%mod;
		}
	}
	int s=0;
	for (int i=0;i<=sum;i++)
		s+=dp[i][1],s%=mod;
	cout << s;
	return 0;
}
