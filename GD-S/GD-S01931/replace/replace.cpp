#include <bits/stdc++.h>
using namespace std;

string s[200005][3], t[200005][3];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= q; i++)
		cin >> t[i][1] >> t[i][2];
	for (int i = 1; i <= q; i++)
	{
		if (t[i][1].size() != t[i][2].size())
		{
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		for (int j = 1; j <= n; j++)
		{
			int len = s[j][1].size();
			for (int k = 0; k + len - 1 < t[i][1].size(); k++)
			{
				string a = t[i][1].substr(k, len);
				if (a == s[j][1])
				{
					string b = t[i][1].substr(0, k) + s[j][2] + t[i][1].substr(k + len, t[i][1].size() - 1);
//					cout << b << "\n";
					if (b == t[i][2])
					{
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
