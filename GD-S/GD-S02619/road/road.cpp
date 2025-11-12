#include<bits/stdc++.h>
using namespace std;

struct edge{
	int from,to,w;
};

bool cmp(edge a,edge b)
{
	return a.w<b.w;
}

vector<edge> g;

int c[11],a[11][10001];

int n,m,k,ans=2147483647,fa[10001];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g.push_back({x,y,z});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		int tans=c[i];
		for(int j=1;j<=n;j++)
			for(int j2=j+1;j2<=n;j2++)
			{
				g.push_back({j,j2,a[i][j]+a[i][j2]});
			}
		sort(g.begin(),g.end(),cmp);
		for(edge u:g)
		{
			int x=u.from,y=u.to,w=u.w;
			int fx=find(x),fy=find(y);
			if(fx!=fy)
			{
				fa[fy]=fx;
				tans+=w;
			}
		}
		ans=min(ans,tans);
	}
	cout<<ans<<"\n";

}

