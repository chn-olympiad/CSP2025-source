#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int M = 1000005;
int n, m, k, num;
long long wi[10], fa[N+10], ans;
bool vis[15];
struct Edge
{
	int u, v;
	long long w;
}e[M], g[10*N];
bool cmp(Edge x,Edge y)
{
	return x.w < y.w;
}
long long find(int x)
{
	if (x == fa[x])
	{
		return x;
	}
	return find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int u, v, w;
	for (int i = 1;i <= m;i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int j = 0;j < k;j++)
	{
		cin >> wi[j+1];
		for (int i = 1;i <= n;i++)
		{
			cin >> g[j*n+i].w;
			g[j*n+i].v = n+j;
			g[j*n+i].u = i;
		}
	}
	for (int i = 1;i <= n+10;i++)
	{
		fa[i] = i;
	}
	sort(e+1,e+m+1,cmp);
	sort(g+1,g+k*n+1,cmp);
	for (int i = 1;i <= n;i++)
	{
		if (num == n-1)
		{
			break;
		}
		if (find(e[i].u) != find(e[i].v))
		{
			fa[e[i].u] = find(e[i].v);
			ans += e[i].w;
			num++;
			for (int j = 1;j <= k;j++)
			{
				int cnt = 0;
				if (!vis[j])
				{
					cnt = wi[j];
				}
				if (cnt + g[j*n+e[i].u].w + g[j*n+e[i].v].w < e[i].w)
				{
					ans -= e[i].w;
					ans += cnt + g[j*n+e[i].u].w + g[j*n+e[i].v].w;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
