// GZ-S00280 贵阳市第一实验中学 林钰涵
#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, Base = 10007;
int n, q, mxlen, len[200005], c[5000005], hhsh[2][5000005];
vector<int> hsh[2][200005];
string s[2][200005], t[2];

inline bool check(int p, int l1, int l2, int len) {
	int r1 = l1 + len - 1, r2 = l2 + len - 1;
	int v01 = (hsh[0][p][r1] - 1ll * hsh[0][p][l1 - 1] * c[len] % mod + mod) % mod;
	int v02 = (hhsh[0][r2] - 1ll * hhsh[0][l2 - 1] * c[len] % mod + mod) % mod;
	int v11 = (hsh[1][p][r1] - 1ll * hsh[1][p][l1 - 1] * c[len] % mod + mod) % mod;
	int v12 = (hhsh[1][r2] - 1ll * hhsh[1][l2 - 1] * c[len] % mod + mod) % mod;
	return v01 == v02 && v11 == v12;
}

inline void solve() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[0][i] >> s[1][i];
		len[i] = s[0][i].size();
		s[0][i] = ' ' + s[0][i];
		s[1][i] = ' ' + s[1][i];
		hsh[0][i].resize(len[i] + 1, 0);
		hsh[1][i].resize(len[i] + 1, 0);
		mxlen = max(mxlen, len[i]);
	}
	c[0] = 1;
	for (int i = 1; i <= mxlen; i++) {
		c[i] = 1ll * c[i - 1] * Base % mod;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= len[j]; k++) {
				hsh[i][j][k] = (1ll * hsh[i][j][k - 1] * Base + s[i][j][k] - 'a') % mod;
			}
		}
	}
	while (q--) {
		cin >> t[0] >> t[1];
		int m = t[0].size();
		t[0] = ' ' + t[0], t[1] = ' ' + t[1];
		int l = -1, r = -1;
		for (int i = 1; i <= m; i++) {
			if (t[0][i] != t[1][i]) {
				if (l == -1) l = i;
				r = i;
			}
		}
		if (r - l + 1 > mxlen) {
			printf("0\n");
			continue;
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= m; j++) {
				hhsh[i][j] = (1ll * hhsh[i][j - 1] * Base + t[i][j] - 'a') % mod;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = max(r - len[i] + 1, 1); j <= l && j + len[i] - 1 <= m; j++) {
				if (check(i, 1, j, len[i])) {
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	solve();
	return 0;
}
