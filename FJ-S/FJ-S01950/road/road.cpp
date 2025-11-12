#include <bits/stdc++.h>
using namespace std;

int f[10025];
int c[15];

int Find(int x)
{
	if(x==f[x]) return x;
	return f[x]=Find(f[x]);
}

bool Union(int x,int y)
{
	int u=Find(x);
	int v=Find(y);
	if(u==v) return false;
	f[u]=v; return true; 
}

struct Edge{
	int u,v,w;
}e[1000005];

bool cmp(Edge a,Edge b)
{
	if(a.w<b.w) return true;
	return false;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;++i)
	{
		int w;
		cin>>c[i];
		for(int j=1;j<=n;++j)
		{
			cin>>w;
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;++i) f[i]=i;
	long long ans=0,cnt=0;
	for(int i=1;i<=m;++i)
	{
		if(Union(e[i].u,e[i].v))
		{
			ans+=e[i].w;
			if(++cnt==n-1)
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
