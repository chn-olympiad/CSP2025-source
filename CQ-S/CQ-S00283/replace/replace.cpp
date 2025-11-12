#include <bits/stdc++.h>
using namespace std;
#define int long long

const int p = 10000000000000061ll, base = 103;
int bases[5000006], n, q;

string s[200005], t[200005];
int hsha[200005], hshb[200005], hss[200005], hts[200005];

inline void rem(string &na, string &nb) {
	reverse(na.begin(), na.end());
	reverse(nb.begin(), nb.end());
	while (na.back() == nb.back()) na.pop_back(), nb.pop_back();
	reverse(na.begin(), na.end());
	reverse(nb.begin(), nb.end());
	while (na.back() == nb.back()) na.pop_back(), nb.pop_back();
}

inline int get_hsh(string a, int *hsht = 0) {
	int hsh = 0;
	for (int i = 0; i < a.size(); ++i) {
		hsh = hsh * base + a[i] - 'a' + 1;
		hsh %= p;
		if (hsht) hsht[i] = hsh % p;
	}
	return hsh % p;
}

inline int get_qj(int l, int r, int *hsht) {
	if (l > r) return 0;
	return ((hsht[r] - (__int128)(l ? hsht[l - 1] : 0) * bases[r - l + 1]) % p + p) % p;
}

namespace CR200J {
	void main() {
	}
}

namespace BF5033 {
	map<pair<int, int>, vector<int>> mt;
	void main() {
		int tmp = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] != t[i]) {
				string ns = s[i], nt = t[i];
				rem(ns, nt);
				hss[i] = get_hsh(s[i]);
				hts[i] = get_hsh(t[i]);
				mt[{get_hsh(ns), get_hsh(nt)}].push_back(i);
			}
		}
		for (int i = 1; i <= q; ++i) {
			string a, b;
			cin >> a >> b;
			get_hsh(a, hsha);
			int tmp = get_hsh(b);
			int ans = 0;
			string na = a, nb = b;
			rem(na, nb);
			pair<int, int> tmp2 = {get_hsh(na), get_hsh(nb)};
			for (auto j : mt[tmp2]) { // 判断 j 是否可行
				for (int pos = 0; pos + (int)s[j].size()-1 < a.size(); ++pos) {
					if (get_qj(pos, pos + s[j].size() - 1, hsha) == hss[j]) {
						int ha = 
							((__int128)get_qj(0, pos - 1, hsha) * bases[a.size() - pos]+ (__int128)hts[j] * bases[a.size() - s[j].size() - pos] + get_qj(pos + s[j].size(), a.size() - 1, hsha)) % p;
						if (ha == tmp) {
							++ans;
							break;
						}
					}
				}
			}
			cout << ans << "\n";
		}
	}
}

signed main() {
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	bases[0] = 1;
	for (int i = 1; i <= 5000000; ++i) {
		bases[i] = bases[i - 1] * base % p;
	}
	cin >> n >> q;
	int sm1 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> t[i];
		sm1 += s[i].size() + t[i].size();
	}
	if (0 && ((sm1 <= 2000 && n <= 1000) || (q == 1))) CR200J::main();
	else BF5033::main();

	return 0;
}
