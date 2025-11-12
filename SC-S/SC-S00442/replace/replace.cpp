#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define per(i,a,b) for (int i = (a); i >= (b); -- i)
#define ll long long
#define INF 0x3f3f3f3f
#define llINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

const int mod1 = 1e9 + 7, mod2 = 998244353, base = 20090629;

struct hint {
	int x, y;
	
	hint(int a = 0) { x = a % mod1, y = a % mod2; }
	
	hint operator + (hint b) {
		hint c;
//		assert(x < mod1 && b.x < mod1);
		c.x = x + b.x, c.y = y + b.y;
		if (c.x >= mod1) c.x -= mod1;
		if (c.y >= mod2) c.y -= mod2;
		return c;
	}
	void operator += (hint b) { *this = *this + b; }
	
	hint operator - (hint b) {
		hint c;
//		assert(x < mod1 && b.x < mod1);
		c.x = x - b.x, c.y = y - b.y;
		if (c.x < 0) c.x += mod1;
		if (c.y < 0) c.y += mod2;
		return c;
	}
	void operator -= (hint b) { *this = *this - b; }
	
	hint operator * (hint b) {
		hint c;
//		assert(x < mod1 && b.x < mod1);
		c.x = 1LL * x * b.x % mod1;
		c.y = 1LL * y * b.y % mod2;
		return c;
	}
	void operator *= (hint b) { *this = *this * b; }
	
	inline bool operator < (hint b) const { return x == b.x ? y < b.y : x < b.x; }
	inline bool operator == (hint b) const { return x == b.x && y == b.y; }
	inline bool operator != (hint b) const { return x != b.x || y != b.y; }
};

struct Trie {
	int son[5000010][26], cnt, rt, f[5000010], dfn[5000010], sz[5000010], cur;
	
	void insert(string s) {
		if (!rt) rt = ++ cnt;
		int u = rt;
		++ f[u];
		for (auto c : s) {
			if (!son[u][c - 'a']) son[u][c - 'a'] = ++ cnt;
			++ f[u = son[u][c - 'a']];
		}
	}
	
	void clear() {
		while (cnt) {
			rep (j,0,25) son[cnt][j] = 0;
			f[cnt] = dfn[cnt] = sz[cnt] = 0;
			-- cnt;
		}
//		dfn[0] = 0;
		rt = cur = 0;
	}
	
	void DFS(int u) {
		if (!u) return;
		sz[u] = 1;
		dfn[u] = ++ cur;
		rep (j,0,25) if (son[u][j]) DFS(son[u][j]), sz[u] += sz[son[u][j]];
	}
	
	int query(string s) {
		int u = rt;
		for (char c : s) u = son[u][c - 'a'];
		return u;
	}
}trie[2];

int n, q, cnt, ans[200010], tot;
hint ha[2][5000010], pw[5000010];
char s[5000010], t[5000010];
map<pair<hint, hint>, vector< tuple<string, string, int> > > ma;
vector< pair<int, int> > vec[5000010], qs[5000010];

inline hint getHa(int op, int l, int r) { return ha[op][r] - ha[op][l - 1] * pw[r - l + 1]; }

struct fenwick {
	int t[5000010];
	
	inline int lowbit(int u) { return u & -u; }
	
	inline void add(int u, int k) {
		if (u > 0) for (int i = u; i <= cnt; i += lowbit(i)) t[i] += k;
	}
	
	inline int query(int u) {
		int res = 0;
		for (int i = u; i >= 1; i -= lowbit(i)) res += t[i];
		return res;
	}
}bit;

void DFS(int u) {
	for (auto x : vec[u]) {
		bit.add(x.first, 1);
		bit.add(x.second + 1, -1);
	}
	for (auto x : qs[u]) ans[x.second] = bit.query(x.first);
	rep (j,0,25) if (trie[1].son[u][j]) DFS(trie[1].son[u][j]);
	for (auto x : vec[u]) {
		bit.add(x.first, -1);
		bit.add(x.second + 1, 1);
	}
}

