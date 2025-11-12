#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct node{
	int u,v,w;
}r[M];
int fa[N],c[20],a[11][N],f[N][N];
int n,m,k,tot,cnt;
long long sum;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)return fa[x];
	return find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)f[i][j]=INT_MAX;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		f[min(u,v)][max(u,v)]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		for(int j=1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				f[j][k]=min(f[j][k],a[i][j]+a[i][k]);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			r[++tot].u=i;
			r[tot].v=j;
			r[tot].w=f[i][j];
		}
	}
	sort(r+1,r+tot+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=tot;i++)
	{
		if(find(r[i].u)!=find(r[i].v))
		{
			fa[find(r[i].u)]=find(r[i].v);
			sum+=r[i].w;
			if(cnt==n-1)break;
		}
	}
	cout<<sum;
	return 0;
}
