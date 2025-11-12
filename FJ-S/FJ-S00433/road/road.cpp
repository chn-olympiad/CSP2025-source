#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110005;
const int M=2000005;
struct node
{
	int u,v,d;
	ll w;
}e[M];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
ll ans,a[N][11],c[N];
int f[N],siz[N];
bool vis[M];
int F(int x)
{
	if(f[x]==x) return x;
	f[x]=F(f[x]);
	return f[x];
}
bool Merge(int x,int y)
{
	x=F(x),y=F(y);
	if(x==y) return 0;
	if(siz[x]<siz[y]) f[x]=y,siz[y]+=siz[x];
	else f[y]=x,siz[x]+=siz[y];
	return 1;
}
int n,m,k;
void Clean()
{
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
		siz[i]=1;
	}
}
ll Solve(int h)
{
	ll ret=0;
	vis[0]=1;
	int sum=0;
	for(int i=0;i<k;i++)
	{
		if((h>>i)&1) vis[i+1]=1;
		else vis[i+1]=0;
	}
	for(int i=1;i<=k;i++)
	{
		ret+=vis[i]*c[i];
		sum-=vis[i];
	}
	Clean();
	for(int i=1;i<=m;i++)
	{
		if(vis[e[i].d]==0) continue;
		bool v=Merge(e[i].u,e[i].v);
		ret+=v*e[i].w;
		sum+=v;
		if(sum==n||ret>=ans) break;
	}
	return ret;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[j][i];
	}
	sort(e+1,e+m+1,cmp);
	Clean();
	for(int i=1;i<=m;i++)
	{
		vis[i]=Merge(e[i].u,e[i].v);
		ans+=vis[i]*e[i].w;
	}
	for(int i=1,j=m;i<=j;i++)
	{
		if(i==1) m=0;
		if(vis[i]==1) m++,e[m]=e[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			m++;
			e[m].d=i;
			e[m].u=n+i;
			e[m].v=j;
			e[m].w=a[j][i];
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int h=1;h<(1<<k);h++)
	{
		ans=min(ans,Solve(h));
	}
	cout<<ans;
	return 0;
}