void solve(vector< tuple<string, string, int> > vec) {
	bool flag = false, qwq = false;
//	for (auto x : vec) if (get<2>(x) == 106) flag = true;else if (get<2>(x) == 101) qwq = true;
	if (flag) cerr << "solving\n";
	if (flag) cerr << qwq << "ATZ.\n";
	trie[0].clear(), trie[1].clear();
	for (auto x : vec) {
		string s1 = get<0>(x), s2 = get<1>(x);
		int id = get<2>(x);
		if (flag && id == 106) cerr << s1 << ' ' << s2 << ' ' << id << endl;
		if (id == -1) continue;
		trie[0].insert(s1), trie[1].insert(s2);
	}
	trie[0].DFS(trie[0].rt);
	cnt = trie[0].cur, tot = trie[1].cnt;
	for (auto x : vec) {
		string s1 = get<0>(x), s2 = get<1>(x);
		int id = get<2>(x);
		int u = trie[1].query(s2), v = trie[0].query(s1);
		if (id == -1) ::vec[u].emplace_back(trie[0].dfn[v], trie[0].dfn[v] + trie[0].sz[v] - 1);
		else qs[u].emplace_back(trie[0].dfn[v], id);
		if (flag) cerr << u << ' ' << v << ' ' << trie[0].dfn[v] << ' ' << trie[0].dfn[v] + trie[0].sz[v] - 1 << ' ' << id << endl;
	}
	if (flag) cerr << "??? " << trie[0].sz[1] << endl;
	DFS(trie[1].rt);
	rep (i,0,tot) vector< pair<int, int> >().swap(qs[i]), vector< pair<int, int> >().swap(::vec[i]);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> q;
	pw[0] = 1;
	rep (i,1,5000000) pw[i] = pw[i - 1] * base;
	rep (i,1,n) {
		cin >> s >> t;
		int m = strlen(s);
		rep (j,1,m) ha[0][j] = ha[0][j - 1] * base + s[j - 1], ha[1][j] = ha[1][j - 1] * base + t[j - 1];
		if (ha[0][m] == ha[1][m]) /*Tybbs!*/;
		else {
			int l, r;
			for (l = 1; l <= m; ++ l) if (getHa(0, 1, l) != getHa(1, 1, l)) break;
			for (r = m; r >= 1; -- r) if (getHa(0, r, m) != getHa(1, r, m)) break;
//			if (getHa(0, l, r).x == 715550843 && getHa(1, l, r).x == 504239511) {
//				cerr << i << ' ' << l << ' ' << r << endl;
//				rep (j,l, r) cerr << s[j - 1];
//				cerr << endl;
//				rep (j,l, r) cerr << t[j - 1];
//				cerr << endl;
//			}
//			cerr << i << ' ' << l << ' ' << r << ' ' << getHa(0, l, r).x << ' ' << getHa(1, l, r).x << endl;
			string s1 = "", s2 = "";
			per (j,l - 1,1) s1 += s[j - 1];
			rep (j,r + 1,m) s2 += s[j - 1];
			ma[make_pair(getHa(0, l, r), getHa(1, l, r))].emplace_back(s1, s2, -1);
		}
	}
	rep (i,1,q) {
		cin >> s >> t;
		int m = strlen(s);
		if (strlen(t) != m) continue;
		rep (j,1,m) ha[0][j] = ha[0][j - 1] * base + s[j - 1], ha[1][j] = ha[1][j - 1] * base + t[j - 1];
		int l, r;
		for (l = 1; l <= m; ++ l) if (getHa(0, 1, l) != getHa(1, 1, l)) break;
		for (r = m; r >= 1; -- r) if (getHa(0, r, m) != getHa(1, r, m)) break;
//		if (i == 101) {
//			cerr << l << ' ' << r << ' ' << getHa(0, l, r).x << ' ' << getHa(1, l, r).x << endl;
//			rep (j,1,r) cerr << s[j - 1];
//			cerr << endl;
//			rep (j,1,r)cerr << t[j - 1];
//			cerr << endl;
//		}
		string s1 = "", s2 = "";
		per (j,l - 1,1) s1 += s[j - 1];
		rep (j,r + 1,m) s2 += s[j - 1];
		ma[make_pair(getHa(0, l, r), getHa(1, l, r))].emplace_back(s1, s2, i);
	}
	for (auto x : ma) solve(x.second);
	rep (i,1,q) cout << ans[i] << '\n';
	return 0;
}

//有点蠢。
//纪律性双哈应该不会四吧？