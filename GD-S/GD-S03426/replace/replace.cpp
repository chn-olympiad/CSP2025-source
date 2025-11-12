#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7, M = 5e6 + 7, mo1 = 1e9 + 7, mo2 = 1e9 + 9, B1 = 10007, B2 = 10009;
int i, j, k, l, r, m, n, Q, tot, idx, cnt, h1[M], h2[M], ans[N];
char a[M], b[M];
ll cal(int l, int r)
{
	int i, s1 = 0, s2 = 0;
	for (i=l; i<=r; i++) 
	{
		s1 = (1ll * s1 * B1 + a[i]) % mo1;
		s2 = (1ll * s2 * B2 + a[i]) % mo2;
	}
	for (i=l; i<=r; i++) 
	{
		s1 = (1ll * s1 * B1 + b[i]) % mo1;
		s2 = (1ll * s2 * B2 + b[i]) % mo2;
	}
	return 1ll * s1 * mo2 + s2;
} 
unordered_map <ll, int> id;
int t[M][26], sz[M], s[M], rt[2][N], dfn[M];
struct query {int t, k;};
vector <query> z[M], q[M];
void ins(int l, int r, int m, int id)
{
	int p = rt[0][id], c, i, t1 = 0, t2 = 0;
	for (i=r; i<=m; i++)
	{
		c = a[i] - 'a';
		if (!t[p][c]) t[p][c] = ++tot;
		p = t[p][c];
	}
	t1 = p, p = rt[1][id];
	for (i=l; i>=1; i--)
	{
		c = a[i] - 'a';
		if (!t[p][c]) t[p][c] = ++tot;
		p = t[p][c];
	}
	t2 = p;
	z[t1].push_back({t2, 0});
}

void ask(int l, int r, int m, int k, int id)
{
	int p = rt[0][id], c, i, t1 = 0, t2 = 0;
	for (i=r; i<=m; i++)
	{
		c = a[i] - 'a';
		if (!t[p][c]) break;
		p = t[p][c];
	}
	t1 = p, p = rt[1][id];
	for (i=l; i>=1; i--)
	{
		c = a[i] - 'a';
		if (!t[p][c]) break;
		p = t[p][c];
	}
	t2 = p;
	q[t1].push_back({t2, k});
}
void dfs(int p, int id)
{
	dfn[p] = ++cnt, sz[p] = 1;
	for (int i=0; i<26; i++) if (t[p][i]) dfs(t[p][i], id), sz[p] += sz[t[p][i]];
}
int c[M];
void add(int x, int v)
{
	for (; x<=tot; x+=-x&x) c[x] += v;
}
int sum(int x)
{
	int res = 0;
	for (; x; x-=-x&x) res += c[x];
	return res;
}
void work(int p, int id)
{
	for (auto Z:z[p]) add(dfn[Z.t], 1), add(dfn[Z.t]+sz[Z.t], -1);
	for (auto Q:q[p]) ans[Q.k] += sum(dfn[Q.t]);
	for (int i=0; i<26; i++) if (t[p][i]) work(t[p][i], id);
	for (auto Z:z[p]) add(dfn[Z.t], -1), add(dfn[Z.t]+sz[Z.t], 1);
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &Q);
	for (h1[0]=h2[0]=i=1; i<M; i++)
	{
		h1[i] = 1ll * h1[i-1] * B1 % mo1;
		h2[i] = 1ll * h2[i-1] * B2 % mo1;
	}
	for (i=1; i<=n; i++)
	{
		scanf("%s %s", a+1, b+1);
		l = 1, r = m = strlen(a+1);
		while (l <= m && a[l] == b[l]) l++;
		if (l > m) continue;
		while (a[r] == b[r]) r--; 
		ll val = cal(l, r);
		if (!id.count(val)) id[val] = ++idx, rt[0][id[val]] = ++tot, rt[1][id[val]] = ++tot;
		ins(l, r, m, id[val]);
	}
	for (i=1; i<=Q; i++)
	{
		scanf("%s %s", a+1, b+1);
		l = 1, r = m = strlen(a+1);
		if (strlen(b+1) != m) continue;
		while (a[l] == b[l]) l++;
		while (a[r] == b[r]) r--; 
		ll val = cal(l, r);
		if (!id.count(val)) continue;
		ask(l, r, m, i, id[val]);
	}
	for (i=1; i<=idx; i++) dfs(rt[1][i], i);
	for (i=1; i<=idx; i++) work(rt[0][i], i);
	for (i=1; i<=Q; i++) printf("%d\n", ans[i]);
}

