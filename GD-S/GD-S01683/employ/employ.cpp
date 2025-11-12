#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
int n, m, c[505], jc[505];
string s;

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	bool flag = 1;
	for (int i = 1; i <= n; ++i)
	{
		char c;
		cin >> c;
		if (c == '0')flag = 0;
		s += c;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}
	
	if (flag)
	{
		int ans = 1;
		for (int i = 2; i <= n; ++i)
		{
			ans = (ans * i) % MOD;
		}
		cout << ans;
	}
	return 0;
}
