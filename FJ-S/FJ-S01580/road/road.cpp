#include <bits/stdc++.h>
using namespace std;

struct rooad
{
	long long u,v,w;
} rd[1000006];
long long n,m,k,c[1000006],a[15][10005],ans=0;
bool fxd[10001][10001];

bool cmp(rooad x1,rooad x2)
{
	return x1.w<x2.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) cin>>rd[i].u>>rd[i].v>>rd[i].w;
	for (int j=1;j<=k;j++)
	{
		cin>>c[j];
		for (int i=1;i<=m;i++) cin>>a[j][i];
	}
	
	sort(rd+1,rd+1+n,cmp);
	for (int i=1;i<=m;i++)
	{
		long long mn=min(rd[i].u,rd[i].v),mx=max(rd[i].u,rd[i].v);
		if (fxd[mn][mx]) continue;
		ans+=rd[i].w;fxd[mn][mx]=1;
	}
	
	cout<<ans;

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
