#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 998244353;
ll n, m, s[19], c[19], cnt[(1 << 18) + 5], f[(1 << 18) + 5][19][19];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char ch; cin >> ch;
		s[i] = ch - '0';
	}
	for (int S = 0; S < (1 << n); S++) {
		for (int i = 1; i <= n; i++) {
			if (S & (1 << (i - 1))) {
				cnt[S]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		ll x = 0;
		if (c[i] == 0 || s[1] == 0) x = 1;
		f[1 << (i - 1)][x][i] = 1;
	}
	for (int S = 0; S < (1 << n); S++) {
		for (int i = 1; i <= n; i++) {
			if (S & (1 << (i - 1))) continue;
			for (int j = 1; j <= n; j++) {
				if (!(S & (1 << (j - 1)))) continue;
				for (int x = 0; x <= cnt[S]; x++) {
					ll v = 0;
					if (x >= c[i] || (cnt[S] < n && !s[cnt[S] + 1])) v = 1;
					f[S | (1 << (i - 1))][x + v][i] = (f[S | (1 << (i - 1))][x + v][i] + f[S][x][j]) % p;
					//cout << (S | (1 << (i - 1))) << ' ' << x + v << ' ' << i << " <--- " << S << ' ' << x << ' ' << j << '\n';
				}
			}
		}
	}
	//for (int S = 0; S < (1 << n); S++) for (int x = 0; x <= cnt[S]; x++) for (int i = 1; i <= n; i++) cout << S << ' ' << x << ' ' << i << ' ' << f[S][x][i] << '\n';
	ll ans = 0;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 1; j <= n; j++) {
			ans = (ans + f[(1 << n) - 1][i][j]) % p;
		}
	}
	cout << ans << '\n';
	return 0;
} 
/*
f[S][x][i] 表示来面试的员工集合为 S ，最后一个为 i ，淘汰 x 人的方案数 
f[S][x][i] += f[S ^ (1 << (j - 1))][(x - 1 >= c[i] ? x - 1 : )
3 2
101
1 1 2
*/
