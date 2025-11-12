#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v,w;
	bool operator<(edge a)const{return w<a.w;}	
}e[1100001],ne[1100001],a[11][10001];
int n,m,k,fa[10011],c[11];
bool vis[11];
long long ans=1e18;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
double ssst;
void work(long long nc)
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
	long long res=0;
	int tot=0;
	vector<int>px{};
	for(int i=1;i<=k;i++)
	{
		if(!vis[i])continue;
		++tot;
		for(int j=1;j<=n;j++)e[m+(tot-1)*n+j]=a[i][j];
	}
	sort(e+m+1,e+m+n*tot+1);
	merge(e+1,e+m+1,e+m+1,e+m+n*tot+1,ne+1);
	for(int i=1,cnt=0;i<=m+tot*n;i++)
	{
		if(find(ne[i].u)==find(ne[i].v))continue;
		if((res+=ne[i].w)+nc>=ans)return;
		fa[find(ne[i].u)]=find(ne[i].v);
		if((++cnt)==n+tot-1)break;
		if((clock()-ssst)/CLOCKS_PER_SEC>0.93)return;
	}
	ans=res+nc;
}
void dfs(int st,long long nc)
{
	if((clock()-ssst)/CLOCKS_PER_SEC>0.93)return;
	if(st>k)return work(nc);
	vis[st]=1;
	dfs(st+1,nc+c[st]);
	vis[st]=0;
	dfs(st+1,nc);
}
int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
signed main()
{
	ssst=clock();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read(); 
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			a[i][j].u=n+i;
			a[i][j].v=j;
			a[i][j].w=read();
		}
		sort(a[i]+1,a[i]+n+1);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
