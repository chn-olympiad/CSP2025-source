#include <bits/stdc++.h>
using namespace std;
#define IC isdigit(c)
#define GC c=getchar()
#define il inline
il void rd(auto &x) { char GC; x = 0; bool f = 0;
	for (; !IC; GC) f |= x == '-';
	for (; IC; GC) x = x * 10 + (c - 48);
	f && (x = -x);
}
il void rd(auto &x, auto &...y) { rd(x); rd(y...);
}
#define U(i,l,r) for (int i(l),END##i(r); i<=END##i; ++i)
#define D(i,l,r) for (int i(l),END##i(r); i>=END##i; --i)
#define ms(x, v) memset(x, v, sizeof(x))
#define vc vector
#define pb push_back
#define eb emplace_back
using ll = unsigned long long;

const ll P = 1004535809, B = 31;
const int L = 5000006, N = 200005;
//const int L = 2500006, N = 200005;
int n, q;

map<tuple<int, ll, ll>, int> id; vc<int> hok[N];
pair<string, string> a[N];

void init() {
	int m = 0;
	U (i, 1, n) {
		static char s[L], t[L];
		scanf("%s%s", s + 1, t + 1);
		int k = strlen(s + 1); assert(strlen(t + 1) == k);
		U (j, 1, k) s[j] -= 'a', t[j] -= 'a';
		
		int l = 0, r = 0;
		U (j, 1, k) if (s[j] != t[j]) {
			l = j; break;
		}
		D (j, k, 1) if (s[j] != t[j]) {
			r = j; break;
		}
		if (!l) continue;
		
		++m;
		
		ll h1 = 0, h2 = 0;
		U (j, l, r) {
			h1 = (h1 * B + s[j] + 1) %P;
			h2 = (h2 * B + t[j] + 1) %P;
		}
		
		a[m] = {string(s + 1, s + l), string(s + r + 1, s + k + 1)};
		
		tuple<int, ll, ll> stat {r - l + 1, h1, h2};
		int &p = id[stat]; if (!p) p = id.size();
		hok[p].pb(m);
	}
}

int m, rt[N];
struct acam {
	int ch[L + N][26], fail[L + N];
	int ptr;
	
	int insert(string &s, int rt) {
		int p = rt;
		for (char c : s) {
			assert(c < 26);
			if (!ch[p][c]) ch[p][c] = ++ptr;
			p = ch[p][c];
		}
		return p;
	}
	int match(int p, string &s) {
		for (char c : s) {
			assert(c < 26);
			p = ch[p][c];
		}
		return p;
	}
	
	vc<int> g[L + N];
	int dfn[L + N], siz[L + N], dfp;
	void dfs(int u) {
		siz[u] = 1; dfn[u] = ++dfp;
		for (int v : g[u]) {
			dfs(v);
			siz[u] += siz[v];
		}
	}
	
	void build(int k) {
		queue<int> q;
		U (i, 1, k) U (c, 0, 25)
			if (ch[i][c]) {
				fail[ch[i][c]] = i;
				q.push(ch[i][c]);
			} else {
				ch[i][c] = i;
			}
		
		while (q.size()) {
			int i = q.front(); q.pop();
			U (c, 0, 25) {
				if (ch[i][c]) {
					fail[ch[i][c]] = ch[fail[i]][c];
					q.push(ch[i][c]);
				} else {
					ch[i][c] = ch[fail[i]][c];
				}
			}
		}
		
		U (i, k + 1, ptr)
			g[fail[i]].pb(i);
		
		U (i, 1, k) dfs(i);
	}
} ap, as;

int ans[N];
int bit[N + L];
struct c2d {
	vc<tuple<int, int, int, int, int>> pt;
	void add(int x1, int x2, int y1, int y2) {
		pt.eb(x1, 0, y1, y2, 1);
		pt.eb(x2 + 1, 0, y1, y2, -1);
	}
	void ask(int x, int y, int i){
		pt.eb(x, i, y, 0, 0);
	}
	
	void ba(int p, int v) {
		for (; p < N + L; p += p & -p) bit[p] += v;
	}
	int bq(int p) { int v = 0;
		for (; p; p ^= p & -p) v += bit[p];
		return v;
	}
	
	void scan() {
		sort(pt.begin(), pt.end());
		for (auto [x, t, l, r, v] : pt) {
			if (t) {
				assert(!ans[t]);
				ans[t] = bq(l);
			} else {
				ba(l, v); ba(r + 1, -v);
			}
		}
	}
} cd[N];

void build() {
	m = id.size();
	if (!m) { while (q--) puts("0"); exit(0); }
	
	pair<int, int> ter[N] {};
	ap.ptr = as.ptr = m;
	U (i, 1, m) {
		for (int j : hok[i]) {
			reverse(a[j].second.begin(), a[j].second.end());
			ter[j].first = ap.insert(a[j].first, i);
			ter[j].second = as.insert(a[j].second, i);
		}
	}
	
	ap.build(m);
	as.build(m);
	
	U (i, 1, m) {
		for (int j : hok[i]) {
			auto [u, v] = ter[j];
			cd[i].add(ap.dfn[u], ap.dfn[u] + ap.siz[u] - 1, as.dfn[v], as.dfn[v] + as.siz[v] - 1);
		}
	}
}

void answer() {
	static char s[L], t[L];
	
	U (i, 1, q) {
		scanf("%s%s", s + 1, t + 1);
		int k = strlen(s + 1); if (strlen(t + 1) != k) continue;
		
		U (j, 1, k) s[j] -= 'a', t[j] -= 'a';
		
		int l = 0, r = 0;
		U (j, 1, k) if (s[j] != t[j]) {
			l = j; break;
		}
		D (j, k, 1) if (s[j] != t[j]) {
			r = j; break;
		}
		assert(l); assert(r);
		
		ll h1 = 0, h2 = 0;
		U (j, l, r) {
			h1 = (h1 * B + s[j] + 1) %P;
			h2 = (h2 * B + t[j] + 1) %P;
		}
		tuple<int, ll, ll> stat {r - l + 1, h1, h2};
		int p = id[stat]; if (!p) continue;
		
		string pre(s + 1, s + l), suf(s + r + 1, s + k + 1);
		reverse(suf.begin(), suf.end());
		int u = ap.match(p, pre),
			v = as.match(p, suf);
		cd[p].ask(ap.dfn[u], as.dfn[v], i);
	}
}


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	rd(n, q);
	init();
	build();
	
	answer();
	
	clog << "#" << ap.ptr << ' ' << as.ptr << endl;
	clog << "$" << 2 * sizeof(ap) / 1048576 << endl;
	
	U (i, 1, m) {
		cd[i].scan();
	}
	U (i, 1, q)
		printf("%d\n", ans[i]);
}
