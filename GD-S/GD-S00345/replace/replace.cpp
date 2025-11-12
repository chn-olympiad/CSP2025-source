#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

#define mk make_pair
#define pii pair<int, int>
#define fir first
#define sec second

const int N = 2e5 + 5, M = 5e6 + 5, V = 5e6, p1 = 998244353, p2 = 1e9 + 7, base = 373;
int n, q, b[N], len[N], pw1[M], pw2[M];
bool sub1 = 1;
pii val[N], v[M];
map<pii, vector<int>> mp;

inline void get_hash(string s) {
	v[0] = mk(s[0], s[0]);
	for (int i = 1; i < (int)s.size(); ++i) {
		v[i].fir = ((ll)v[i - 1].fir * base + s[i]) % p1;
		v[i].sec = ((ll)v[i - 1].sec * base + s[i]) % p2;
	}
}

inline int sub_mod(int x, int mod) {
	return x < 0 ? x + mod : x;
}

inline pii get(int l, int r) {
	if (l == 0) return v[r];
//	cout << l << ' ' << r << '\n';
	return mk(sub_mod((v[r].fir - (ll)v[l - 1].fir * pw1[r - l + 1]) % p1, p1),
		sub_mod((v[r].sec - (ll)v[l - 1].sec * pw2[r - l + 1]) % p2, p2));
}

inline pair<pii, int> get_hash(string s1, string s2) {
	pii res = mk(0, 0);
	int b = -1, e = -1;
	for (int i = 0; i < (int)s1.size(); ++i)
		if (s1[i] != s2[i]) {
			if (b == -1) b = i;
			e = i;
		}
//	cerr << b << ' ' << e << '\n';
	for (int i = 0; i < (int)s1.size(); ++i)
		if (i >= b && i <= e) {
			res.fir = (((ll)res.fir * base + s1[i]) * base + s2[i]) % p1;
			res.sec = (((ll)res.sec * base + s1[i]) * base + s2[i]) % p2;
		}
	return mk(res, b);
}

bool check(string s) {
	int cnt = 0;
	for (char ch : s)
		if (ch <= 'b') {
			if (ch == 'b') ++cnt;
		} else return 0;
	return cnt <= 1;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= V; ++i) {
		pw1[i] = (ll)pw1[i - 1] * base % p1;
		pw2[i] = (ll)pw2[i - 1] * base % p2;
	}
	for (int i = 1; i <= n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		sub1 &= check(s1) && check(s2);
		len[i] = s1.size();
		pair<pii, int> r = get_hash(s1, s2);
		b[i] = r.sec;
		mp[r.fir].push_back(i);
		get_hash(s1);
		val[i] = v[s1.size() - 1];
	}
	for (int i = 1; i <= q; ++i) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		pair<pii, int> r = get_hash(t1, t2);
		get_hash(t1);
		int res = 0;
		vector<int> v = mp[r.fir];
		for (int x : v) {
			int be = r.sec - b[x];
			if (be >= 0 && be + len[x] - 1 < (int)t1.size()
				&& get(be, be + len[x] - 1) == val[x]) {
					++res;
				}
		}
		cout << res << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
