#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define per(i, r, l) for (int i = r; i >= l; i --)
#define int long long

using namespace std;

const int maxn = 2e3 + 5, mod = 998244353;

int T;
int n, m, c[maxn];
int f[(1 << 19)][19];


signed main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	/**/
	cin >> n >> m;
	string s;
	cin >> s;
	rep(i, 1, n) cin >> c[i - 1];
	f[0][0] = 1;
	rep(i, 1, (1 << n) - 1) {
		int popc = __builtin_popcount(i);
//		cout << i << ' ' << popc << '\n';
		rep(k, 0, popc) {
			if (k == 0) {
				rep(j, 0, n - 1) {
					int op = (1 << j);
					if (!(i & op)) continue ;
					if (popc - 1 - k >= c[j] || s[popc - 1] == '0')
						(f[i][k] += f[i ^ op][k]) %= mod;
				}
			} 
			else {
				rep(j, 0, n - 1) {
					int op = (1 << j);
					if (!(i & op)) continue ;
					if (popc - 1 - k >= c[j] || s[popc - 1] == '0')
						(f[i][k] += f[i ^ op][k]) %= mod;
					if ((popc - k < c[j]) && s[popc - 1] == '1')
						(f[i][k] += f[i ^ op][k - 1]) %= mod;
				}
			}	
		}
	}
	int ans = 0;
	rep(i, m, n) (ans += f[(1 << n) - 1][i]) %= mod;
	cout << ans << '\n';
} 
/*
3 2
101
1 1 2

*/
