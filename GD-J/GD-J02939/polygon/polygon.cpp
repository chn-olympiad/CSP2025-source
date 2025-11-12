#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
ll n, max_n = -1;
ll a[10005];
ll f[5005][5005] = {0};
bitset<500010> s;
inline void init()
{
	f[1][1] = 1;
	f[2][1] = 2;
	f[2][2] = 1;
	f[3][1] = 3;
	f[3][2] = 3;
	f[3][3] = 1;
	f[4][1] = 4;
	f[4][2] = 6;
	f[4][3] = 4;
	f[4][4] = 1;
	for (int i = 5; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j == 1)
			{
				f[i][j] = i;
			}
			if (j == i)
			{
				f[i][j] = 1;
			}
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
		}
	}
}
inline ll C(ll m, ll n)//m -> n
{
	if (m == n)
	{
		return 1;
	}
	return f[m][n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		max_n = max(max_n, a[i]);
		s[a[i]] = 1;
	}
	if (n <= 3)
	{
		if (n < 3)
		{
			cout << 0;
			exit(0);
		}
		ll cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			cnt += a[i];
			max_n = max(max_n, a[i]);
		}
		if (cnt > max_n * 2)
		{
			cout << 1;
			exit(0);
		}
		else
		{
			cout << 0;
			exit(0);
		}
	}
	if (max_n <= 1)
	{
		init();
		ll ans = 0;
		for (int i = 3; i <= n; ++i)
		{
			ans = (ans + C(n, i)) % mod;
		}
		cout << ans;
		exit(0);
	}
	for (int i = 1; i <= n; ++i)
	{
		s <<= a[i];
		s[a[i]] = 1;
	}
	max_n <<= 1;
	int cnt_1 = 0;
	for (int i = 0; i < max_n; ++i)
	{
		if (s[i] == 1)
		{
			++cnt_1;
		}
	}
	cout << s.count() - cnt_1;
	return 0;
}
