#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10010;
const int M = 1000010;

struct edge
{
	int u, v, w;
	bool operator < (const edge &u) const { return w < u.w; }
} e[M << 1];

int n, m, k, cnt;
int fa[N << 1];

int findx(int x)
{
	if (x != fa[x]) fa[x] = findx(fa[x]);
	return fa[x];
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	cnt = m;
	for (int i = 1; i <= k; i++)
	{
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= n; j++) scanf("%d", &c), e[++cnt] = {n + i, j, c};
	}
	sort(e + 1, e + cnt + 1);
	ll ans = 0;
	for (int i = 1, j = 0; i <= cnt && j < n + k - 1; i++)
	{
		int fu = findx(e[i].u), fv = findx(e[i].v);
		if (fu == fv) continue;
		ans += e[i].v;
		fa[fu] = fv;
		j++;
	}
	printf("%lld", ans);
	return 0;
}
