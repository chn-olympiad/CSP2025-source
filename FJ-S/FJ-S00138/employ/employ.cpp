#include <bits/stdc++.h>
#include <cstdio>
const int N = 5e2 + 10, mod = 998244353;
using namespace std;
long long n, m, c[N], ans;
string s;
bool vis[N], tp;
void dfs(long long x, long long num)
{
	if (x + n - num < m) return;
	if (num > n) return;
	if (x >= m)
	{
		ans++;
		ans %= mod;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && num - x < c[i])
		{
			if (s[num] == '1')
			{
				vis[i] = true;
				dfs(x + 1, num + 1);
				vis[i] = false;
			}
			else
			{
				vis[i] = true;
				dfs(x, num + 1);
				vis[i] = false;
			}
		}
	}
	return;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	tp = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0') tp = false;
	}
	if (tp)
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
		{
			ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}
