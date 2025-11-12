#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505, mod = 998244353;
int c[N], sa[N];
int n, m;
string s;
bool chk(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '0')
			return false;
	return true;
}
void solve1()
{
	int cnt = n;
	for (int i = 1; i <= n; i++)
		if (!c[i]) cnt--;
	
	if (cnt < m)
	{
		cout << '0';
		return;
	}
	ll ans = 1;
	for (ll i = 1; i <= cnt; i++) ans = ans * i % mod;
	cout << ans << '\n';
}
void solve2()
{
	ll ans = 0;
	memset(sa, 0, sizeof sa);
	for (int i = 1; i <= n; i++)
	{
		sa[i] = sa[i - 1];
		if (s[i - 1] == '0') sa[i]++;
	}
	for (int i = 1; i <= n; i++)
	{
		int id = lower_bound(sa + 1, sa + n + 1, c[i]) - sa;
		if (sa[id] == id) continue;
		ll mul = 1;
		for (ll i = 1; i <= n - 1; i++) mul = (mul * i) % mod;
		ans = (ans + mul) % mod;
	}
	cout << ans << '\n';
}
void solve3()
{
	int a[15];
	int mul = 1;
	for (int i = 1; i <= n; i++) 
	{
		mul *= i;
		a[i] = i;
	}
	int ans = 0;
	while (mul--)
	{
		next_permutation(a + 1, a + n + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c[a[i]] <= cnt) cnt++;
			if (!s[i - 1]) cnt++;
		}
		cout << cnt << '\n';
		if (n - cnt >= m) ans++;
	}
	cout << ans << '\n';
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 10) solve3();
	if (m == n && !chk(s))
	{
		cout << 0;
		return 0;
	}
	if (chk(s)) solve1();
	
	if (m == 1)
	{
		solve2();
	}
	return 0;
}
