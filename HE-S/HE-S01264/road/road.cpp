#include<bits/stdc++.h>
using namespace std;
int n, m, k, tot, qwq;
int fa[110000], ww[110000];
bool vis[1010][1010];
struct node
{
	int u, v;
	long long w;
}edge[2100000];
int find(int x)
{
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]); 
}
bool cmp(node x,node y)
{
	return x.w < y.w;
}
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	tot = n;
	for(int i=1;i<=n;i++)
	{
		fa[i] = i;
	}
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge[++qwq].u = u;
		edge[qwq].v = v;
		edge[qwq].w = w;
	}
	for(int i=1;i<=k;i++)
	{
		int num;
		cin >> num;
		tot++;
		for(int j=1;j<=n;j++)
		{
			cin >> ww[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				edge[++qwq].u = j;
				edge[qwq].v = k;
				edge[qwq].w = ww[j]+ww[k]+num;
			}
		}
	}
	sort(edge+1,edge+qwq+1,cmp);
	for(int i=1;i<=qwq;i++)
	{
		int uu = edge[i].u;
		int vv = edge[i].v;
		int ww = edge[i].w;
		if(vis[uu][vv]) continue;
		int fau = find(uu);
		int fav = find(vv);
		if(fau == fav) continue;
		vis[uu][vv] = 1;
		ans += ww;
		fa[fav] = fau;
	}
	cout << ans;
	return 0;
} 
