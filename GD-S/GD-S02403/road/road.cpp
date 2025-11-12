#include<bits/stdc++.h>
using namespace std;
const int N=3e6,N2=2e6;
long long n,m,k,cnt,f[N],ans1,ans2,a[N];
long long bz[N2],bz2[N2],w,head[N],x[11][N];
int jl2[N2],cnt2,sum,u,v;
map<int,map<int,int> > jl;
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void xg(int x,int y)
{
	f[f[x]]=f[y];
}
struct O{
	long long u,v,w,next;
}l[N],l2[N];
void add(int u,int v,long long w)
{
	++cnt;
	l[cnt].u=u;
	l2[cnt].u=u;
	l[cnt].v=v;
	l2[cnt].v=v;
	l[cnt].w=w;
	l2[cnt].w=w;
	l[cnt].next=head[u];
	head[u]=cnt;
}
bool cmp(O a,O b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
//	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
	}sort(l2+1,l2+cnt+1,cmp);
	
	for(int i=1;i<=cnt;i++)
	{
		int u=l2[i].u,v=l2[i].v;
		if(find(u)!=find(v))
		{
			xg(u,v),ans1+=l[i].w;
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i+n];
		f[i+n]=i+n;
		for(int j=1;j<=n;j++)
		{
			cin>>x[i][j];
			add(i+n,j,a[i+n]+x[i][j]);
		}
	}
	sort(l2+1,l2+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int u=l2[i].u,v=l2[i].v;
		if(find(u)!=find(v))
		{
			xg(u,v),ans2+=l2[i].w;
			if(u>n&&bz[u])ans2-=a[u];
			if(v>n&&bz[v])ans2-=a[v];
			bz[u]=bz[v]=1;jl[u][v]=1;jl[v][u]=1;
		}
	}
	for(int i=1;i<=k;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(jl[i+n][j])sum++;
		}
		if(sum<2)
		{
			ans2-=a[i+n];
			for(int j=1;j<=n;j++)
			{
				if(jl[i+n][j])ans2-=x[i][j];
			}
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}
