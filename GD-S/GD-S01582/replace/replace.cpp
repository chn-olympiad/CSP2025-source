#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 5, MOD1 = 998244353, MOD2 = 993244853, M = 5e6 + 5;

int n, q;

string s1[N], s2[N], sq1[N], sq2[N];
string ps[N], ss[N], qps[N], qss[N];
array<int, N> prel, sufl, ans, prelq, suflq, tlen;

vector<int> pos[N], rq[N], pl[N];
vector<pair<int, int>> pc[N], sc[N];

struct Two_Hash
{
public:
	int v1, v2;
	bool operator==(const Two_Hash t) const
	{
		return (v1 == t.v1 && v2 == t.v2);
	}
	bool operator<(const Two_Hash t) const
	{
		return (v1 != t.v1 ? (v1 < t.v1) : (v2 < t.v2));
	}
	Two_Hash() = default;
	Two_Hash(int v1, int v2): v1(v1), v2(v2){}
	Two_Hash operator+(const int x)
	{
		int nv1 = v1 + x, nv2 = v2 + x;
		nv1 >= MOD1 ? nv1 -= MOD1 : 0;
		nv2 >= MOD2 ? nv2 -= MOD2 : 0;
		return Two_Hash(nv1, nv2);
	}
	Two_Hash operator*(const int x)
	{
		return Two_Hash(1ll * v1 * x % MOD1, 1ll * v2 * x % MOD2);
	}
	Two_Hash operator+(const Two_Hash x)
	{
		int nv1 = v1 + x.v1, nv2 = v2 + x.v2;
		nv1 >= MOD1 ? nv1 -= MOD1 : 0;
		nv2 >= MOD2 ? nv2 -= MOD2 : 0;
		return Two_Hash(nv1, nv2);
	}
	Two_Hash operator*(const Two_Hash x)
	{
		return Two_Hash(1ll * v1 * x.v1 % MOD1, 1ll * v2 * x.v2 % MOD2);
	}
};

vector<pair<Two_Hash, Two_Hash>> avs;
array<pair<Two_Hash, Two_Hash>, N> tws;

inline Two_Hash calc(string &str)
{
	Two_Hash res = Two_Hash(0, 0);
	for (auto &c : str)
	{
		res = res * 31 + (c - 'a' + 1);
	}
	return res;
}

class Fenwick_Tree
{
public:
	array<int, M> tr;
	inline void update(int u, int x)
	{
		while (u < M) tr[u] += x, u += u & -u;
	}
	inline int query(int u)
	{
		int res = 0;
		while (u) res += tr[u], u -= u & -u;
		return res;
	}
}fwt;

class Trie
{
public:
	array<array<int, 26>, M> son;
	array<int, M> dfn, sz;
	int idx, idx2;
	inline void clear()
	{
		for (int i = 0; i <= idx; i++) son[i].fill(0), sz[i] = dfn[i] = 0;
		idx = 0;
		idx2 = 0;
	}
	inline void dfs(int u)
	{
		sz[u] = 1;
		dfn[u] = ++idx2;
		for (int j = 0; j < 26; j++) if (son[u][j]) dfs(son[u][j]), sz[u] += sz[son[u][j]];
	}
	inline int ins(string s)
	{
		int now = 0;
		for (auto &i : s)
		{
			if (!son[now][i - 'a']) son[now][i - 'a'] = ++idx;
			now = son[now][i - 'a'];
		}
		return now;
	}
}f1, f2;

