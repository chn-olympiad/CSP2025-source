#include <bits/stdc++.h>
using namespace std;
int n, q, l, ans, minl = 1e9, maxl, s, d, cnt;
string a, b, x, y;
map <string, string> t;
bool g, h, f;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		minl = min(minl, int(a.size()));
		maxl = max(maxl, int(a.size()));
		t[a] = b;
		t[b] = a;
	} 
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		l = x.size();
		ans = 0;
		if (l != y.size())
		{
			cout << 0 << '\n';
			continue;
		}
		cnt = 0;
		f = 1;
		for (int i = 1; i <= l; i++)
		{
			if (x[i - 1] != y[i - 1])
			{
				if (f)
				{
					s = i - 1;
					f = 0;
				}
				d = i - 1;
				cnt++;
			}
		}
		if (d - s + 1 > maxl || cnt < minl)
		{
			cout << 0 << '\n';
			continue;
		}
		for (int j = 0; j < l; j++)
		{
			for (int k = minl; k <= min(l - j, maxl); k++)
			{
				g = 0, h = 0;
				if (t[x.substr(j, k)] == y.substr(j, k))
				{
					if (j != 0)
					{
						if (x.substr(0, j) != y.substr(0, j))
						{
							g = 1;
						}
					}
					if (k != l - j)
					{
						if (x.substr(j + k) != y.substr(j + k))
						{
							h = 1;
						}
					}
					if (!g && !h)
					{
						ans++;
						//cout << x.substr(j, k) << '\n';
					}
				} 
			}
		}
		cout << ans << '\n'; 
	}
	return 0;
}
