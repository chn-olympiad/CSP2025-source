#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
#define llt long long
int n,m,k,dep[N];
vector<pair<llt,int> >g[N];
llt c[15],a[15][N],ans,res,gg[N][N],ggg[N][N];
bool vis[N],in[N],cs[15];
priority_queue<pair<llt,pair<int,int> > >q;
#define val first
#define uu second.first
#define vv second.second
void dfs2(int u,int pre)
{
	for(auto v:g[u])
	{
		if(v.second==pre) continue;
		if(!vis[v.second])
		{
			q.push({v.first,{u,v.second}});
//			cout<<1<<"  "<<u<<' '<<v.second<<endl;
			ans+=v.first;
			in[v.second]=1;
			vis[v.second]=1;
			dep[v.second]=dep[u]+1;
			dfs2(v.second,u);
			in[v.second]=0;
		}
		else if(dep[v.second]>dep[u]) continue;
		else
		{
//			cout<<2<<"  "<<u<<' '<<v.second<<"   ";
			q.push({v.first,{u,v.second}});
			ans+=v.first;
			while(!in[q.top().uu]||!in[q.top().vv]) q.pop();
//			cout<<q.top().uu<<' '<<q.top().vv<<endl;
			ans-=q.top().val;
			q.pop();
		}
	}
}
void dfs1(int u,int pre)
{
	for(int v=1;v<=n;v++)if(gg[u][v]!=4557430888798830399)
	{
		if(v==pre) continue;
		if(!vis[v])
		{
			q.push({gg[u][v],{u,v}});
//			cout<<1<<"  "<<u<<' '<<v.second<<endl;
			res+=gg[u][v];
			in[v]=1;
			vis[v]=1;
			dep[v]=dep[u]+1;
			dfs2(v,u);
			in[v]=0;
		}
		else if(dep[v]>dep[u]) continue;
		else
		{
//			cout<<2<<"  "<<u<<' '<<v.second<<"   ";
			q.push({gg[u][v],{u,v}});
			res+=gg[u][v];
			while(!in[q.top().uu]||!in[q.top().vv]) q.pop();
//			cout<<q.top().uu<<' '<<q.top().vv<<endl;
			res-=q.top().val;
			q.pop();
		}
	}
}
inline void solve()
{
	memcpy(gg,ggg,sizeof gg);
	res=0;
	for(int i=1;i<=k;i++)if(cs[i])
	{
		res+=c[i];
		for(int u=1;u<=n;u++)for(int v=u+1;v<=n;v++)
			gg[u][v]=gg[v][u]=min(gg[v][u],a[i][u]+a[i][v]);
	}
//	for(int i=1;i<=n;i++,cout<<endl)for(int j=1;j<=n;j++) cout<<gg[i][j]<<' ';
	memset(vis,0,sizeof vis);
	memset(in,0,sizeof in);
	vis[1]=1;
	in[1]=1;
	dfs1(1,0);
//	for(int i=1;i<=k;i++) cout<<cs[i];
//	cout<<' '<<res<<endl;
	ans=min(ans,res);
}
void dfs0(int u)
{
	if(u>k){solve();return;}
	cs[u]=1;dfs0(u+1);
	cs[u]=0;dfs0(u+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0)
	{
		int u,v;llt w;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%lld",&u,&v,&w);
			g[u].push_back({w,v});
			g[v].push_back({w,u});
		}
		for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
		while(!q.empty()) q.pop();
		vis[1]=1;
		in[1]=1;
		dfs2(1,0);
		printf("%lld",ans);
		return 0; 
	} 
	else
	{
		memset(ggg,0x3f,sizeof ggg);
		int u,v;llt w;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%lld",&u,&v,&w);
			ggg[u][v]=ggg[v][u]=min(ggg[v][u],w);
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&c[i]);
			for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
		}
		ans=LONG_LONG_MAX;
		dfs0(1);
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
