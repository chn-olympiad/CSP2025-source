#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 2005, M = 4005, B = 131, Mod = 1e9 + 7;

int n, q, tot, L1, L2, hs[M], ht[M], p[M];
string s, t;
map<pii, int> mp;

int Hashs(int l, int r) {
	return (hs[r] - 1ll * hs[l - 1] * p[r - l + 1] % Mod + Mod) % Mod;
}

int Hasht(int l, int r) {
	return (ht[r] - 1ll * ht[l - 1] * p[r - l + 1] % Mod + Mod) % Mod;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i < M; ++i) {
		p[i] = 1ll * p[i - 1] * B % Mod;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s >> t;
		int hs = 0, ht = 0, len = s.size();
		for (int j = 0; j < len; ++j) {
			hs = (1ll * hs * B + s[j]) % Mod;
			ht = (1ll * ht * B + t[j]) % Mod;
		}
		mp[pii(hs, ht)]++;
	}
	while (q--) {
		cin >> s >> t;
		int len = s.size(), ans = 0;
		s = ' ' + s, t = ' ' + t;
		for (int i = 1; i <= len; ++i) {
			hs[i] = (1ll * hs[i - 1] * B + s[i]) % Mod;
			ht[i] = (1ll * ht[i - 1] * B + t[i]) % Mod;
		}
		for (int i = 1; i <= len; ++i) {
			for (int j = len; j >= i; --j) {
				int ss = Hashs(i, j), tt = Hasht(i, j);
				if (mp.count(pii(ss, tt))) {
					ans += mp[pii(ss, tt)];
				}
				if (s[j] != t[j]) {
					break;
				}
			}
			if (s[i] != t[i]) {
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}