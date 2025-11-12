#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[200005][3], a, b;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> a >> b;
		int c = -1, d;
		for (int u = 0; u < a.size(); u++)
		{
			if (a[u] != b[u])
			{
				if (c == -1)
				{
					c = u;
				}
				d = u;
			}
		}
		int e = d - c + 1, w = 0;
		for (int v = 1; v <= n; v++)
		{
			if (s[v][1].size() >= e)
			{
				w = 1;
				break;
			}
		}
		if (w == 0 || a.size() != b.size())
		{
			cout << 0 << "\n";
		}
	}
	return 0;
}
