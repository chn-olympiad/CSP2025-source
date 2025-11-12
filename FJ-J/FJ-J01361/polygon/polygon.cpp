# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 5e3 + 10;
const int mod = 998244353;
int n;
int a[N];
int ans;
map < pair < int, pair < int, int > >, int > f;
int dfs(int i, int val, int maxx)
{
	if (i > n)
	{
		if (val > 2 * maxx) return 1;
		return 0;
	}
	int res = 0;
	if (f.count({i + 1, {val + a[i], maxx}})) res = (res + f[{i + 1, {val + a[i], maxx}}]) % mod;
	else res = (res + (f[{i + 1, {val + a[i], maxx}}] = dfs(i + 1, val + a[i], max(maxx, a[i]) % mod))) % mod;
	if (f.count({i + 1, {val, maxx}}))res = (res + f[{i + 1, {val, maxx}}]) % mod;
	else res = (res + (f[{i + 1, {val, maxx}}] = dfs(i + 1, val, maxx) % mod)) % mod;
	return res % mod;
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	cout << dfs(1, 0, 0);
	return 0;
}
