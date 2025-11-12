#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 5, M = 2e6 + 5;
int n, m, k, cnt = 0, fa[N], ans = 0, pre[N], c[N], vis[N], tmp = 0;
struct node { int from, to, ne, len; } a[M];
bool cmp(node n1, node n2) { return n1.len < n2.len; }
void add(int u, int v, int w) { a[++cnt] = (node){u, v, pre[u], w}; pre[u] = cnt; return; }
void init() { for (int i = 1; i <= n; i++) fa[i] = i; return; }
int find(int x) { if (fa[x] == x) return x; return fa[x] = find(fa[x]); }
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	init();
	for (int i = 1, u, v, w; i <= m; i++)
	{
		scanf("%lld%lld%lld", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i + n]);
		for (int j = 1, x; j <= n; j++)
		{
			scanf("%lld", &x);
			add(i + n, j, x + c[i + n]);
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
	{
		int u = a[i].from, v = a[i].to;
		if (find(u) == find(v))
			continue;
		if (vis[u])
			ans -= c[u];
		vis[u]++;
		ans += a[i].len;
		tmp++;
		if (tmp >= n)
			break;
	}
	printf("%lld", ans);
	return 0;
}