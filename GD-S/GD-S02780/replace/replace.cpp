#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q, ans;
string a[200001];
string b[200001];
bool repl(string s, string t, int p)
{
	for (int i = s.find(a[p]); i < s.size(); i++)
	{
		if (s.substr(i, a[p].size()) == a[p]) 
		{
			string c = s;
			for (int j = i; j < i + a[p].size(); j++)
			{
				c[j] = b[p][j - i];
			}
			if (c == t) 
			{
				return 1;
			}
		}
	}
	return 0;
}
signed main()
{
	#ifndef DEBUG
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	#endif // DEBUG
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= q; i++)
	{
		string s, t;
		ans = 0;
		cin >> s >> t;
		for (int j = 1; j <= n; j++)
		{
			if (s.find(a[j]) != s.size())
			{
				ans += repl(s, t, j);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
