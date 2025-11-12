#include<bits/stdc++.h>
using namespace std;
int n, q, ans;
string s1[200005], s2[200005], x, y, a, b;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		if (x.size() != y.size())
		{
			cout << 0 << endl;
			continue;
		}
		for (int j = 1; j <= n; j++)
		{
			int d = 0;
			bool f = false;
			for (int k = 0; k < x.size(); k++)
			{
				if (x[k] == s1[j][d] && y[k] == s2[j][d])
				{
					if (f)
					{
						ans--;
						break;
					}
					if (d == s1[j].size() - 1)
					{
						ans++;
						f = true;
					}
					else
					{
						d++;
					}
				}
				else if (x[k] != y[k])
				{
					break;
				}
			}
		}
		cout << ans;
		ans = 0;
	}
	return 0;
}
