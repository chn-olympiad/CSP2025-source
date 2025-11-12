#include <iostream>

using namespace std;

const int MaxN = 20, mod = 998244353, MaxA = 510;

int f[1 << MaxN][MaxN], dp[MaxA][MaxA][MaxA], s[MaxA], ct[MaxA], c[MaxA], t[MaxN], p[MaxA], cnt, tot, n, m, ans;

int cound(int x, int res = 0) {
	for (x; x; x -= x & -x, res++) {
	}
	return res;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c, s[i] = c - '0', p[s[i]]++;
		cnt += s[i];
	}
	for (int i = n; i >= 0; i--) {
		p[i] += p[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n >= 19) {
		for (int i = n; i >= 1; i--) {
			if (s[i] == 1) {
				t[++tot] = i;
			}
		}
		f[0][0] = 1;
		if (tot < m) {
			cout << 0 <<'\n';
			return 0;
		} else {
		for (int i = 1; i <= tot; i++) { // 考虑到第几位 
			for (int j = 0; j <= tot; j++) { // 过了几个人 
				if (j) f[i][j] += f[i - 1][j - 1] * (p[t[i] + 1] - (j - 1));
				f[i][j] += f[i - 1][j];
			}
		}
		for (int i = m; i <= tot; i++) {
//			ans += i;
		}
		}
	} else {
	f[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i & (1 << (k - 1))) continue;
				if (c[k] <= cound(i) - j || !s[cound(i) + 1]) f[i | (1 << (k - 1))][j] = (f[i | (1 << (k - 1))][j] + f[i][j]) % mod;
				else f[i | (1 << (k - 1))][j + 1] = (f[i | (1 << (k - 1))][j + 1] + f[i][j]) % mod;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		ans = (ans + f[(1 << n) - 1][i]);
	}
	cout << ans << '\n';
	}
	return 0;
}
