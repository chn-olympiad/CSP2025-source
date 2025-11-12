#include <bits/stdc++.h>
using namespace std;

long long dp[2][105][105][105];

int a1[100005], a2[100005], a3[100005];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		if(n != 100000)
		{
			for(int i = 1; i <= n; i++) cin >> a1[i] >> a2[i] >> a3[i];
			int t = 0;
			long long maxn = -1e9;
			memset(dp, 0xc0, sizeof(dp));
			dp[0][0][0][0] = 0;
			for(int i = 1; i <= n; i++)
			{
				t = 1 - t;
				for(int j = 0; j <= i; j++)
				{
					if(j > n / 2)	break;
					for(int k = 0; k <= i - j; k++)
					{
						if(k > n / 2)	break;
						int now = i - j - k;
						if(now > n / 2)	continue;
						dp[t][j][k][now] = dp[1 - t][j][k][now];
						if(j - 1 >= 0)	dp[t][j][k][now] = max(dp[t][j][k][now], dp[1 - t][j - 1][k][now] + a1[i]);
						if(k - 1 >= 0)	dp[t][j][k][now] = max(dp[t][j][k][now], dp[1 - t][j][k - 1][now] + a2[i]);
						if(now - 1 >= 0)	dp[t][j][k][now] = max(dp[t][j][k][now], dp[1 - t][j][k][now - 1] + a3[i]);
						maxn = max(maxn, dp[t][j][k][now]);
					}
				}
			}
			cout << maxn << endl;
		}
		else
		{
			for(int i = 1; i <= n; i++) cin >> a1[i] >> a2[i] >> a3[i];
			sort(a1 + 1, a1 + n + 1, cmp);
			long long ans = 0;
			for(int i = 1; i <= n / 2; i++) ans += a1[i];
			cout << ans << endl;
		}
	}
	return 0;
}
