#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 5 , mod = 998244353;
signed n , m , c[N];
string s;
signed main ()
{
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i ++) cin >> c[i];
	if (m == n)
	{
		int ans = 1;
		for (int i = 1;i <= n;i ++)
		{
			ans = ans * i % mod;
			if (c[i] == 0 || s[i - 1] == 0) ans = 0;
		}
		cout << ans;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
