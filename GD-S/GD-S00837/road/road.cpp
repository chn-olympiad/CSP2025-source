#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn = 1e4 + 5, maxk = 15, maxm = 1e6 + 5;
LL n, m, k, ans, s, fa[maxn], dis[maxn][maxn];
struct node
{
	LL u, w;
};
struct line
{
	LL u, v, w, p;
}edge[maxm + maxn * maxn / 10];
bool cmp(line a, line b)
{
	return a.w < b.w;
}
vector <node> e[maxn];
LL c[maxk], a[maxk][maxn];
bool vis[maxk];

LL find(LL x)
{
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1, x, y, z; i <= m; i++)
	{
		scanf("%lld%lld%lld", &x, &y, &z);
		edge[i] = {x, y, z, 0};
		dis[x][y] = dis[y][x] = z;
	}
	for(int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++)
			scanf("%lld", &a[i][j]);
		for(int j = 1; j <= n; j++)
			for(int v = 1; v <= j; v++)
			{
				if(j == v) continue;
				edge[++m] = {j, v, c[i] + a[i][j] + a[i][v], i};
			}
	}
	sort(edge + 1, edge + 1 + m, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		LL fx = find(edge[i].u), fy = find(edge[i].v);
		if(fx != fy)
		{
			ans += edge[i].w;
			if(edge[i].p != 0)
			{
				ans -= vis[edge[i].p] * c[i];
				vis[edge[i].p] = 1;
			}
			fa[fy] = fx;
			s++;
		}
		if(s == n - 1)
		{
			break;
		}
	}
	printf("%lld", ans);
	return 0;
}
