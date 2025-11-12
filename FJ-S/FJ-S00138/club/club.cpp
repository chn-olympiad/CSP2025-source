#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
long long T, n, a[N][5], dp[N][5], cnt[N][5][5], value, p;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				p = 0;
				for (int k = 1; k <= 3; k++)
				{
					if (dp[i - 1][k] >= dp[i - 1][p] && cnt[i - 1][j][k] < n / 2)
					{
						p = k;
					}
				}
				for (int k = 1; k <= 3; k++) cnt[i][j][k] = cnt[i - 1][j][p];
				dp[i][j] = dp[i - 1][p] + a[i][j];
				cnt[i][j][j]++;
			}
		}
		cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << endl;;
	}
	return 0;
}
