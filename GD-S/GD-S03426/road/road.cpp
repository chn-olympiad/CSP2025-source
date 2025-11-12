#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 17;
int i, j, k, l, r, m, n, K, f[N], s[N], p[12], c[12];
struct edge
{
	int a, b, c;
	bool operator < (const edge&x) const {return c < x.c;}
} e[N*100], d[12][N];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
ll solve(int S)
{
	ll ans = 0; int cnt = 0, tot = 0;
	priority_queue <pair<int, int>> q;
	for (i=0; i<=K; i++) p[i] = 1; 
	q.emplace(-d[0][1].c, 0);
	for (i=1; i<=K; i++) if (S >> (i-1) & 1) q.emplace(-d[i][1].c, i), ans += c[i], tot++;
	for (i=1; i<=n+K; i++) f[i] = i, s[i] = 1;
	while (q.size())
	{
		int k = q.top().second, a = find(d[k][p[k]].a), b = find(d[k][p[k]].b);
		if (a != b) 
		{
			if (s[a] < s[b]) swap(a, b);
			ans += d[k][p[k]].c, f[a] = b, s[a] += s[b];
			if (++cnt == n+tot-1) break; 
		}
		q.pop();
		if (p[k] < (k ? n : n-1)) q.emplace(-d[k][++p[k]].c, k);
	}
	return ans;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &K);
	for (i=1; i<=m; i++) scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c);
	sort(e+1, e+m+1);
	for (i=1; i<=K; i++)
	{
		scanf("%d", &c[i]);
		for (j=1; j<=n; j++) 
		{
			scanf("%d", &k);
			d[i][j] = {n+i, j, k}; 
		}
		sort(d[i]+1, d[i]+n+1);
	}
	iota(f+1, f+n+1, 1);
	for (k=0,i=1; i<=m; i++)
	{
		int a = find(e[i].a), b = find(e[i].b);
		if (a != b) d[0][++k] = e[i], f[a] = b;
	}
	ll ans = 1e18;
	for (int t=0; t<1<<K; t++) ans = min(ans, solve(t));
	printf("%lld", ans);
}

