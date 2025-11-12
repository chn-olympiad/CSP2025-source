#include <bits/stdc++.h>
#define ing long long
using namespace std;
map <string, string> mp;
signed main()
{ 
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
	{
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	while (q --)
	{
		string a, b;
		cin >> a >> b;
		if (a.size() != b.size())
		{
			cout << "0\n";
		}
		string d = "", r = "";
		int p = -1, j = -1;
		for (int i = 0; i < a.size(); i ++)
		{
			if (a[i] != b[i])
			{
				p = i;
				break;
			}
		}
		for (int i = b.size() - 1; i >= 0; i --)
		{
			if (a[i] != b[i])
			{
				j = i;
				break;
			}
		}
		for (int i = p; i <= j; i ++)
		{
			r += a[i];
			d += b[i];
		}
		if (mp[r] == d)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}
	return 0;
}
