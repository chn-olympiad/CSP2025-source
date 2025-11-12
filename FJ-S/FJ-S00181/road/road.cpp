#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5,M=1e6+5,K=10+5;

struct node
{
	int u,v,w;
}nd[M];

struct Edge
{
	int a[N],c;
}e[K];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>nd[i].u>>nd[i].v>>nd[i].w;
		ans+=nd[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>e[i].c;
		for(int j=1;j<=n;j++)
		{
			cin>>e[i].a[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
