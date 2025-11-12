#include <bits/stdc++.h>
namespace GDS03068 {
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
const int maxn = 2e5 + 50, maxlentype = 3e3, maxlen = 5e6 + 60;
const ll base = 32, mod1 = 998244353, mod2 = 1e9 + 7;
ll po1[maxlen], po2[maxlen];
int n, q;
string s1, s2;
vector<int> len;
multiset<pii> ha[maxlentype];
int sz[maxn];
ll ha1[maxlen], ha2[maxlen];
void init() {
	po1[0] = po2[0] = 1;
	for (int i = 1; i < maxlen; ++i)
		po1[i] = (po1[i - 1] << 5) % mod1,
		po2[i] = (po2[i - 1] << 5) % mod2;
}
void Mian() {
	init();
	cin >> n >> q;
	len.reserve(n);
	for (register int i = 1; i <= n; ++i) {
		cin >> s1 >> s2;
		sz[i] = s1.size();
		for (register char c : s1) {
			ha1[i] = (ha1[i] << 5) % mod1 + (c ^ 96);
			if (ha1[i] >= mod1) ha1[i] -= mod1;
			ha2[i] = (ha2[i] << 5) % mod2 + (c ^ 96);
			if (ha2[i] >= mod2) ha2[i] -= mod2;
		}
		for (register char c : s2) {
			ha1[i] = (ha1[i] << 5) % mod1 + (c ^ 96);
			if (ha1[i] >= mod1) ha1[i] -= mod1;
			ha2[i] = (ha2[i] << 5) % mod2 + (c ^ 96);
			if (ha2[i] >= mod2) ha2[i] -= mod2;
		}
		len.emplace_back(sz[i]);
	}
	sort(len.begin(), len.end());
	len.erase(unique(len.begin(), len.end()), len.end());
	for (register int i = 1; i <= n; ++i) {
		int type = lower_bound(len.begin(), len.end(), sz[i]) - len.begin();
		ha[type].emplace(ha1[i], ha2[i]);
	}
	register int sz, l, r, ls;
	register ll ans, v1, v2, t1, t2;
	while (q--) {
		cin >> s1 >> s2;
		if (s1.size() ^ s2.size()) {
			cout << "0\n";
			continue;
		}
		sz = s1.size();
		ha1[0] = ha2[0] = 0;
		s1 = ' ' + s1 + s2;
		for (register int i = 1, ir = s1.size(); i < ir; ++i) {
			ha1[i] = (ha1[i - 1] << 5) % mod1 + (s1[i] ^ 96);
			if (ha1[i] >= mod1) ha1[i] -= mod1;
			ha2[i] = (ha2[i - 1] << 5) % mod2 + (s1[i] ^ 96);
			if (ha2[i] >= mod2) ha2[i] -= mod2;
		}
		l = r = 0;
		for (register int i = 1; i <= sz; ++i) {
			if (s1[i] ^ s1[i + sz]) {
				if (!l) l = i;
				r = i;
			}
		}
		ans = 0;
		if (l <= sz - r + 1) {
			ls = lower_bound(len.begin(), len.end(), r) - len.begin();
			for (register int i = 1; i <= l; ++i) {
				if (ls && len[ls - 1] >= r - i + 1) --ls;
				for (register int si = ls, s, sir = len.size(); si < sir; ++si) {
					s = len[si];
					if (i + s - 1 > sz) break;
					v1 = ha1[i + s - 1] - ha1[i - 1] * po1[s] % mod1,
					v2 = ha2[i + s - 1] - ha2[i - 1] * po2[s] % mod2;
					if (v1 < 0) v1 += mod1;
					if (v2 < 0) v2 += mod2;
					v1 = v1 * po1[s] % mod1,
					v2 = v2 * po2[s] % mod2;
					t1 = ha1[sz + i + s - 1] - ha1[sz + i - 1] * po1[s] % mod1,
					t2 = ha2[sz + i + s - 1] - ha2[sz + i - 1] * po2[s] % mod2;
					if (t1 < 0) t1 += mod1;
					if (t2 < 0) t2 += mod2;
					v1 += t1,
					v2 += t2;
					if (v1 >= mod1) v1 -= mod1;
					if (v2 >= mod2) v2 -= mod2;
					ans += ha[si].count({v1, v2});
				}
			}
		} else {
			ls = lower_bound(len.begin(), len.end(), sz - l + 1) - len.begin();
			for (register int i = sz; i >= r; --i) {
				if (ls && len[ls - 1] >= i - l + 1) --ls;
				for (register int si = ls, s, sir = len.size(); si < sir; ++si) {
					s = len[si];
					if (i - s + 1 < 1) break;
					v1 = ha1[i] - ha1[i - s] * po1[s] % mod1,
					v2 = ha2[i] - ha2[i - s] * po2[s] % mod2;
					if (v1 < 0) v1 += mod1;
					if (v2 < 0) v2 += mod2;
					v1 = v1 * po1[s] % mod1,
					v2 = v2 * po2[s] % mod2;
					t1 = ha1[sz + i] - ha1[sz + i - s] * po1[s] % mod1,
					t2 = ha2[sz + i] - ha2[sz + i - s] * po2[s] % mod2;
					if (t1 < 0) t1 += mod1;
					if (t2 < 0) t2 += mod2;
					v1 += t1,
					v2 += t2;
					if (v1 >= mod1) v1 -= mod1;
					if (v2 >= mod2) v2 -= mod2;
					ans += ha[si].count({v1, v2});
				}
			}
		}
		cout << ans << '\n';
	}
}
}
int main() {
#ifndef LOCALruanhuaxuan
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T = 1;
//	std::cin >> T;
	while (T--) GDS03068::Mian();
	return 0;
}

