#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e6 + 40, mod = 998244353, base = 26;

inline int has(const string& s) {
	int ans = 0, siz = s.size();
	for (char c : s)
		((ans *= base) += c - 'a') %= mod;
	return ans;
}

inline int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)
			(ans *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ans;
}

map<int, multiset<pair<int, int>>> ds;

inline void insert(const string& s1, const string& s2) {
	ds[s1.size()].emplace(has(s1), has(s2));
}

inline int query(const string& s1, const string& s2) {
	if (s1.size() != s2.size())
		return 0;
	int fi = -1, la = -1, n = s1.size();
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i]) {
			if (!~fi)
				fi = i;
			la = i;
		}
	}
	if (!la)
		return 0;
	int ans = 0;
	for (map<int, multiset<pair<int, int>>>::iterator it = ds.lower_bound(la - fi + 1); it != ds.end(); it++) {
		int l = max(0ll, la - it->first + 1), r = l + it->first - 1;
		int h1 = has(s1.substr(l, it->first - 1)), h2 = has(s2.substr(l, it->first - 1));
		int tmp = qpow(base, it->first - 1);
		for (; l <= fi; l++, r++) {
			((h1 *= base) += s1[r] - 'a') %= mod;
			((h2 *= base) += s2[r] - 'a') %= mod;
			ans += it->second.count(make_pair(h1, h2));
			(h1 += mod - tmp * (s1[l] - 'a')) %= mod;
			(h2 += mod - tmp * (s2[l] - 'a')) %= mod;
		}
	}
	return ans;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;
		insert(s1, s2);
	}
	while (m--) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << query(s1, s2) << '\n';
	}
}