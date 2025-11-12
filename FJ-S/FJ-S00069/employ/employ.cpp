#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 505;
const int MOD = 998244353;
int n, m, t;
string s;
int d[MAXN], c[MAXN];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.length(); i ++)
	{
		if (s[i] == '1')
			d[i] = 0;
		else
			d[i] = -1;
	}
	ll ans = 1;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> c[i];
		if (c[i] == 0) t ++;
	}
	if (n - t < m)
		{ cout << 0 << endl; return 0; }
	for (int i = 1; i <= n; i ++)
	{
		if (d[i] == 0)
			m --;
		if (m == 0)
		{
			for (int j = 2; j <= n; j ++)
				ans = (ans * i) % MOD;
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}
