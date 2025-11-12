a#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 5000005, M = 200005, mod = 998244353;
int tt, tot, rt[M], dfn[N], ed[N], st[N], ch[N][26];
inline int ins(int &rt, const string &s) {
	if (!rt)
		rt = ++tot;
	int p = rt;
	for (char c : s) {
		int o = c - 'a';
		if (!ch[p][o])
			ch[p][o] = ++tot, st[p] |= (1 << o);
		p = ch[p][o];
	}
	return p;
}
inline int qry0(int p, const string &s) {
	for (int i = 0; i < s.size() && p; i++) {
		int o = s[i] - 'a';
		p = ch[p][o];
	}
	return p;
}
inline int qry1(int p, const string &s) {
	assert(p);
	for (int i = 0; i < s.size(); i++) {
		int o = s[i] - 'a';
		if (!ch[p][o])
			break;
		p = ch[p][o];
	}
	return p;
}
void dfs(int p) {
	dfn[p] = ++tt;
	int now = st[p];
	while (now) {
		int o = __builtin_ctz(now);
		dfs(ch[p][o]);
		now &= (now - 1);
	}
	ed[p] = tt;
}
map<pair<int, int>, int> mp;
vector<pair<int, int> > au[M];
vector<int> aq[M];
int a[M], b[M], res[M];
int c[N];
inline void upd(int x, int v) {
	for (; x <= tt; x += x & -x)
		c[x] += v;
}
inline int qry(int x) {
	int res = 0;
	for (; x; x ^= x & -x)
		res += c[x];
	return res;
}
struct node {
	int l, r, v;
};
vector<node> U[N];
vector<int> Q[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q, m = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s, t;
		cin >> s >> t;
		if (s == t)
			continue;
		int p0 = 0, p1 = s.size() - 1;
		while (s[p0] == t[p0])
			++p0;
		while (s[p1] == t[p1])
			--p1;
		int x = ins(rt[0], s.substr(p0, p1 - p0 + 1)), y = ins(rt[0], t.substr(p0, p1 - p0 + 1));
		if (!mp[{x, y}])
			mp[{x, y}] = ++m;
		string uu = s.substr(0, p0), vv = s.substr(p1 + 1, s.size() - p1);
		reverse(uu.begin(), uu.end());
		int id = mp[{x, y}], u = ins(rt[id], uu), v = ins(rt[id], vv);
		au[id].emplace_back(u, v);
		// cerr << i << ' ' << p0 << ' ' << p1 << '|' << uu << ',' << vv << '|' << u << ',' << v << '\n';
	}
	for (int i = 1; i <= q; i++) {
		string s, t;
		cin >> s >> t;
		if (s.size() != t.size())
			continue;
		int p0 = 0, p1 = s.size() - 1;
		while (s[p0] == t[p0])
			++p0;
		while (s[p1] == t[p1])
			--p1;
		int x = qry0(rt[0], s.substr(p0, p1 - p0 + 1)), y = qry0(rt[0], t.substr(p0, p1 - p0 + 1));
		int id = mp[{x, y}];
		if (!id)
			continue;
		string uu = s.substr(0, p0), vv = s.substr(p1 + 1, s.size() - p1);
		reverse(uu.begin(), uu.end());
		a[i] = qry1(rt[id], uu), b[i] = qry1(rt[id], vv);
		aq[id].emplace_back(i);
		// cerr << i << ' ' << id << ' ' << p0 << ' ' << p1 << '|' << uu << ',' << vv << '|' << a[i] << ',' << b[i] << '\n';
	}
	for (int i = 1; i <= m; i++) {
		if (!aq[i].size())
			continue;
		tt = 0;
		dfs(rt[i]);
		for (pair<int, int> x : au[i]) {
			int p0 = x.first, p1 = x.second;
			// cerr << p0 << ',' << p1 << ' ' << dfn[p0] << ',' << ed[p0] << ' ' << dfn[p1] << ',' << ed[p1] << '\n';
			U[dfn[p0]].push_back({dfn[p1], ed[p1], 1});
			if (ed[p0] < tt)
				U[ed[p0] + 1].push_back({dfn[p1], ed[p1], -1});
		}
		for (int x : aq[i])
			Q[dfn[a[x]]].emplace_back(x);
		for (int j = 1; j <= tt; j++) {
			for (node x : U[j])
				upd(x.l, x.v), upd(x.r + 1, -x.v);
			for (int x : Q[j]) {
				// cerr << x << ' ' << a[x] << ' ' << b[x] << ' ' << j << ' ' << dfn[b[x]] << '\n';
				res[x] = qry(dfn[b[x]]);
			}
			U[j].clear();
			Q[j].clear();
		}
		memset(c + 1, 0, sizeof(int) * tt);
	}
	for (int i = 1; i <= q; i++) {
		cout << res[i] << '\n';
	}
	return 0;
}
