#include <bits/stdc++.h>
using namespace std;
const int N = 200480;
string x[N], y[N];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	for (int i = 1; i <= q; ++i)
	{
		string s, t, u;
		int ans = 0;
		cin >> s >> u;
		for (int j = 1; j <= n; ++j)
		{
			int p = s.find(x[j]);
			while (p != string::npos)
			{
				t = s.substr(0, p) + y[j] + s.substr(p + x[j].size(), s.size() - p - x[j].size());
				if (t == u)
					++ans;
				p = s.find(x[j], p + 1);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
