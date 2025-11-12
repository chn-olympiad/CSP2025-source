#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _ = 500 + 10;
const ll MOD = 998244353;
int c[_];
void solve();
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
	return 0;
}
void solve()
{
	ll n, m, ans = 1, cnt = 0;
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (c[i] == 0)
			cnt++;
	}
	for (int i = n - cnt; i >= n - cnt - m; i--)
	{
		ans *= i;
		ans %= MOD;
	}
	cout << ans % MOD << " "; 
	for (int i = n - m; i >= 1; i--)
	{
		ans *= i;
		ans %= MOD;
	}
	cout << ans % MOD << '\n';
}

