// 去你的 AC 自动机
// 出题人 you have no egg 
#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;
const int N = 2e5 + 5;
int T = 1, n, q, l[N], b1[N], b2[N];
string s1[N], s2[N], t1, t2;
void solve ()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> s1[i] >> s2[i],
		l[i] = s1[i].size ();
	if (n <= 100)
	{
		while (q --)
		{
			int ans = 0;
			cin >> t1 >> t2;
			int len = t1.size ();
			if (len != t2.size ())
			{
				cout << "0\n";
				continue;
			}
			for (int i = 1; i <= n; ++ i)
			{
				if (len < l[i])
					continue;
				if (len == l[i])
				{
					if (s1[i] == t1 && s2[i] == t2)
						++ ans;
					continue;
				}
				for (int j = 0; j + l[i] - 1 < len; ++ j)
				{
					bool f = 1;
					for (int k = 0; k < l[i]; ++ k)
						if (s1[i][k] ^ t1[j + k] || s2[i][k] ^ t2[j + k])
						{
							f = 0;
							break;
						}
					if (f)
					{
						++ ans;
						for (int k = j + l[i]; k < len; ++ k)
							if (t1[k] ^ t2[k])
							{
								-- ans;
								break;
							}
						break;
					}
				}
			}
			cout << ans << '\n';
		}
		return;
	}
	for (int i = 1; i <= n; ++ i)
	{
		for (int j = 0; j < l[i]; ++ j)
		{
			if (s1[i][j] == 'b')
				b1[i] = j;
			if (s2[i][j] == 'b')
				b2[i] = j;
		}
	}
	while (q --)
	{
		cin >> t1 >> t2;
		int c1, c2, ans = 0;
		if (t1.size () != t2.size ())
		{
			cout << "0\n";
			continue;
		}
		int len = t1.size ();
		for (int i = 0; i < len; ++ i)
		{
			if (t1[i] == 'b')
				c1 = i;
			if (t2[i] == 'b')
				c2 = i;
		}
		for (int i = 1; i <= n; ++ i)
		{
			if (c1 - b1[i] + b2[i] == c2 && b1[i] <= c1 && l[i] - b1[i] - 1 <= len - c1 - 1)
				++ ans;
		}
		cout << ans << '\n';
	}
}
signed main ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	while (T --)
		solve ();
	return 0;
}
