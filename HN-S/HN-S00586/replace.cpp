#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void FileIO (string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 2e5 + 10, P = 131, mod = 1e9 + 7;

int n, q, hsh_[1010][2], len[1010], hsh[1010][2], p[N], ans, l, r;
string s, s_, t, t_;

int Hash (bool f, int l, int r) {
	return (hsh[r][f] - 1ll * hsh[l - 1][f] * p[r - l + 1] % mod + mod) % mod;
}

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	FileIO("replace");
	cin >> n >> q, p[0] = 1;
	for (int i = 1; i <= 1000; i++) p[i] = 1ll * p[i - 1] * P % mod;
	for (int i = 1; i <= n; i++) {
		cin >> s >> s_, hsh_[i][0] = hsh_[i][1] = 0, len[i] = s.size();
		for (int j = 1; j <= len[i]; j++) hsh_[i][0] = (1ll * hsh_[i][0] * P + s[j - 1] - 'a') % mod;
		for (int j = 1; j <= len[i]; j++) hsh_[i][1] = (1ll * hsh_[i][1] * P + s_[j - 1] - 'a') % mod;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t >> t_, hsh[0][0] = hsh[0][1] = 1, ans = 0, t = ' ' + t, t_ = ' ' + t_, r = 0, l = t.size();
		for (int j = 1; j < t.size(); j++) hsh[j][0] = (1ll * hsh[j - 1][0] * P + t[j] - 'a') % mod;
		for (int j = 1; j < t.size(); j++) hsh[j][1] = (1ll * hsh[j - 1][1] * P + t_[j] - 'a') % mod;
		// cout << Hash(0, 1, 5) << ' ' << hsh_[1][0] << ' ' << len[1] << '\n';
		for (int j = 1; j < t.size(); j++)
			if (t[j] != t_[j])
				l = min(l, j), r = max(r, j);
		for (int j = r; j < t.size(); j++)
			for (int k = 1; k <= n; k++)
				if (j >= len[k] && j - len[k] + 1 <= l) {
					if (Hash(0, j - len[k] + 1, j) == hsh_[k][0] && Hash(1, j - len[k] + 1, j) == hsh_[k][1]) ans++;
					// cout << j - len[k] + 1 << ' ' << j << ' ' << k << ' ' << ans << '\n';
				}
		cout << ans << '\n';
	}
	return 0;
}
/*
2 1
xabcx xadex
bc de
xabcx xadex

*/
