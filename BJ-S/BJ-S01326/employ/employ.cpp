#include <bits/stdc++.h>

#define _for(i, a, b) for (int i = (a); i <= (int)(b); i ++ )

using namespace std;

const int N = 510, M = (1 << 18), mod = 998244353; //////
int n, m;
string s;
int a[N];
namespace sub1{
	int f[19][M][19];
	int main() {
		cin >> s;
		_for (i, 0, n - 1) cin >> a[i];
		f[0][0][0] = 1;
		_for (i, 0, n - 1)
			_for (j, 0, (1 << n) - 1)
				if (__builtin_popcount(j) == i) {
					_for (v, 0, i) {
						_for (k, 0, n - 1)
							if (!(j >> k & 1)) {
								int x = ((a[k] <= v) || (s[i] == '0'));
							//	cout << i << ' ' << j << ' ' << k << ' ' << a[k] << ' ' << v << ' ' << x << '\n';
								f[i + 1][j | (1 << k)][v + x] = (f[i + 1][j | (1 << k)][v + x] + f[i][j][v]) % mod;
							}
					}
				}
		int ans = 0;
		_for (i, 0, n - m) ans = (ans + f[n][(1 << n) - 1][i]) % mod;
		cout << ans << '\n';
		return 0;	
	}
}

namespace sub2{
	int main() {
		cin >> s;
		int k = 1;
		_for (i, 0, n - 1) {
			cin >> a[i];
			k = min(k, a[i]);
		}
		_for (i, 0, n - 1) 
			if (s[i] == '0') k = 0;
		int ans = k;
		_for (i, 1, n) ans = 1ll * ans * i % mod;
		cout << ans << '\n';
		return 0;
	}
}

namespace sub3{
	int f[N][N][N], cnt[N], sumcnt[N], c[N][N], A[N][N], pw[N];
	int main() {
		cin >> s;
		pw[0] = 1;
		_for (i, 1, n) {
			cin >> a[i];
			cnt[a[i]] ++;
			pw[i] = 1ll * pw[i - 1] * i % mod;
		}
		sumcnt[0] = cnt[0];
		_for (i, 1, n) sumcnt[i] = sumcnt[i - 1] + cnt[i];
		_for (i, 0, n) {
			c[i][0] = c[i][i] = 1;
			_for (j, 1, i - 1)
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
		_for (i, 0, n)
			_for (j, 0, i) A[i][j] = 1ll * c[i][j] * pw[j] % mod;
		f[0][0][0] = 1;
		_for (i, 0, n - 1) 
			_for (j, 0, i) 
				_for (k, 0, i - j) {
					if (j > sumcnt[j]) continue;
					if (s[i] == '1' && n - sumcnt[j] > k) f[i + 1][j][k + 1] = (f[i + 1][j][k + 1] + f[i][j][k]) % mod;
					_for (x, 0, min(cnt[j + 1], k)) {
						if (j < sumcnt[j] && n - sumcnt[j + 1] >= k - x) 
							f[i + 1][j + 1][k - x] = (f[i + 1][j + 1][k - x] + 1ll * f[i][j][k] * (sumcnt[j] - j) % mod * A[k][x]) % mod;
					}
				}
		/*
		_for (i, 1, n)
			_for (j, 0, i)
				_for (k, 0, i - j) cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << '\n';
		*/
		int ans = 0;
		_for (j, 0, n - m)
			_for (k, 0, n) {
				ans = (ans + 1ll * pw[k] * f[n][j][k] % mod) % mod;
				// cout << j << ' ' << k << ' ' << f[n][j][k] << '\n';
			}
		cout << ans << '\n';
		return 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (n <= 18) { ///////
		sub1::main();
	}
	else if (m == n) {
		sub2::main();
	}
	else sub3::main();
	return 0;
}