vector<tuple<int, int, int>> op[M];
vector<pair<int, int>> rqd[M];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
		if (s1[i] == s2[i]) continue;
		else
		{
			while (s1[i].back() == s2[i].back()) ss[i] += s1[i].back(), s1[i].pop_back(), s2[i].pop_back(), sufl[i]++;
			int c = 0;
			while (c < s1[i].size() && s1[i][c] == s2[i][c])
			{
				ps[i] += s1[i][c];
				prel[i]++, c++;
			}
			s1[i] = s1[i].substr(c), s2[i] = s2[i].substr(c);
			tws[i] = make_pair(calc(s1[i]), calc(s2[i]));
			avs.emplace_back(tws[i]);
		}
	}
	sort(avs.begin(), avs.end());
	avs.erase(unique(avs.begin(), avs.end()), avs.end());
	for (int i = 1; i <= n; i++)
	{
		if (s1[i] != s2[i])
		{
			int id = lower_bound(avs.begin(), avs.end(), tws[i]) - avs.begin() + 1;
			pos[id].emplace_back(i);
			pc[id].emplace_back(prel[i], s1[i].size() + prel[i] + sufl[i]);
			sc[id].emplace_back(sufl[i], s1[i].size() + prel[i] + sufl[i]);
			pl[id].emplace_back(s1[i].size() + prel[i] + sufl[i]); 
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sort(pc[i].begin(), pc[i].end());
		sort(sc[i].begin(), sc[i].end());
		sort(pl[i].begin(), pl[i].end());
		reverse(ps[i].begin(), ps[i].end());
		reverse(ss[i].begin(), ss[i].end());
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> sq1[i] >> sq2[i];
		int len = sq1[i].size();
		tlen[i] = len;
		while (sq1[i].back() == sq2[i].back()) qss[i] += sq1[i].back(), sq1[i].pop_back(), sq2[i].pop_back(), suflq[i]++;
		int c = 0;
		while (c < sq1[i].size() && sq1[i][c] == sq2[i][c])
		{
			qps[i] += sq1[i][c];
			prelq[i]++, c++;
		}
		sq1[i] = sq1[i].substr(c), sq2[i] = sq2[i].substr(c);
		Two_Hash ra = calc(sq1[i]), rb = calc(sq2[i]);
		auto it = lower_bound(avs.begin(), avs.end(), make_pair(ra, rb));
		if (it == avs.end() || *it != make_pair(ra, rb)) continue;
		int id = it - avs.begin() + 1;
		rq[id].emplace_back(i);
		reverse(qps[i].begin(), qps[i].end());
		reverse(qss[i].begin(), qss[i].end());
	}
	for (int i = 1; i <= n; i++)
	{
		if (rq[i].empty() || pos[i].empty()) continue;
		f1.clear(), f2.clear();
		vector<pair<int, int>> vv;
		for (auto &id : pos[i])
		{
			vv.emplace_back(make_pair(f1.ins(ps[id]), f2.ins(ss[id])));
		}
		f1.dfs(0), f2.dfs(0);
		for (int j = 0; j <= f1.idx + 2; j++) vector<tuple<int, int, int>>().swap(op[j]), vector<pair<int, int>>().swap(rqd[j]); 
		for (auto &x : vv)
		{
			int a = x.first, b = x.second;
			int l1 = f1.dfn[a], r1 = f1.dfn[a] + f1.sz[a] - 1;
			int l2 = f2.dfn[b], r2 = f2.dfn[b] + f2.sz[b] - 1;
			op[l1].emplace_back(l2, r2, 1);
			op[r1 + 1].emplace_back(l2, r2, -1);
		}
		for (auto &qid : rq[i])
		{
			int ta = 0, tb = 0;
			for (auto &i : qps[qid])
			{
				int j = i - 'a';
				if (f1.son[ta][j]) ta = f1.son[ta][j];
				else break;
			}
			for (auto &i : qss[qid])
			{
				int j = i - 'a';
				if (f2.son[tb][j]) tb = f2.son[tb][j];
				else break;
			}
			rqd[f1.dfn[ta]].emplace_back(f2.dfn[tb], qid);
		}
		for (int j = 1; j <= f1.idx2 + 2; j++)
		{
			for (auto &c : op[j])
			{
				int l = get<0>(c), r = get<1>(c), val = get<2>(c);
				fwt.update(l, val);
				fwt.update(r + 1, -val);
			}
			for (auto &c : rqd[j])
			{
				int x = c.first, id = c.second;
				ans[id] = fwt.query(x);
			}
		}
		for (int j = 1; j <= f1.idx2 + 2; j++)
		{
			for (auto &c : op[j])
			{
				int l = get<0>(c), r = get<1>(c), val = get<2>(c);
				fwt.update(l, -val);
				fwt.update(r + 1, val);
			}
		}
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
	return 0;
}
