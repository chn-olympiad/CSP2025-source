#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 5e3 + 10, mod =  998244353;
long long n, a[N], ans, jzsum;
void dfs(long long x, long long num, long long sum, long long maxx)
{
	if (num + n - x < 3) return;
	if (maxx * 2 >= jzsum) return;
	if (num >= 3 && sum > maxx * 2)
	{
		ans++;
		ans %= mod;
	}
	if (x >= n) return;
	for (int i = x + 1; i <= n; i++)
	{
		long long now = max(maxx, a[i]);
		dfs(i, num + 1, sum + a[i], now);
	}
	return;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		jzsum += a[i];
	}
	dfs(0, 0, 0, 0);
	cout << ans;
	return 0;
}