#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int fr,to,w,is;
}e[10100010];
int n,m,k,fa[10020],cnt,d[20];
bool use[10020];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void un(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y) fa[x]=y;
}
int js(int x)
{
	if(e[e[x].fr].is) return (e[e[x].to].is==1?0:1);
	if(use[e[x].fr])
	{
		return 1;
	}
	if(use[e[x].to]) return 1;
	return 2;
}
void kruskal()
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int sum=0,p=0;
	for(int i=1;i<=cnt;i++)
	{
		if(find(e[i].fr)!=find(e[i].to))
		{
			un(e[i].fr,e[i].to);
			p+=js(i);
			sum+=e[i].w-((e[i].is&&!use[e[i].fr])?d[e[i].fr-n]:0);
			use[e[i].fr]=use[e[i].to]=1;
		}
		if(p==n-1) break;
	}
	cout<<sum;
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].fr>>e[i].to>>e[i].w;
	}
	cnt=m;
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		d[i]=x;
		for(int j=1;j<=n;j++)
		{
			int p;
			cin>>p;
			e[++cnt]={n+i,j,p+x,1}; 
		}
	}
	sort(e+1,e+cnt+1,cmp);
	kruskal();
	return 0;
}
