#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N =  5 * 1e4 + 10, mo = 998244353, INF = 0x3f3f3f3f, RP = LONG_LONG_MAX;

int n, a[N], d[N], ans;
bool quan = true, v[N];

int f(int x, int n)
{
	int nn = n % mo, ansf = 1;
	for (int i = 1; i <= x; i++)
		ansf = ((ansf % mo) * nn) % mo, nn--;
	return ansf % mo;
}

int dfs(int sit, int need, int maxl, int sum)
{
	if (d[sit])
	{
		return d[sit];
	}
	if (need == 0)
	{
		if (maxl > sum / 2)
			d[sit]++;
		return d[sit];
	}
	for (int i = 1; i <= n; i++)
		if (v[i])
		{
			v[i] = false;
			d[sit] += dfs(i, need - 1, max(maxl, i), sum + a[i]);
		}
	return 1145;
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
		if (i >= 2 and a[i] != a[i - 1])
			quan = false;
	}
	if (quan)
	{
		for (int i = 3; i <= n; i++)
			ans += f(i, n) % mo;
		cout << ans;
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				v[i] = true;
			for (int j = 1; j <= n; j++)
				ans += dfs(j, i, -INF, a[j]);
		}
		cout << ans;
	}
	
	return 0;
 } 
