#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int a[15][10010], c[15];
int fa[10010];
long long ans = 1e18;

struct Edge
{
	int u, v, w;
}eg[1000010], nw[1000010];
int ix, idx;

int find(int u)
{
	if(u == fa[u]) return u;
	return fa[u] = find(fa[u]);
}

bool cmp(Edge xx, Edge yy)
{
	return xx.w < yy.w;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		eg[++ ix] = {u, v, w};
	}
	sort(eg + 1, eg + ix + 1, cmp);
	for(int i = 0;i < k;i ++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j ++) cin >> a[i][j];
	}
	sort(nw + 1, nw + idx + 1, cmp);
	for(int s = 0;s < (1 << k);s ++)
	{
		for(int i = 1;i <= n + k;i ++) fa[i] = i;
		long long sum = 0;
		idx = 0;
		int sz = n - 1;
		for(int i = 0;i < k;i ++)
		{
			if(((s >> i) & 1))
			{
				sz ++;
				sum += c[i];
				for(int j = 1;j <= n;j ++) nw[++ idx] = {i + n + 1, j, a[i][j]};
			}
		}
		sort(nw + 1, nw + idx + 1, cmp);
		for(int i = 1, j = 1, cz = 0;i <= ix || j <= idx;)
		{
			if(i <= ix && (j > idx || eg[i].w <= nw[j].w))
			{
				int val = eg[i].w;
				int fu = find(eg[i].u), fv = find(eg[i].v);
//				cout << i << " " << j << "\n";
				i ++;
				if(fu == fv) continue;
				sum += val;
				fa[fu] = fv;
				sz ++;
			}
			else
			{
				int val = nw[j].w;
				int fu = find(nw[j].u), fv = find(nw[j].v);
//				cout << i << " " << j << "*\n";
				j ++;
				if(fu == fv) continue;
				sum += val;
				fa[fu] = fv;
				sz ++;
			}
			if(sz == 0 || sum >= ans) break;
		}
		ans = min(ans, sum);
	}
	cout << ans;
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

*/
