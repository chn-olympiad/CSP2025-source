#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
int n, m, s[N], c[N], ans = 1;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; cin >> s[i++]);
	for(int i = 1; i <= n; cin >> c[i++]);
	for(int i = n; i >= 1; i--) ans *= i;
	return cout << ans, 0;
}
