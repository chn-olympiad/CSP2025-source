#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,K=12,NK=1e4+15,M=1e6+5;
int fa[NK],sz[NK];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct EDGE
{
	int u,v,w;
	bool operator<(const EDGE &b)const
	{
		return w<b.w;
	}
}E[M];
pair<int,int> a[K][N];
int c[K];
int n,m,k;

vector<int> p;
long long ans=LONG_LONG_MAX;
void dfs(int x)
{
	if(x==k+1)
	{
		long long sum=0;
		for(int x:p)sum+=c[x];
		int j[p.size()];
		for(int i=0;i<p.size();i++)j[i]=1;
		for(int i=1;i<=n+p.size();i++)fa[i]=i,sz[i]=1;
		for(int i=1,cnt=1;cnt<n+p.size();)
		{
			int mn=INT_MAX,id=-2;
			if(i<=m)mn=E[i].w,id=-1;
			for(int k=0;k<p.size();k++)if(j[k]<=n&&a[p[k]][j[k]].first<mn)mn=a[p[k]][j[k]].first,id=k;
			int u,v;
			if(id==-1)u=E[i].u,v=E[i].v,i++;
			else u=n+id+1,v=a[p[id]][j[id]].second,j[id]++;
			int U=find(u),V=find(v);
			if(U==V)continue;
			cnt++;
			if(sz[U]>sz[V])swap(U,V);
			fa[U]=V;
			sz[V]+=sz[U];
			sum+=mn;
			if(sum>=ans)break;
		}
		ans=min(ans,sum);
		return;
	}
	p.push_back(x);
	dfs(x+1);
	p.pop_back();
	dfs(x+1);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);
	}
	sort(E+1,E+m+1);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j].first),a[i][j].second=j;
		sort(a[i]+1,a[i]+n+1);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
