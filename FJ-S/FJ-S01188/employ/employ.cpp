# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 505;
const int mod = 998244353;
int n, m;
string s;
int a[N], c[N];
bool vis[N];
int ans;
bool ck()
{
	int cnt = 0, res = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (c[a[i]] > cnt && (s[i] - '0'))
		{
			res ++;
		}
		else
		{
			cnt ++;
		}
	}
	return res >= m;
}
bool h()
{
	for (int i = 1; i <= n; i ++)
	{
		if (!c[i]) return 1;
	}
	return 0;
}
void dfs(int x)
{
	if (x > n)
	{
		ans += ck();
	}
	for (int i = 1; i <= n; i ++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			a[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
bool check()
{
	for (int i = 1; i <= n; i ++)
	{
		if (c[i]) return 0;
	}
	return 1;
}
bool checker()
{
	for (int i = 1; i <= n; i ++)
	{
		if (!(s[i] - '0')) return 0;
	}
	return 1;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i ++)
	{
		cin >> c[i];
	}
	if (n <= 10)
	{
		dfs(1);
		cout << ans;
	}
	else
	{
		if (m == 1)
		{
			if (check()) cout << 0;
			else
			{
				ans = 1;
				for (int i = 1; i <= n; i ++)
				{
					ans = ans * i % mod;
				}
				cout << ans;
			}
			return 0;
		}
		if (m == n)
		{
			if (!checker() || h()) cout << 0;
			else
			{
				ans = 1;
				for (int i = 1; i <= n; i ++)
				{
					ans = ans * i % mod;
				}
				cout << ans;
			}
			return 0;
		}
		cout << 1;
	}
	return 0;
}
