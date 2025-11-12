#include <bits/stdc++.h>
using namespace std;
using LL = long long;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
namespace FastIO {
	char gc() {
		static char buf[1 << 20], *p1, *p2;
		if (p1 == p2) p1 = buf, p2 = buf + fread(buf, 1, 1 << 20, stdin);
		return p1 == p2 ? EOF : *(p1++);
	}
	template <typename T> void read(T &x) {
		char ch; bool op = 0; x = 0;
		do ch = gc(), op |= ch == '-'; while (ch < '0' || ch > '9');
		do x = x * 10 + (ch & 15), ch = gc(); while (ch >= '0' && ch <= '9');
		if (op) x = -x;
	}
	void read(string &s) {
		char ch; s = "";
		do ch = gc(); while (ch < 'a' || ch > 'z');
		do s += ch, ch = gc(); while (ch >= 'a' && ch <= 'z');
	} 
	template <typename T, typename ...U> void read(T &x, U &...y) { read(x), read(y...); }
	template <typename T> void write(T x, char ed = '\n') {
		static int stk[100]; int tp = 0;
		if (x < 0) putchar('-'), x = -x;
		do stk[++tp] = x % 10, x /= 10; while (x);
		for (; tp; --tp) putchar(stk[tp] | 48);
		putchar(ed);
	}
	template <typename T, typename ...U> void write(T x, U ...y) { write(x, ' '), write(y...); }
}
using namespace FastIO;

bool Mst;

const LL B = 871;
const LL P = 1e12+7;
LL hsh(const string& s) {
	LL res = 0;
	for (char ch : s) res = (res * B + ch) % P;
	return res;
}
const int MAXN = 2e5+5;
const int SIZ = 5e6+5;
map<pair<LL, LL>, int> id;
int n, q; 
int px[MAXN], py[MAXN];
int rt[2][MAXN], son[SIZ][26], m, tot;
int dfn[SIZ], siz[SIZ], cnt;

pair<LL, LL> strdiff(string s1, string s2, string &L, string &R) {
	string B, C;
	int len = s1.size(), p = 0, q = 0;
	for (p = 0; p < len && s1[p] == s2[p]; ++p);
	for (int i = 0; i < len; ++i) if (s1[i] != s2[i]) q = i;
	++q;
	L = s1.substr(0, p), B = s1.substr(p, q - p), C = s2.substr(p, q - p), R = s1.substr(q, len - q);
	reverse(L.begin(), L.end());
	return make_pair(hsh(B), hsh(C));
}

int tins(int &x, int p, string &str) {
	if (!x) x = ++tot;
	if (p >= (int)str.size()) return x;
	return tins(son[x][str[p] - 'a'], p + 1, str);
}
int tqry(int x, int p, string &str) {
	if (p >= (int)str.size()) return x;
	int y = son[x][str[p] - 'a'];
	return y ? tqry(y, p + 1, str) : x;
}

void dfs(int x) {
	dfn[x] = ++cnt, siz[x] = 1;
	for (int i = 0; i < 26; ++i) {
		int y = son[x][i];
		if (!y) continue;
		dfs(y); siz[x] += siz[y];
	}
}

struct Node {
	int x, y, v;
	Node(int a, int b, int w) { x = a, y = b, v = w; }
};

struct BIT {
	vector<int> f;
	int n;
	BIT(int len) { n = len; f.assign(n, 0); }
	void update(int p, int v) { for (; p <= n; p += p & -p) f[p] += v; }
	int query(int p) { int s = 0; for (; p; p -= p & -p) s += f[p]; return s; }
}; 

int ans[MAXN];


void solve(vector<Node> &upd, vector<Node> &qry) {
	sort(upd.begin(), upd.end(), [](Node x, Node y) { return x.x < y.x; });
	sort(qry.begin(), qry.end(), [](Node x, Node y) { return x.x < y.x; });
	vector<int> dsc;
//	for (auto u : upd) write(u.x, u.y, u.v); puts("");
//	for (auto u : qry) write(u.x, u.y, u.v); puts("");
	for (auto &u : upd) dsc.push_back(u.y);
	for (auto &u : qry) dsc.push_back(u.y);
	sort(dsc.begin(), dsc.end());
	dsc.erase(unique(dsc.begin(), dsc.end()), dsc.end()); 
	for (auto &u : upd) u.y = lower_bound(dsc.begin(), dsc.end(), u.y) - dsc.begin() + 1;
	for (auto &u : qry) u.y = lower_bound(dsc.begin(), dsc.end(), u.y) - dsc.begin() + 1;
	vector<Node>::iterator it1 = upd.begin(), it2 = qry.begin();
	BIT B(dsc.size());
	for (; it2 != qry.end(); ++it2) {
		for (; it1 != upd.end() && it1->x <= it2->x; ++it1) B.update(it1->y, it1->v);
		ans[it2->v] += B.query(it2->y);
	}
}

bool Med;

int main() {
	assert(freopen("replace.in", "r", stdin));
	assert(freopen("replace.out", "w", stdout));
	fprintf(stderr, "%f\n", (&Mst - &Med) / 1048576.0);	
	read(n, q);
	for (int i = 1; i <= n; ++i) {
		string s1, s2, L, R; read(s1, s2);
		if (s1 == s2) continue;
		pair<LL, LL> pr = strdiff(s1, s2, L, R);
		if (id.find(pr) == id.end()) id[pr] = ++m;
		int u = id[pr];
		px[i] = tins(rt[0][u], 0, L), py[i] = tins(rt[1][u], 0, R);
	}
	int ttt = 0;
	for (int i = 1; i <= tot; ++i) if (!dfn[i]) dfs(i), ++ttt;
	vector<Node> upd, qry; 
	for (int i = 1; i <= n; ++i) {
		int x = px[i], y = py[i];
		upd.emplace_back(dfn[x], dfn[y], 1);
		upd.emplace_back(dfn[x], dfn[y] + siz[y], -1);
		upd.emplace_back(dfn[x] + siz[x], dfn[y], -1);
		upd.emplace_back(dfn[x] + siz[x], dfn[y] + siz[y], 1);
//		write(x, y, dfn[x], dfn[x] + siz[x], dfn[y], dfn[y] + siz[y]);
	}
	for (int i = 1; i <= q; ++i) {
		string s1, s2, L, R; read(s1, s2);
		if (s1.size() != s2.size()) continue;
		pair<LL, LL> pr = strdiff(s1, s2, L, R);
		if (id.find(pr) == id.end()) continue;
		int u = id[pr];
		int x = tqry(rt[0][u], 0, L), y = tqry(rt[1][u], 0, R);
		if (!x || !y) continue;
		qry.emplace_back(dfn[x], dfn[y], i);
//		write(x, y, dfn[x], dfn[y]);
	}
	solve(upd, qry);
	for (int i = 1; i <= q; ++i) write(ans[i]);
	return 0;
}
