#include<bits/stdc++.h>
using namespace std;
struct FSI
{
	template<typename T>
	FSI& operator >> (T &res)
	{
		res=0;T f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
		while(isdigit(ch)){res=res*10+(ch-'0');ch=getchar();}
		res*=f;
		return *this;
	}
}scan;

int n,m,k;
int c[20],a[20][10010],d[20];

struct Road
{
	int u,v,w;
};
Road r1[1000010],r2[100010];
bool cmp(Road x,Road y) {return x.w<y.w;}

int pa[10100],siz[10100];
int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}

long long ans=1e18;
void work()
{
	int cnt=0;
	long long sum=0;
	int tot=0;
	for(int i=1;i<=k;i++)
	{
		if(!d[i]) continue;
		tot++;
		sum+=c[i];
		if(sum>=ans) return ;
		for(int j=1;j<=n;j++) r2[tot*n-n+j].u=n+tot,r2[tot*n-n+j].v=j,r2[tot*n-n+j].w=a[i][j];
	}
	sort(r2+1,r2+tot*n+1,cmp);
	for(int i=1;i<=n+tot;i++) pa[i]=i,siz[i]=1;
	int now=n*tot+m,t1=1,t2=1;
	while(now--)
	{
		if(r1[t1].w<r2[t2].w||t2>=tot*n)
		{
			int u=find(r1[t1].u),v=find(r1[t1].v),w=r1[t1].w;
			t1++;
			if(u==v) continue;
			if(siz[u]>siz[v]) swap(u,v);
			pa[u]=v;siz[v]+=siz[u];
			sum+=w; cnt++;
		}
		else
		{
			int u=find(r2[t2].u),v=find(r2[t2].v),w=r2[t2].w;
			t2++;
			if(u==v) continue;
			if(siz[u]>siz[v]) swap(u,v);
			pa[u]=v;siz[v]+=siz[u];
			sum+=w; cnt++;
		}
		if(cnt==n+tot-1)
		{
			ans=sum;
			return ;
		}
	}
}

void dfs(int x)
{
	if(x==k+1)
	{
		work();
		return ;
	}
	dfs(x+1);
	d[x]=1;
	dfs(x+1);
	d[x]=0;
	return ;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scan>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scan>>u>>v>>w;
		r1[i].u=u;r1[i].v=v;r1[i].w=w;
	}
	sort(r1+1,r1+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		scan>>c[i];
		for(int j=1;j<=n;j++) scan>>a[i][j];
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
