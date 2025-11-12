#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
	int u;
	int v;
	long long w;
}e[10000004];
struct country
{
	int num;
	int s;
	int cn;
	int road[1100006];
}c[12];
int cnt;
long long ans,g[10004][10];
int n,m,k,fa[10004];
bool vis[10004],r[1000006];
void add(int x,int y,int z)
{
	e[++cnt].u=x;
	e[cnt].v=y;
	e[cnt].w=z;
	return;
}
int ff(int x)
{
	if(x==fa[x]) return x;
	fa[x]=ff(fa[x]);
	return fa[x];
}
void he(int x,int y)
{
	fa[x]=ff(y);
	return;
} 
bool cmp(edge e1,edge e2)
{
	return e1.w<e2.w;
}
bool cmp2(country c1,country c2)
{
	return c1.s<c2.s;
}
void sl(int x)
{
	for(int i=1;i<=k;i++)
	{
		if(g[e[x].u][i]+g[e[x].v][i]<e[x].w)
		{
			c[i].s+=(g[e[x].u][i]+g[e[x].v][i])-e[x].w;
			//cout<<i<<":"<<c[i].s;
		}
	}
 } 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		//cout<<z<<" ";
		add(x,y,z); 
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i].s;
		for(int j=1;j<=n;j++) cin>>g[j][i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int kk=1;kk<=k;kk++)
			{
				add(i,j,g[i][kk]+g[j][kk]);
			}
		}
	}
	sort(e+1,e+1+m,cmp);
	int countt=0;
	for(int i=1;i<=m;i++) 
	{
		if(countt==(n-1)) break;
		x=e[i].u;
		y=e[i].v;
		z=e[i].w;
		if(!vis[x]||!vis[y]||ff(x)!=ff(y))
		{
			vis[x]=1;
			vis[y]=1;
			he(x,y);
			ans+=z;
			//cout<<z<<" ";
			//sl(i);
			countt+=1;
		 } 
	}
	//cout<<ans<<" ";
	sort(c+1,c+1+k,cmp2);
	/*for(int i=1;i<=k;i++)
	{
		if(c[i].s>=0) break;
		ans+=c[i].s;
		for(int j=1;j<=c[i].cn;j++) r[c[i].road[j]]=1;
		for(int j=i+1;j<=k;j++)
		{
			for(int kk=1;kk<=c[j].cn;kk++)
			{
				if(r[c[j].road[kk]])
				{
					c[j].s+=e[c[j].road[kk]].w-g[e[c[j].road[kk]].u][j]-g[e[c[j].road[kk]].v][j];
				}
			}
		}
		sort(c+1+i,c+1+m,cmp2);
	}*/
	cout<<ans;
	return 0;
} 
