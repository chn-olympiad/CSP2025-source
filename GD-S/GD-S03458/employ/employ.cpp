#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int mod = 998244353;
int n, m, c[N], p[N], ans;
string s;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s; s = ' ' + s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) p[i] = i;
	do {
		int res = 0, tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (tmp >= c[p[i]]) {
				tmp++;
				continue ;
			}
			if (s[i] == '1') res++;
			else tmp++;
		}
		if (res >= m) ans++;
	} while (next_permutation(p + 1, p + 1 + n));
	cout << ans % mod;	
	return 0;
}
