#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], ans = 0;
void dfs(long long x, long long sum, long long now, long long maxx, bool f)
{
	if (x == n)
	{
		if (maxx * 2 < sum && !f)
		{
			ans++;
			ans = ans % 998244353;
		}
		if (a[x] * 2 < sum + a[x] && now >= 2)
		{
			ans++;
			ans = ans % 998244353;
		}
		return ;
	}
	if (now < 3)
	{
		dfs(x + 1, sum + a[x], now + 1, a[x], 0);
		dfs(x + 1, sum, now, maxx, 1);
	}
	else
	{
		if (maxx * 2 < sum && !f)
		{
			ans++;
			ans = ans % 998244353;
		}
		dfs(x + 1, sum + a[x], now + 1, a[x], 0);
		f = 1;
		dfs(x + 1, sum, now, maxx, 1);
		f = 0;
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	dfs(1, 0, 0, 0, 1);
	cout << ans;
	return 0;
}
