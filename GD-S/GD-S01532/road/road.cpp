#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,a[17][N+5],c[25],tot,f[N+20];
long long ans=1e18,nans;
struct node{
	int u,v,w;
}ned[M],G[M+11*N];
int getf(int x){return ((f[x]==x)?x:f[x]=getf(f[x]));}
void initG()
{
	nans=0;
	for(int i=1;i<=m;i++)G[i]=ned[i];
	for(int i=1;i<=n+15;i++)f[i]=i;
}
void upd(int u){for(int i=1;i<=n;i++)G[++m]={.u=u+n,.v=i,.w=a[u][i]};}
int cmp(node x,node y){return x.w<y.w;}
long long kruskal()
{
	int get_cnt=0;
	sort(G+1,G+m+1,cmp);
	for(int i=1;get_cnt<n-1;i++)
	{
		if(nans>=ans)break;
		int fu=getf(G[i].u),fv=getf(G[i].v);
		if(fu!=fv)f[fu]=fv,nans+=G[i].w,get_cnt++;
	}
	return nans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ned[i]={.u=u,.v=v,.w=w};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++)
	{
		int node_cnt=0;
		initG();
		for(int j=0;(1<<j)<=i;j++)if(i&(1<<j))
		{
			upd(j+1),nans+=c[j+1],node_cnt++;
			if(nans>=ans)break;
		}
		n+=node_cnt;
		if(nans<ans)ans=min(ans,kruskal());
		n-=node_cnt;
		m-=node_cnt*n;
	}
	cout<<ans;
	return 0;
}
