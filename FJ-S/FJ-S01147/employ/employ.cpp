#include <bits/stdc++.h>
using namespace std;
int p, n, m, i, c[500], Mod = 998244353, ans, f[10007];
string s;
int main()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	int bf = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '0')
		{
			bf++;
		}
		for (int j = 1; j <= n; j++)
		{
			if (c[i] > 0)
			c[i]--;
			f[i]++;
		}
	}
	cout << f[n] % Mod;
	return 0;
}
