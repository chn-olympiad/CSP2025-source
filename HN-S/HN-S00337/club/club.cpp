#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[500005][3];
int dp[205][205][205];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		for(int i = 0;i <= n;i++)
		{
			for(int j = 0;j <= n;j++)
			{
				for(int k = 0;k <= n;k++)
				{
					dp[i][j][k] = -1e9;
				}
			}
		}
		dp[0][0][0] = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j <= n;j++)
			{
				for(int k = 0;k <= i-j;k++)
				{
					int l = i-j-k;
					if(j > 0)
					{
						dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+a[i][0]);
					}
					if(k > 0)
					{
						dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][1]);
					}
					if(l > 0)
					{
						dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0;i <= n/2;i++)
		{
			for(int j = 0;j <= n/2;j++)
			{
				int k = n-i-j;
				if(2*k > n)continue;
				ans = max(ans,dp[n][i][j]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
