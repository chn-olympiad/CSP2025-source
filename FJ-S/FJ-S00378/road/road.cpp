#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int u,v,w;
}edge[1000010];
struct node1
{
	int u,w;
};
bool cmp(node a,node b)
{
	return a.w<b.w;
}
bool cmp1(node1 a,node1 b)
{
	return a.w<b.w;
}
int fa[10100],c[15],p[15],st[15],tot;
node1 v[15][10010];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
long long mntree(int n,int m)
{
	int cnt=0;
	long long res=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv,res+=w,edge[++cnt]=edge[i];
		if(cnt==n-1)break;
	}
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>v[i][j].w,v[i][j].u=j;
		sort(v[i]+1,v[i]+1+n,cmp1);
	}
	sort(edge+1,edge+1+m,cmp);
	ans=mntree(n,m);
//	cout<<"start:\n";
//	cout<<ans<<'\n';
//	for(int i=1;i<n;i++)cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<'\n';
//	cout<<'\n';
	for(int i=1;i<(1<<k);i++)
	{
		long long res=0;
		int cnt=0,pp=1;
		tot=0;
		for(int j=1;j<=k;j++)
			if(i&(1<<j-1))res+=c[j],cnt++,p[j]=1,st[++tot]=j;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<n+cnt;j++)
		{
			int minn=0x7fffffff,pos;
			for(int z=1;z<=tot;z++)
			{
//				while(p[st[z]]<=n&&find(n+st[z])==find(v[st[z]][p[st[z]]].u))p[st[z]]++;
				if(p[st[z]]<=n&&minn>v[st[z]][p[st[z]]].w)minn=v[st[z]][p[st[z]]].w,pos=st[z];
			}
			
//			while(pp<n&&find(edge[pp].u)==find(edge[pp].v))pp++;
			
			if(pp<n&&minn>edge[pp].w)
			{
				int fu=find(edge[pp].u),fv=find(edge[pp].v);
				if(fu==fv)
				{
					pp++,j--;
					continue;
				}
				res+=edge[pp].w;
				fa[fu]=fv,pp++;
			}
			else
			{
//				if(p[pos]>n)exit(1);
				int fu=find(v[pos][p[pos]].u),fv=find(n+pos);
				if(fu==fv)
				{
					p[pos]++,j--;
					continue;
				}
				res+=minn;
				fa[fu]=fv,p[pos]++;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
