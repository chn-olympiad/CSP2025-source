#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[12][10005],c[12],fa[100005];
struct Edge
{
	int v,w;
}edge[100005];
vector<Edge> e[100005];
bool cmp(Edge x,Edge y)
{
	return x.w < y.w;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int kr()
{
	int cnt = 0,ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < e[i].size(); j++)
		{
			int v = e[i][j].v,w = e[i][j].w;
			if(find(v) != find(i))
			{
				fa[v] = i;
				cnt++;
				ans += w;
			}
			if(cnt == n - 1)
			{
				return ans;
			}
		}
	}
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++)
    {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back((Edge){v,w});
		e[v].push_back((Edge){u,w});
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= n && j != i; j++)
		{
			e[i].push_back((Edge){j,a[i][j] + a[i][i] + c[i]});
			e[j].push_back((Edge){i,a[i][j] + a[i][i] + c[i]});
		}
	}
	sort(edge + 1,edge + m + (n - 1) * k + 1,cmp);
	cout << kr();
    return 0;
}
