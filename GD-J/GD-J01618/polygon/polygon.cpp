#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n;
int a[5007];
int dp[5007][2];//more than 5001 -> 5001
int ans = 0;
signed main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dp[0][0] = 1;
	for(int i=1;i<=n;i++)
	{
		if(i>=3)
		{
			for(int j=a[i]+1;j<=5001;j++)
				ans = (ans + dp[j][!(i&1)]) % MOD;
		}
		for(int j=0;j<=5001;j++)
			dp[j][i&1] = dp[j][!(i&1)];
		for(int j=0;j<=5001;j++)
			dp[min(j+a[i],5001ll)][i&1] = (dp[min(j+a[i],5001ll)][i&1] + dp[j][!(i&1)]) % MOD;
//		for(int j=0;j<=15;j++)
//			cout<<dp[j][i&1]<<" ";
//		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
