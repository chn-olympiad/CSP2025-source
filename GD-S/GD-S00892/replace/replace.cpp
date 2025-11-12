#include <bits/stdc++.h> 
//#define ONLINE_JUDGE
#define FILENAME "replace"

typedef long long ll;
const int N = 5e6 + 5;
const ll tim = 1930427, mod = 998244353;
int n, q, tot = 1, root = 1;
ll from[N], dest[N], power[N];
struct Node {
	int ch[30];
	int len;
	bool flag = 0;
	std::unordered_map<ll, int> end;
} tree[N];

void insert(const std::string &s, ll hash) {
	int u = root;
	for (auto ch : s) {
		int c = ch - 'a';
		if (!tree[u].ch[c]) {
			tree[u].ch[c] = ++tot;
			tree[tot].len = tree[u].len + 1;
		}
		u = tree[u].ch[c];	
	}
	++tree[u].end[hash];
	tree[u].flag = 1;
}

inline ll hash(const std::string &s) {
	ll ans = 0;
	for (auto c : s) {
		ans = (ans * tim + c) % mod;
	}
	return ans;
}

inline ll cut(ll *dest, int i, int j) {
	if (i > j) return 0;
	return ((dest[j] - (dest[i - 1] * power[j - i + 1] % mod)) % mod + mod) % mod;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	
	std::cin >> n >> q;
	std::string s1, s2;
	power[0] = 1;
	for (int i = 1; i < N; ++i) {
		power[i] = power[i - 1] * tim % mod;
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> s1 >> s2;
		ll hs2 = hash(s2);
		insert(s1, hs2);
//		std::cout << "HASH " << hs2 << '\n';
	}
	for (int i = 1; i <= q; ++i) {
		std::cin >> s1 >> s2;
		for (int i = 1; i <= s2.size(); ++i) {
			from[i] = (from[i - 1] * tim + s1[i - 1]) % mod;
			dest[i] = (dest[i - 1] * tim + s2[i - 1]) % mod;
		}
		
		int ans = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (i > 0 && s1[i - 1] != s2[i - 1]) break;
			int u = root;
			for (int j = i; j < s1.size() && u; ++j) {
				int c = s1[j] - 'a';
				u = tree[u].ch[c];
				if (tree[u].flag) {
					int len = tree[u].len;
					int l = j - len + 2, r = j + 1;
					if (cut(from, r + 1, s1.size()) != cut(dest, r + 1, s2.size())) continue;
//					std::cerr << l << ", " << r << '\n';
//					std::cerr << "HSH: " << cut(dest, l, r) << '\n';
					ans += tree[u].end[cut(dest, l, r)];
				}
			}
		}
		std::cout << ans << '\n';
	}
	
	return 0;
}

