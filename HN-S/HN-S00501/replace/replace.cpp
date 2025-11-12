#include <bits/stdc++.h>

using namespace std;

const int MOD1 = 1000000007, MOD2 = 1000000009;

int n, q;
int p1[5000005], p2[5000005];
string s1[200005], s2[200005];
vector<pair<int, int>> hs1[200005], hs2[200005];

inline void h(const string& s, vector<pair<int, int>>& v) {
	const int m = s.length();
	v.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		v[i].first = (v[i - 1].first * 27LL + (s[i - 1] - 'a' + 1)) % MOD1,
		v[i].second = (v[i - 1].second * 27LL + (s[i - 1] - 'a' + 1)) % MOD2;
	}
}

inline pair<int, int> h(const vector<pair<int, int>>& v, int l, int r) {
	return {((v[r].first - 1LL * v[l].first * p1[r - l]) % MOD1 + MOD1) % MOD1,
		    ((v[r].second - 1LL * v[l].second * p2[r - l]) % MOD2 + MOD2) % MOD2};
}

inline pair<int, int> concat(int l1, const pair<int, int>& h1,
					  int l2, const pair<int, int>& h2,
					  int l3, const pair<int, int>& h3) {
	pair<int, int> res(0, 0);
	res.first = (1LL * res.first * p1[l1] + h1.first) % MOD1;
	res.second = (1LL * res.second * p2[l1] + h1.second) % MOD2;
	res.first = (1LL * res.first * p1[l2] + h2.first) % MOD1;
	res.second = (1LL * res.second * p2[l2] + h2.second) % MOD2;
	res.first = (1LL * res.first * p1[l3] + h3.first) % MOD1;
	res.second = (1LL * res.second * p2[l3] + h3.second) % MOD2;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= 5000000; i++)
		p1[i] = 27LL * p1[i - 1] % MOD1, p2[i] = 27LL * p2[i - 1] % MOD2;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		h(s1[i], hs1[i]), h(s2[i], hs2[i]);
	}
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.length() != t2.length()) {
			cout << 0 << '\n';
			continue;
		}
		vector<pair<int, int>> ht1, ht2;
		h(t1, ht1), h(t2, ht2);
		int res = 0;
		for (int j = 1; j <= n; j++)
			for (size_t k = s1[j].length(); k <= t1.length(); k++)
				if (h(ht1, k - s1[j].length(), k) == hs1[j].back() &&
					concat(k - s1[j].length(), h(ht1, 0, k - s1[j].length()),
						   s2[j].length(), hs2[j].back(),
						   t1.length() - k, h(ht1, k, t1.length())) == ht2.back())
					res++;
		cout << res << '\n';
	}
	return 0;
}
