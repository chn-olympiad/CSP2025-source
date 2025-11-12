#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int fa[1000001],n,m,k,sum;
int a[1000001][11];
struct edge
{
	int u,v,w;
};
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
edge e[1000001];
int find_(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find_(fa[x]);
}
void krus()
{
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		edge t=e[i];
		int fu=find_(t.u),fv=find_(t.v);
		if(fu==fv)continue;
		fa[fu]=fv;
		++cnt;
		sum+=t.w;
		if(cnt==n-1)
			break;
	}
}
int dis[1001][1001],c[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1,u,v,w;i<=m;i++)
			cin>>u>>v>>w,e[i]=((edge){u,v,w});
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++)
			fa[i]=i;
		krus();
		cout<<sum;
		return 0;
	}
	bool flg=1;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,dis[u][v]=dis[v][u]=w;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			if(j==0)cin>>c[i],flg=flg&&(c[i]==0);
			else cin>>a[i][j];
		}
	if(flg)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=INT_MAX;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				if(i!=k)
					for(int j=1;j<=n;j++)
						if(dis[i][j]>dis[i][k]+dis[k][j])
							dis[i][j]=dis[i][k]+dis[k][j];
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
				for(int l=1;l<=n;l++)
					if(dis[j][l]<a[i][j]+a[i][l])
						dis[j][l]=a[i][j]+a[i][l];
		}	
		for(int i=1;i<=n;i++)	
			for(int j=1;j<=n;j++)
				if(dis[i][j]!=INT_MAX)e[++cnt]=((edge){i,j,dis[i][j]});
		sort(e+1,e+cnt+1,cmp);
		krus();
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
