#include <bits/stdc++.h>
using namespace std;
struct Edges
{
	int u,v,w;
}e[1000005];
struct Node
{
	int c,a[10005];
}vl[15];
int n,m,k,fa[10005];
long long ans;
vector<int> vis;
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(Edges x,Edges y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i=1;i<=k;i++)
	{
		cin >> vl[i].c;
		for (int j=1;j<=n;j++)
		{
			cin >> vl[i].a[j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++)
	{
		if (find(e[i].u)!=find(e[i].v))
		{
			fa[e[i].u]=e[i].v;
			vis.push_back(i);
			ans+=e[i].w;
		}
	}
	if (k==0)
	{
		cout << ans;
	}
	return 0;
}
