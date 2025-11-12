#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int t, n, a[100005][5], dp[100005][5], pt[100005][5][5];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		memset(pt, 0, sizeof(pt));
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		dp[1][1] = a[1][1];
		dp[1][2] = a[1][2];
		dp[1][3] = a[1][3];
		pt[1][1][1] = pt[1][2][2] = pt[1][3][3] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
//				if (pt[i - 1][j] == n >> 1) continue;
//				dp[i][j] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][2]}) + a[i][j];
				int maxk = 0;
				for (int k = 1; k <= 3; k++) // i - 1 -> k
				{
					if (pt[i - 1][k][j] >= (n >> 1)) continue;
					if (dp[i - 1][k] + a[i][j] >= dp[i][j])
					{
						dp[i][j] = dp[i - 1][k] + a[i][j];
						maxk = k;
					}
				}
				for (int k = 1; k <= 3; k++)
				{
					pt[i][j][k] = (k == maxk ? pt[i - 1][maxk][k] + 1 : pt[i - 1][maxk][k]);
					// cout << i << j << k << " " << maxk << " " << pt[i][j][k] << endl;
				}
			}
		}
		cout << max({dp[n][1], dp[n][2], dp[n][3]}) << endl;
	}
	return 0;
}
