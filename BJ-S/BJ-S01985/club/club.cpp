#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 210, N2 = 100010;
int a[3], dp[N][N];
int x[N2], num[N2][3], dp2[N2];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, ans;
	cin >> t;
	bool flag;
	while (t--)
	{
		cin >> n;
		if (n <= 200)
		{
			ans = 0;
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= n - i; j++)
				{
					dp[i][j] = 0;
				}
			}
			for (int i = 1; i <= n; i++)
			{
				cin >> a[0] >> a[1] >> a[2];
				a[0]++;
				a[1]++;
				a[2]++;
				dp[0][i] = dp[0][i - 1] + a[2];
				dp[i][0] = dp[i - 1][0] + a[1];
				for (int j = i; j > 0; j--)
				{
					for (int k = i - j; k > 0; k--)
					{
						dp[j][k] = max(max(dp[j][k - 1] + a[2], dp[j - 1][k] + a[1]), dp[j][k] + a[0]);
					}
				}
				for (int j = i - 1; j > 0; j--)
				{
					dp[0][j] = max(dp[0][j] + a[0], dp[0][j - 1] + a[2]);
					dp[j][0] = max(dp[j - 1][0] + a[1], dp[j][0] + a[0]);
				}
				dp[0][0] += a[0];
			}
			for (int i = 1; i <= n / 2; i++)
			{
				for (int j = n / 2 - i; j <= n / 2; j++)
				{
					if (i + j >= n / 2)
					{
						ans = max(ans, dp[i][j]);
					}
				}
			}
			cout << ans - n << endl;
		}
		else
		{
			ans = 0;
			flag = true;
			for (int i = 1; i <= n; i++)
			{
				cin >> num[i][0] >> num[i][1] >> num[i][2];
				x[i] = num[i][1] - num[i][0];
				ans += num[i][0];
				flag = (flag && num[i][2] == 0);
			}
			if (!flag)
			{
				ans = 0;
				for (int i = 1; i <= n; i++)
				{
					ans += max(max(num[i][0], num[i][1]), num[i][2]);
				}
				cout << ans << endl;
			}
			else
			{
				sort(x + 1, x + n + 1);
				for (int i = n; i > n / 2; i--)
				{
					ans += x[i];
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}