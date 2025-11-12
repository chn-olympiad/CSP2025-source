#include <bits/stdc++.h>
using namespace std;
const int Mod1 = 1e9 + 7, Mod2 = 1e9 + 9, base = 233;
const int N = 2e5 + 7, S = 5e6 + 7;

struct Node {
	int op, x, l, r;
	
	inline bool operator < (const Node &rhs) const {
		return x == rhs.x ? op < rhs.op : x < rhs.x;
	} 
} nd[N * 3];

map<tuple<int, int, int, int>, int> mp;
string nsl[N], nsr[N], qsl[N], qsr[N];

int ans[N], inl[N], outl[N], inr[N], outr[N], dfnl[N], dfnr[N];
char s[S], t[S];

int n, q, idx;

namespace Trie {
int ch[S][26], in[S], out[S];

int tot, dfstime;

inline void clear() {
	for (; tot; --tot)
		memset(ch[tot], 0, sizeof(ch[tot]));
	
	tot = 1, dfstime = 0;
}

inline void insert(string str) {
	int u = 1;
	
	for (int i = 0; i < str.length(); ++i) {
		int c = str[i] - 'a';
		
		if (!ch[u][c])
			ch[u][c] = ++tot;
			
		u = ch[u][c];
	}
}

void dfs(int u) {
	in[u] = ++dfstime;
	
	for (int i = 0; i < 26; ++i)
		if (ch[u][i])
			dfs(ch[u][i]);
	
	out[u] = dfstime;
}

inline int query(string str) {
	int u = 1;
	
	for (int i = 0; i < str.length(); ++i) {
		int c = str[i] - 'a';
		
		if (!ch[u][c])
			return -1;
			
		u = ch[u][c];
	}
	
	return u;
}
} // namespace Trie

namespace BIT {
int c[S];

inline void modify(int x, int k) {
	for (; x < S; x += x & -x)
		c[x] += k;
}

inline void update(int l, int r, int k) {
	modify(l, k), modify(r + 1, -k);
}

inline int query(int x) {
	int res = 0;
	
	for (; x; x -= x & -x)
		res += c[x];
	
	return res;
}
} // namespace BIT

struct Solver {
	vector<int> nid, qid;
	
	inline void prework(string *ns, string *qs, int *in, int *out, int *dfn) {
		Trie::clear();
		
		for (int it : qid)
			Trie::insert(qs[it]);
		
		Trie::dfs(1);
		
		for (int it : qid)
			dfn[it] = Trie::in[Trie::query(qs[it])];
		
		for (int it : nid) {
			int x = Trie::query(ns[it]);
			
			if (~x)
				in[it] = Trie::in[x], out[it] = Trie::out[x];
		}
	}
	
	inline void solve() {
		prework(nsl, qsl, inl, outl, dfnl), prework(nsr, qsr, inr, outr, dfnr);
		int m = 0;
		
		for (int it : nid)
			if (inl[it] && outl[it] && inr[it] && outr[it]) {
				nd[++m] = (Node){1, inl[it], inr[it], outr[it]};
				nd[++m] = (Node){-1, outl[it] + 1, inr[it], outr[it]};
			}
		
		for (int it : qid)
			nd[++m] = (Node){2, dfnl[it], dfnr[it], it};
			
		sort(nd + 1, nd + m + 1);
		
		for (int i = 1; i <= m; ++i) {
			if (nd[i].op == 2)
				ans[nd[i].r] = BIT::query(nd[i].l);
			else
				BIT::update(nd[i].l, nd[i].r, nd[i].op);
		}
		
		for (int i = 1; i <= m; ++i)
			if (nd[i].op != 2)
				BIT::update(nd[i].l, nd[i].r, -nd[i].op);
	}
} solver[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	
	for (int i = 1; i <= n; ++i) {
		scanf("%s%s", s + 1, t + 1);
		int len = strlen(s + 1), l = 1, r = len;
		
		while (l <= len && s[l] == t[l])
			++l;
			
		if (l > len)
			continue;
			
		while (s[r] == t[r])
			--r;
			
		int res11 = 0, res12 = 0, res21 = 0, res22 = 0;
		
		for (int j = l; j <= r; ++j) {
			res11 = (1ll * res11 * base + s[j]) % Mod1, res12 = (1ll * res12 * base + s[j]) % Mod2;
			res21 = (1ll * res21 * base + t[j]) % Mod1, res22 = (1ll * res22 * base + t[j]) % Mod2;
		}
		
		tuple<int, int, int, int> res = make_tuple(res11, res12, res21, res22);
		
		if (mp.find(res) == mp.end())
			mp[res] = ++idx;
		
		solver[mp[res]].nid.emplace_back(i);
		nsl[i] = string(s + 1, s + l), nsr[i] = string(s + r, s + len + 1);
		reverse(nsl[i].begin(), nsl[i].end());
	}
	
	for (int i = 1; i <= q; ++i) {
		scanf("%s%s", s + 1, t + 1);
		int len = strlen(s + 1), l = 1, r = len;
		
		if (len != strlen(t + 1))
			continue;
		
		while (s[l] == t[l])
			++l;
			
		while (s[r] == t[r])
			--r;
			
		int res11 = 0, res12 = 0, res21 = 0, res22 = 0;
		
		for (int j = l; j <= r; ++j) {
			res11 = (1ll * res11 * base + s[j]) % Mod1, res12 = (1ll * res12 * base + s[j]) % Mod2;
			res21 = (1ll * res21 * base + t[j]) % Mod1, res22 = (1ll * res22 * base + t[j]) % Mod2;
		}
		
		tuple<int, int, int, int> res = make_tuple(res11, res12, res21, res22);
		
		if (mp.find(res) == mp.end())
			continue;
		
		solver[mp[res]].qid.emplace_back(i);
		qsl[i] = string(s + 1, s + l), qsr[i] = string(s + r, s + len + 1);
		reverse(qsl[i].begin(), qsl[i].end());
	}
	
	for (int i = 1; i <= idx; ++i)
		solver[i].solve();
		
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	
	return 0;
} 
