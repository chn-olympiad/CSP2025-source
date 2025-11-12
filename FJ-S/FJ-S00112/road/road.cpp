#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10,M=1e6+10;
int n,m,k,now,cnt[2*N],fa[2*N],sp[2*N],vis[2*N];
ll ans,sw[2*N],c[20],a[20][N];
struct edge{int u,v;ll w;}e[M+2*N];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++)
			e[++m]=(edge){j,n+i,c[i]+a[i][j]};
		//for(int j=1;j<=n;j++)
		//	e[++m]=(edge){n+i,j,c[i]+a[i][j]};
	}
	sort(e+1,e+1+m,cmp);
//	for(int i=1;i<=m;i++)
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v))continue;
		//cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
		fa[find(u)]=find(v);
		if(u<=n&&v<=n)now++,ans+=e[i].w,fa[find(u)]=find(v);
		else if(vis[v]==0)vis[v]++,sp[v]=u,sw[v]=e[i].w;
		else if(vis[v]==1)vis[v]++,now++,fa[find(sp[v])]=find(v),ans+=sw[v];
		if(v>n&&vis[v]>1)now++,ans+=e[i].w-c[v-n],fa[find(u)]=find(v);
	}
	cout<<ans;
	return 0;
}
