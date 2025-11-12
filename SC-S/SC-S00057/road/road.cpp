#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
struct node{
	int id,w;
};
int n,m,k,cnt,ans,f[10005],c[15],a[15][10005],mp[1005][1005];
struct line{
	int u,v,w;
}e[5000005];
int find(int i)
{
	if(f[i]==i) return f[i];
	return f[i]=find(f[i]);
}
bool cmp(line a,line b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		mp[u][v]=mp[v][u]=w;
		e[i].u=u;e[i].v=v;e[i].w=w;
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
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(mp[j][k]>c[i]+a[i][j]+a[i][k])
				e[++m].u=j,e[m].v=k,e[m].w=c[i]+a[i][j]+a[i][k];
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1) break;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int zx=find(f[u]),zy=find(f[v]);
		if(zx!=zy) {cnt++;f[zx]=zy;ans+=w;}
	}
	cout<<ans;
	return 0;
}