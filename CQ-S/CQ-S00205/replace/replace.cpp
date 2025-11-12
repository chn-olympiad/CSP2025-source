#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pii pair< int, int >
#define inf 0x3f3f3f3f3f3f3f3f
#define F(v, x) for (auto v : (x))
#define ALL(x) (x).begin(), (x).end()
#define L(i, a, b) for (int i = (a); i <= (b); i++)
#define R(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;
bool bm;

inline void cmin(int &x, int c) { x = min(x, c); }
inline void cmax(int &x, int c) { x = max(x, c); }

int tes = 1, cas;

//namespace zrH {
//	const int N = 4e5 + 5, M = 5e6 + 6;	
//	int n, q, son[4][N][30], tot;
//	unordered_set< int > s[4][N];
//	void mer(unordered_set< int > &x, unordered_set< int > y) {
//		if (x.size() < y.size()) swap(x, y);
//		F(z, y) x.insert(z); 
//	}
//	void mer2(unordered_set< int > &x, unordered_set< int > y) {
//		if (x.size() < y.size()) swap(x, y);
//		unordered_set< int > st;
//		F(z, y) if (x.count(z)) st.insert(z);
//		x = st;
//	}
//	void ins(string S, int i, int id) {
//		int p = 0;
//		F(c, S) {
//			if (!son[id][p][c - 'a']) son[id][p][c - 'a'] = ++tot;
//			p = son[id][p][c - 'a'];
//		} s[id][p].insert(i);
//	} unordered_set< int > get(string S, int id, int siz) {
//		int p = 0;
//		unordered_set< int > ans = {};
//		int cnt = 0;
//		F(c, S) {
//			cnt++;
//			if (!son[id][p][c - 'a']) return ans;
//			p = son[id][p][c - 'a'];
//			if (cnt >= siz) mer(ans, s[id][p]);
//		} return ans;
//	}
//	void init() {}
//	void clear() {}
//	void solve() {
//		cin >> n >> q;
//		L(i, 1, n) {
//			string s, t; int k;
//			cin >> s >> t, k = s.size(), s = " " + s, t = " " + t;
//			if (s == t) continue;
//			int mn = k, mx = 0;
//			L(j, 1, k) if (s[j] != t[j]) cmin(mn, j), mx = j;
//			string b1 = "", b2 = "";
//			L(j, mn, k) b1 += s[j];
//			R(j, mx, 1) b2 += s[j];
//			ins(b1, i, 0), ins(b2, i, 1);
//			b1 = "", b2 = "";
//			L(j, mn, k) b1 += t[j];
//			R(j, mx, 1) b2 += t[j];
//			ins(b1, i, 2), ins(b2, i, 3);
//		} 
//		L(i, 1, q) {
//			string s, t; int k;
//			cin >> s >> t, k = s.size(), s = " " + s, t = " " + t;
//			if (s.size() != t.size()) {
//				cout << "0\n";
//				continue;
//			}
//			int mn = k, mx = 0;
//			L(j, 1, k) if (s[j] != t[j]) cmin(mn, j), mx = j;
//			string b1 = "", b2 = "";
//			L(j, mn, k) b1 += s[j];
//			R(j, mx, 1) b2 += s[j];
//			unordered_set< int > st = get(b1, 0, mx - mn + 1);
//			mer2(st, get(b2, 1, mx - mn + 1));
//			b1 = "", b2 = "";
//			L(j, mn, k) b1 += t[j];
//			R(j, mx, 1) b2 += t[j];
//			mer2(st, get(b1, 2, mx - mn + 1));
//			mer2(st, get(b2, 3, mx - mn + 1));
//			cout << st.size() << "\n";
//		}
//	}
//}

namespace zrh {
	const int N = 2e5 + 5, M = 5e6 + 6;
	int n, q;
	map< pair< string, string>, int > cnt;
//	void mer(unordered_set< int > &x, unordered_set< int > y) {
//		if (x.size() < y.size()) swap(x, y);
//		F(z, y) x.insert(z); 
//	}
//	void mer2(unordered_set< int > &x, unordered_set< int > y) {
//		if (x.size() < y.size()) swap(x, y);
//		unordered_set< int > st;
//		F(z, y) if (x.count(z)) st.insert(z);
//		x = st;
//	}
	void init() {}
	void clear() {}
	void solve() {
		cin >> n >> q;
		L(i, 1, n) {
			string s, t; int k;
			cin >> s >> t, k = s.size();
			cnt[{s, t}]++;
		}
		L(i, 1, q) {
			string s, t; int k;
			cin >> s >> t, k = s.size(), s = " " + s, t = " " + t;
			if (s.size() != t.size()) {
				cout << "0\n";
				continue;
			}
			int mn = k, mx = 0;
			L(j, 1, k) if (s[j] != t[j]) cmin(mn, j), mx = j;
			int ans = 0;
			L(j, 1, mn) {
				string b = "", c = "";
				L(l, j, mx - 1) b += s[l], c += t[l];
				L(l, mx, k) {
					b += s[l], c += t[l];
					if (cnt[{b, c}]) ans++;
				}
			}
			cout << ans << "\n";
		}
	}
}

bool em;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> tes;
	zrh::init(); while (++cas <= tes) zrh::clear(), zrh::solve();
//	cerr << "time  : " << (double)clock() / CLOCKS_PER_SEC * 1000 << "ms\n";
//	cerr << "memory: " << fabs(&bm - &em) / 1024 / 1024 << "mb\n";
	return 0;
}
// I love zrh forever.

