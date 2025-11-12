#include <bits/stdc++.h>
#define filein(x) freopen(x".in", "r", stdin)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout);
#define files(x) freopen(x".in", "r", stdin), freopen(x".ans", "w", stdout);
template <typename T>
inline T& chkmax(T& a, const T& b){if (a < b) a = b; return a;}
template <typename T>
inline T& chkmin(T& a, const T& b){if (a > b) a = b; return a;}
using namespace std; // my guiding star.
using ll = long long;
using pii = pair<int, int>;
const int N = 2e5 + 5, L = 5e6 + 5, C = 26, base = 131;
int n, q, ans[N];
string s[N][2], t[N][2];
template <const int P>
struct Hasher
{
	vector<int> pw, hsh;
	inline void init(string s)
	{
		int n = s.length(); pw.assign(n + 1, 0); hsh.assign(n + 1, 0); pw[0] = 1;
		for (int i=1; i<=n; i++) pw[i] = 1ll * pw[i - 1] * base % P;
		for (int i=1; i<=n; i++) hsh[i] = (1ll * hsh[i - 1] * base + s[i - 1]) % P;
	}
	inline int hashCode(int l, int r) const {return l > r ? 0 : ((hsh[r] - 1ll * pw[r - l + 1] * hsh[l - 1] % P) % P + P) % P;}
};
struct SmartHasher
{
	int n;
	Hasher<1004535809> H1;
	Hasher<1000003579> H2;
	inline void init(string s){H1.init(s); H2.init(s); n = s.length();}
	inline pii hashCode(int l, int r) const {return {H1.hashCode(l, r), H2.hashCode(l, r)};}
}S[N][2], T[N][2];
inline int lcp(const SmartHasher& H1, const SmartHasher& H2)
{
	int l = 0, r = min(H1.n, H2.n);
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (H1.hashCode(1, mid) == H2.hashCode(1, mid)) l = mid + 1;
		else r = mid - 1;
	}
	return l - 1;
}
inline int lcs(const SmartHasher& H1, const SmartHasher& H2)
{
	int l = 0, r = min(H1.n, H2.n);
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (H1.hashCode(H1.n - mid + 1, H1.n) == H2.hashCode(H2.n - mid + 1, H2.n)) l = mid + 1;
		else r = mid - 1;
	}
	return l - 1;
}
map<pair<pii, pii>, vector<tuple<int, int, int, bool>>> coco;
struct Trie
{
	map<pii, vector<int>> qry[L];
	vector<pii> ovo[L];
	int root, ch[L][C], siz[L], son[L], cc;
	inline void inserttag(string s, vector<pii> hsh, int i)
	{
		int u = root;
		for (char c : s)
		{
			if (!ch[u][c - 'a']) ch[u][c - 'a'] = ++cc;
			u = ch[u][c - 'a'];
		}
		for (pii h : hsh) qry[u][h].emplace_back(i), ++siz[u];
	}
	inline void insertovo(string s, pii hsh)
	{
		int u = root;
		for (char c : s)
		{
			if (!ch[u][c - 'a']) ch[u][c - 'a'] = ++cc;
			u = ch[u][c - 'a'];
		}
		ovo[u].emplace_back(hsh);
	}
	void dfs1(int u)
	{
		for (int c=0; c<C; c++)
			if (ch[u][c])
			{
				dfs1(ch[u][c]); siz[u] += siz[ch[u][c]];
				if (!son[u] || (siz[son[u]] < siz[ch[u][c]])) son[u] = ch[u][c];
			}
	}
	// ========== dsu on tree ==========
	map<pii, int> tag;
	vector<pair<pii, int>> pvp;
	void add(int u){for (auto&& [h, v] : qry[u]) for (int i : v){ans[i] -= tag[h]; pvp.emplace_back(h, i);}}
	void clr(){for (auto [h, i] : pvp) ans[i] += tag[h]; pvp.clear(); tag.clear();}
	void dfs2(int u, int cl = 1)
	{
		for (int c=0; c<C; c++)
			if (ch[u][c] && (ch[u][c] != son[u])) dfs2(ch[u][c], cl == 2 ? 2 : 1);
		if (son[u]) dfs2(son[u], cl == 2 ? 2 : 0);
		if (cl != 2)
		{
			for (int c=0; c<C; c++)
				if (ch[u][c] && (ch[u][c] != son[u])) dfs2(ch[u][c], 2);
		}
		add(u);
		if (cl != 2) for (pii h : ovo[u]) ++tag[h];
		if (cl == 1) clr();
	}
	// ========== dsu on tree ==========
	inline void clear(){for (int i=0; i<=cc; i++){qry[i].clear(); ovo[i].clear(); memset(ch[i], 0, sizeof ch[i]); siz[i] = son[i] = 0;} cc = 0;}
	Trie() : root(0), cc(0){}
}trie;
int main()
{
	file("replace");
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> q;
	for (int i=1; i<=n; i++)
	{
		cin >> s[i][0] >> s[i][1];
		if (s[i][0] == s[i][1]) continue;
		S[i][0].init(s[i][0]); S[i][1].init(s[i][1]);
		int o = s[i][0].length(), p = lcp(S[i][0], S[i][1]), q = lcs(S[i][0], S[i][1]);
		coco[{S[i][0].hashCode(p + 1, o - q), S[i][1].hashCode(p + 1, o - q)}].emplace_back(i, p, q, 0);
	}
	for (int i=1; i<=q; i++)
	{
		cin >> t[i][0] >> t[i][1];
		if (t[i][0].length() != t[i][1].length()) continue;
		T[i][0].init(t[i][0]); T[i][1].init(t[i][1]);
		int o = t[i][0].length(), p = lcp(T[i][0], T[i][1]), q = lcs(T[i][0], T[i][1]);
		coco[{T[i][0].hashCode(p + 1, o - q), T[i][1].hashCode(p + 1, o - q)}].emplace_back(i, p, q, 1);
	}
	for (auto&& [o, v] : coco)
	{
		trie.clear();
		for (auto&& [i, p, q, _] : v)
		{
			if (_ == 0) trie.insertovo(s[i][0].substr(S[i][0].n - q), S[i][0].hashCode(1, p));
			else
			{
				vector<pii> ovo;
				for (int o=1; o<=p+1; o++) ovo.emplace_back(T[i][0].hashCode(o, p));
				trie.inserttag(t[i][0].substr(T[i][0].n - q), ovo, i);
			}
		}
		trie.dfs1(trie.root); trie.dfs2(trie.root);
	}
	for (int i=1; i<=q; i++) cout << ans[i] << '\n';
	return 0;
}
