#include<bits/stdc++.h>
#define ll long long
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define fans(x) freopen(#x".ans","w",stdout)
const int N=2e4+7,M=1e6+7;
using namespace std;
int n,m,k,tot,c[17],a[17][N],siz[N];
ll ans;
struct Edge
{
	int u,v,w;
	bool operator<(const Edge&x)const{return w<x.w;}
}E[M],e[M],e1[M];
int fa[N];
void init(int n){for(int i = 1;i<= n;i++)fa[i]=i,siz[i]=1;}
int find(int x){return fa[x]=fa[x]==x?x:find(fa[x]);}
void uni(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(siz[x]<siz[y])fa[fx]=fy,siz[fy]+=siz[fx];
	else fa[fy]=fa[x],siz[fx]+=siz[fy];
}
void dfs(int x,ll sum)
{
	if(x==k+1)
	{
		for(int i = 1;i<= tot;i++)e1[i]=e[i];
		sort(e1+1,e1+tot+1);
		ll res=0;
		init(n+k);
		for(int i = 1;i<= tot;i++)
		{
			int u=e1[i].u,v=e1[i].v,w=e1[i].w;
			if(find(u)==find(v))continue;
			res+=w;
			uni(u,v);
		}
		ans=min(ans,res+sum);
		return;
	}
	for(int i = 1;i<= n;i++)
	{
		e[++tot]={n+x,i,a[x][i]};
	}
	dfs(x+1,sum+c[x]);
	tot-=n;
	dfs(x+1,sum);
}
signed main()
{
//	fin(road);
//	fout(road);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i<= m;i++)cin>>E[i].u>>E[i].v>>E[i].w;
	for(int i = 1;i<= k;i++)
	{
		cin>>c[i];
		for(int j = 1;j<= n;j++)cin>>a[i][j];
	}
	sort(E+1,E+m+1);
	init(n+k);
	for(int i = 1;i<= m;i++)
	{
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(find(u)==find(v))continue;
		e[++tot]=E[i],ans+=w;
		uni(u,v);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
