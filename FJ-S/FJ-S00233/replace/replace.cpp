#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 5000005
using namespace std;

int n, q;
int num, dfn[N], dln[N];
int top, stk[N];
char s0[N], s1[N];
long long ans[N];

struct opt {int x, len, id; opt (int u, int v, int w) {x = u, len = v, id = w;}};
struct que {int x, id, k; que (int u, int v, int w) {x = u, id = v, k = w;}};

vector <int> p[N];
vector <opt> qq[N];
vector <que> qry[N];

struct fenwick_tree
{
	int tr[N];
	
	void add (int p, int c)
	{
		for (; p <= num; p += p & -p) tr[p] += c;
		return ;
	}
	
	void add (int l, int r, int c) {return add (l, c), add (r + 1, -c);}
	
	int ask (int p)
	{
		int res = 0;
		for (; p; p &= p - 1) res += tr[p];
		return res;
	}
} t1;

struct AC
{
	int tot, trie[N][26], dep[N], fail[N];
	int lt, rt, q[N];
	int to, head[N], nxt[N], ver[N];
	
	int insert (int p, char *s, int len, int k)
	{
		if (k > len) return p;
		int ch = s[k] - 'a';
		if (!trie[p][ch]) trie[p][ch] = ++ tot, dep[tot] = dep[p] + 1;
		return insert (trie[p][ch], s, len, k + 1);
	}
	
	void add (int x, int y)
	{
		ver[++ to] = y, nxt[to] = head[x], head[x] = to;
		return ;
	}
	
	void build ()
	{
		fail[0] = ++ tot;
		lt = 1, rt = 0, q[++ rt] = 0;
		while (lt <= rt)
		{
			int x = q[lt ++];
			for (int i = 0; i < 26; i ++)
			{
				int &y = trie[x][i];
				if (!y) y = trie[fail[x]][i];
				else fail[y] = trie[fail[x]][i], q[++ rt] = y;
			}
		}
		for (int i = 1; i < tot; i ++)
		{
			add (fail[i], i);
		}
		return ;
	}
} t2, t3;

void dfs1 (int x)
{
	dfn[x] = ++ num;
	for (int i = t3.head[x]; i; i = t3.nxt[i]) dfs1 (t3.ver[i]);
	dln[x] = num;
	return ;
}

void dfs2 (int x)
{
	if (x) stk[++ top] = x;
	for (auto u : qq[x])
	{
		if (t2.dep[x] >= u.len)
		{
			qry[x].emplace_back (u.x, u.id, 1);
			int l = 0, r = top;
			while (l < r)
			{
				int mid = (l + r + 1) >> 1;
				if (t2.dep[stk[mid]] < u.len) l = mid;
				else r = mid - 1;
			}
			qry[stk[l]].emplace_back (u.x, u.id, -1);
		}
	}
	for (int i = t2.head[x]; i; i = t2.nxt[i])
	{
		dfs2 (t2.ver[i]);
	}
	if (x) top --;
	return ;
}

void dfs3 (int x)
{
	for (auto u : p[x])
	{
		t1.add (dfn[u], dln[u], 1);
	}
	for (auto u : qry[x])
	{
		ans[u.id] += u.k * t1.ask (dfn[u.x]);
	}
	for (int i = t2.head[x]; i; i = t2.nxt[i])
	{
		dfs3 (t2.ver[i]);
	}
	for (auto u : p[x])
	{
		t1.add (dfn[u], dln[u], -1);
	}
	return ;
}

int main ()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	scanf ("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%s%s", s0 + 1, s1 + 1);
		int len0 = strlen (s0 + 1), len1 = strlen (s1 + 1);
		int p0 = t2.insert (0, s0, len0, 1), p1 = t3.insert (0, s1, len1, 1);
		p[p0].push_back (p1);
	}
	t2.build (), t3.build (), dfs1 (0);
	for (int i = 1; i <= q; i ++)
	{
		scanf ("%s%s", s0 + 1, s1 + 1);
		int len0 = strlen (s0 + 1), len1 = strlen (s1 + 1);
		if (len0 != len1) {ans[i] = 0; continue;}
		int sl = 0, sr = 0;
		while (s0[sl + 1] == s1[sl + 1]) sl ++;
		while (s0[len0 - sr] == s1[len1 - sr]) sr ++;
		for (int j = 1, p0 = 0, p1 = 0; j <= len0; j ++)
		{
			p0 = t2.trie[p0][s0[j] - 'a'], p1 = t3.trie[p1][s1[j] - 'a'];
			if (j >= len0 - sr)
			{
				qq[p0].emplace_back (p1, j - sl, i);
			}
		}
	}
	dfs2 (0), dfs3 (0);
	for (int i = 1; i <= q; i ++)
	{
		printf ("%lld\n", ans[i]);
	}
	return 0;
}
