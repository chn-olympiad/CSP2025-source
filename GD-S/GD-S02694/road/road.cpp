#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

struct edge_t
{
	int u,v;
	long long w;
}edge[10000010];

int n,m,k,len,f[10010];

inline void insert(int u,int v,long long w)
{
	edge[len].u=u;
	edge[len].v=v;
	edge[len].w=w;
	len++;
}

inline bool cmp(edge_t a,edge_t b)
{
	return a.w<b.w;
}

inline int find(int id)
{
	if(f[id]==id)return id;
	return f[id]=find(f[id]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int u,v;
		long long w;
		cin>>u>>v>>w;
		insert(u,v,w);
	}
	for(int i=0;i<k;i++)
	{
		long long c,a[10010];
		cin>>c;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)insert(i,j,a[i]+a[j]+c);
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=0;
	long long ans=0;
	sort(edge,edge+len,cmp);
	for(int i=0;cnt<n-1;i++)
	{
		if(find(edge[i].u)==find(edge[i].v))continue;
		f[find(edge[i].u)]=find(edge[i].v);
		cnt++;
		ans+=edge[i].w;
	}
	cout<<ans;
}
