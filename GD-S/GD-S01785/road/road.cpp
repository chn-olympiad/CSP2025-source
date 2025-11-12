#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int u;
	int v;
	int w;
}e[100005];


bool cmp(edge e1, edge e2)
{
	return e1.w < e2.w;
}

bool d[10005];
int vi[12][10005];
int p[10005][10005];
int c[12];
int n, m, k;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin >> e[i].u>> e[i].v >> e[i].w;
	}
	sort(e+1, e+n+1, cmp);
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> vi[i][j];
		}
	}
	memset(d, 0, sizeof d);
	memset(p, -1, sizeof p);
	int sum = 0;
	for(int i=1;i<=m;i++)
	{
		if(d[e[i].u] == 0 || d[e[i].v] == 0)
		{
			sum += e[i].w;
			d[e[i].u] = 1;
			d[e[i].v] = 1;
			p[u][v] = p[v][u] = e[i].w;
		}
	}
	cout << sum << endl;
	//no village +16pt
	return 0;
}
