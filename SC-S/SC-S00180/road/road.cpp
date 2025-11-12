/*
16+32+8+8
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+50,M=2e6;
int n,m,k,tot;
int f[N];
long long ans;
bool flag[N];
long long c[N],a[20][N];
struct Edge
{
	int from,to;
	long long v;
}edge[M],nedge[M];
bool check()
{
	for(int j=1;j<=n;j++)
		if(c[j]!=0) return 0;
	return 1;
}
bool cmp(Edge i,Edge j)
{
	return i.v<j.v;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void work(long long st_v)
{
	long long res=0,cnt=0;
	sort(edge+1,edge+tot+1,cmp);
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=tot;i++)
	{
		int fx=find(edge[i].from);
		int fy=find(edge[i].to);
		if(fx==fy) continue;
		res+=edge[i].v,f[fx]=fy;
		cnt++;
	}
	ans=min(ans,res+st_v);
}
void dfs(int x,long long sum)
{
	if(sum>ans) return;
	if(x==k+1)
	{
		for(int i=1;i<=m;i++)
			edge[i]=nedge[i];
		tot=m;
		for(int i=1;i<=k;i++)
			if(flag[i])
				for(int j=1;j<=n;j++)
					edge[++tot]={n+i,j,a[i][j]};
		work(sum);
		return;
	}
	flag[x]=1,dfs(x+1,sum+c[x]),flag[x]=0,dfs(x+1,sum);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		long long v;
		scanf("%d%d%lld",&x,&y,&v);
		nedge[i]={x,y,v},edge[i]={x,y,v};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	if(k==0||check())
	{
		tot=m,ans=1e18+7;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				edge[++tot]={n+i,j,a[i][j]};
		work(0),printf("%lld\n",ans);
		return 0;
	}
	ans=1e18+7,dfs(1,0LL),printf("%lld\n",ans);
	return 0;
}