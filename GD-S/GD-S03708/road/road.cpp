#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e4+5,M=1e6+5;
int n,m,num;
int c[15];
int a[15][N];
int fa[N];
int sum,cnt;

int find(int x)
{
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}

struct edge
{
	int u,v,w;
}e[M];

bool cmp(edge a,edge b)
{
	return a.w<b.w;
}

void kruskal()
{
	int k=1;
	while(k<n)
	{
		edge t=e[++cnt];
		int u=t.u,v=t.v,w=t.w;
		u=find(u),v=find(v);
		cout<<u<<' '<<v<<'\n';
		if(u!=v)
		{
			sum+=w,++k;
			fa[u]=v;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>num;
	
	for(int i=1;i<=n;i++) fa[i]=i;
	
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
		
	for(int i=1;i<=num;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	
	sort(e+1,e+m+1,cmp);
	
	kruskal();
	
	cout<<sum;

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
