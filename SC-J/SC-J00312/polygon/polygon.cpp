#include <bits/stdc++.h>

using namespace std;

const int N = 5005, MOD = 998244353;

int n, a[N], ans, bjt = 1;

void dfs (int x, int maxx, long long sum, int gs)
{
	if (x == n + 1)
	{
		if (gs >= 3 && sum > maxx * 2)
		{
			ans ++;
			ans %= MOD;
			return ; 
		}
		return ;
	}
	dfs (x + 1, max (maxx, a[x]), sum + a[x], gs + 1);
	dfs (x + 1, maxx, sum, gs);
}

long long work (int x, int y)
{
	unsigned long long res = 1;
	for (int i = x;i <= y;i ++)
	{
		res *= i;
	}
	return res;
}

int main ()
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			bjt = 0;
		}
	}
	if (bjt)
	{
		long long res = 0;
		for (int i = n;i >= 3;i --)
		{
			long long tmp = ((work (n - i + 1, n)) / (work (1, i)));
			res += tmp;
			res %= MOD;
		}
		cout << res % MOD << endl;
		return 0;
	}
	dfs (1, -2e9, 0, 0);
	cout << ans % MOD;
	return 0;
}
