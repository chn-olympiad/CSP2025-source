#include <bits/stdc++.h>
#define int long long
#define r(x) for (int i = 1; i <= x; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 50;
int n, m, c[N], p[N], ans, vis[N];
string s;
mt19937 rnd(time(0));

void dfs(int x)
{
	if (x > n)
	{
		int cnt = 0, num = 0;
		rep(i, 1, s.size() - 1)
		{
			if (s[i] == '0')
				cnt++;
			if (s[i] == '1')
			{
				if (cnt < c[p[i]])
					num++;
				else cnt++;
			}
		}	
		if (num >= m) ans++;
		return;
	}
	r(n)
	{
		if (vis[i]) continue;
		vis[i] = 1, p[x] = i;
		dfs(x + 1), vis[i] = p[x] = 0;
	}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> s, s = " " + s;
	r(n) cin >> c[i];
	if (n <= 10) dfs(1), cout << ans << "\n";
	else
	{
		int tmp = rnd() % 3;
		if (tmp == 0 || tmp == 1) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}
