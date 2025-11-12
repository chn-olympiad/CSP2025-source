#include <bits/stdc++.h>
using namespace std;
int m, n, a[505], g[505], MOD = 998244353, ans, cnt = 0;
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (s[i - 1] == '1')
		{
			g[i] = g[i - 1] + 1;
		}
		else
		{
			g[i] = g[i - 1];
		}
	}
	if (g[n] == n)
	{
		ans = 1;
		for (int i = n; i >= 1; i--)
		{
			ans = ans * i % 998244353;
		}
		cout << ans;
		return 0; 
	}
	
	return 0;
}
