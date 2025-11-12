#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline int read()
{
	// int f = 1?
	int res = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

const int MAXN = 1e4 + 10, INF = 0x3f3f3f3f;

int n, m, k, c[11], fa[MAXN + 20];

#define edge pair<int, pair<int, int> > // <w2, u2, v2>.
#define w2 first
#define u2 second.first
#define v2 second.second
#define make_edge(a, b, c) make_pair(a, make_pair(b, c))

edge b[MAXN], b2[1000010]; int b_cnt = 0, cnt2 = 0; ll ans = 0, res = 0;
edge a[12][MAXN];

inline void fa_clear()
	{for (int i = 1; i <= n + 10; i++) fa[i] = i;}
inline int find(int x)
	{return fa[x] == x ? x : fa[x] = find(fa[x]);}
inline void un_(int u, int v)
	{fa[find(u)] = find(v);}

priority_queue<pair<int, pair<int, int> > > qu; // <-a[i][j].w2, i, j>.

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	for (int i = 1, i1, i2, i3; i <= m; i++)
		i1 = read(), i2 = read(), i3 = read(), b2[i] = make_edge(i3, i1, i2);
	
	sort(b2 + 1, b2 + m + 1), fa_clear(), cnt2 = n;
	for (int i = 1, u, v, uu, vv; i <= m; i++)
	{
		if (cnt2 == 1) break;
		u = b2[i].u2, v = b2[i].v2, uu = find(u), vv = find(v);
		if (uu != vv) cnt2--, ans += b2[i].w2, fa[uu] = vv, a[0][++b_cnt] = b2[i]; // b[++b_cnt] = b2[i];
	}
	a[0][b_cnt + 1] = make_edge(INF, 0, 0);
	
	for (int i = 1; i <= k; i++)
	{
		c[i] = read();
		for (int j = 1, j_; j <= n; j++) j_ = read(), a[i][j] = make_edge(j_, j, n + i);
		sort(a[i] + 1, a[i] + n + 1), a[i][n + 1] = make_edge(INF, 0, 0);
	}
	
	for (int j = 1, j_ = (1 << k); j < j_; j++)
	{
		cnt2 = n, res = 0; while (qu.size()) qu.pop();
		for (int i = 1; i <= k; i++)
			if ((j >> (i - 1)) & 1) res += c[i], cnt2++, qu.push(make_edge(-a[i][1].w2, i, 1));
		qu.push(make_edge(-a[0][1].w2, 0, 1));
		if (res >= ans) continue;
		
		fa_clear();
		while (1)
		{
			auto qu_ = qu.top(); qu.pop();
			int val = -qu_.w2, p = qu_.u2, q = qu_.v2;
			if (val == INF || cnt2 == 1) break;
			
			int u = a[p][q].u2, v = a[p][q].v2, uu = find(u), vv = find(v);
			if (uu != vv) cnt2--, res += a[p][q].w2, fa[uu] = vv;
			qu.push(make_edge(-a[p][q + 1].w2, p, q + 1));
			
			if (res >= ans) break;
		}
		ans = min(ans, res);
	}
	printf("%lld", ans);
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


Time complexity: \sum C(k, i) * (i+1)n * ???

\sum C(k, i) * i, max = 5120.
*/
