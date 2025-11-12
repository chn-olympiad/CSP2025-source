#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, u = 0, v = 0, ans = 1, N = 998244353;
	cin >> n >> m;
	char ss[n];
	int s[n], c[n];
	for(int i = 0; i < n; i ++)
	{
		cin >> ss[i];
		s[i] = ss[i] - '0';
	}
	for(int i = 0; i < n; i ++) cin >> c[i];
	for(int i = 0; i < n; i ++) if(s[i] == 1) u ++;
	for(int i = 0; i < n; i ++) if(c[i] > 0) v ++;
	if(u < m || v < m) ans = 0;
	if(m == 1)
	{
		for(int i = 1; i <= n; i ++)
		{
			ans *= i;
			ans %= N;
		}
	}
	if(m == n)
	{
		if(u == m and v == n)
		{
			for(int i = 1; i <= n; i ++)
			{
				ans *= i;
				ans %= N;
			}
		}
		else ans = 0;
	}
	cout << ans;
	return 0;
}