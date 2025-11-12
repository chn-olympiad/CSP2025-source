#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N][2], s1, s2;
int n, q, p, l, x, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];
	while (q--)
	{
		cin >> s1 >> s2; l = s1.size(); ans = 0;
		if (l != (int)s2.size()) cout << "0\n";
		else
		{
			for (int i = 1; i <= n; i++)
			{
				p = s1.find(s[i][0]); x = s[i][0].size();
				if (p != l + 1)
					if (s1.substr(0, p) + s[i][1] + s1.substr(p + x, l - p - x) == s2)
						ans++;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}