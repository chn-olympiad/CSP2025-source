#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,a[11],aw[10001],tot,f[10001],ans,cnt,vis[11];
struct edge
{
	int u,v,w;
	int f;
}e[1000001];
void add(int u,int v,int w,int f)
{
	tot++;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].u=u;
	e[tot].f=f;
	vis[f]=1;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int find(int x)
{
	while(x!=f[x])
	{
		x=f[x];
	}
	return f[x];
}
void kruskal()
{
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u;
		int v=e[i].v;
		u=find(u);
		v=find(v);
		if(u==v)
		{
			continue;
		}
		else
		{
			if(e[i].f&&vis[e[i].f]==0)
			{
				ans-=a[e[i].f];
			}
			else
			{
				vis[e[i].f]=0;
			}
			ans+=e[i].w;
			u=f[v];
			cnt++;
			if(cnt==n-1)
			{
				return;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w,0);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			cin>>aw[j];
		}
		for(int j=1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				add(j,k,aw[j]+aw[k]+a[i],i);
				m++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	kruskal();
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
