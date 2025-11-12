#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50,M=1e6+5,K=15;
int n,m,k,cnt;
long long c[K],p[N+K],vis[K],a[K][N];
long long ans;
struct node{
	int u,v,w;
	bool operator<(const node& t)const{
		return w<t.w;
	}
}e[M+K*N];
int find(int x)
{
	if(p[x]!=x)
	{
		p[x]=find(p[x]);
	}
	return p[x];
}
int main()
{
	//freopen("club2.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		for(int j=1;j<=k;j++)
		{
			if(c[j]+a[j][u]+a[j][v]<w)
			{
				e[i].w=c[j]+a[j][u]+a[j][v];
			}
		}
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)
		{
			continue;
		}
		p[fu]=fv;
		ans+=w;
	}
	cout<<ans;
	return 0;
}
