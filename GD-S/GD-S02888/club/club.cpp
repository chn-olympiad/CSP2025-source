#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T, n, dp[205][205][205];
bool flag1 = true, flag2 = true;
struct node
{
	ll a, b, c;
} d[100005];
bool cmp1(node one, node two)
{
	return one.a > two.a;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (ll i = 1; i <= n; i++)
		{
			cin >> d[i].a >> d[i].b >> d[i].c;
			if (d[i].b != 0)
			{
				flag1 = false;
			}
			if (d[i].c != 0)
			{
				flag2 = false;
			}
		}
		if (n <= 200)
		{
			ll ans = -1e18;
			memset(dp, -0x3f3f3f3f, sizeof(dp));
			dp[0][0][0] = 0;
			for (ll i = 1; i <= n; i++)
			{
				for (ll j = 0; j <= n / 2; j++)
				{
					for (ll k = 0; k <= n / 2; k++)
					{
						if (j + k > i || i - j - k > n / 2)
						{
							continue;
						}
						dp[i][j][k] = dp[i - 1][j][k] + d[i].c;
						if (j > 0)
						{
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + d[i].a);
						}
						if (k > 0)
						{
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + d[i].b);
						}
					}
				}
			}
			for (ll i = 0; i <= n / 2; i++)
			{
				for (ll j = 0; j <= n / 2; j++)
				{
					if (i + j > n || n - i - j > n / 2)
					{
						continue;
					}
					ans = max(ans, dp[n][i][j]);
				}
			}
			cout << ans << endl;
		}
		else if (flag1 && flag2)
		{
			ll ans = 0;
			sort(d + 1, d + n + 1, cmp1);
			for (ll i = 1; i <= n / 2; i++)
			{
				ans += d[i].a;
			}
			cout << ans << endl;
		}
		else if (flag2)
		{
			ll ans = 0;
			for (ll i = 1; i <= n / 2; i++)
			{
				ans += d[i].a;
			}
			for (ll i = n / 2 + 1; i <= n; i++)
			{
				ans += d[i].b;
			}
			cout << ans << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/
