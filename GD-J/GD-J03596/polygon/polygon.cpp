#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 * 6 + 300;
const int MOD = 998244353;
int l[N], n, cnt;
void dfs (int x, int sl, int sum, int max_s, int max_xs)
{
	if (x > max_xs)
	{
		if (sl >= 3)
		{
			cnt = (cnt + ((sum > max_s * 2) ? 1 : 0)) % MOD;
		}
		return ;
	}
	dfs (x + 1, sl + 1, sum + l[x], max_s, max_xs);
	dfs (x + 1, sl, sum, max_s, max_xs);
	return ;
}
int main ()
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%d", &l[i]);
	}
	sort (l + 1, l + n + 1);
	for (int i = 3; i <= n; ++i)
	{
		dfs (1, 0, 0, l[i], i);
	}
	printf ("%d", cnt);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
