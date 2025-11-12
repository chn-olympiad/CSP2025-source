#include<bits/stdc++.h>
#define ll long long
#define db double
#define int ll//#
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int inf=2e9;
const db eps=1e-7;
int n,m,k,c[15],dis[10025],minn[10025];
int fa[10025],cv[15][10005],ans,fa2[10025];
bool vis[10025],vis2[10005];
vector<pii>e[10020];
vector<pair<int,pii>>rd;
map<pii,int>r;
void p_e(int u,int v,int w)
{
	e[u].pb({v,w});
	e[v].pb({u,w});
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void uni(int u,int v)
{
	fa[find(u)]=find(v);
}
bool yn[13];
void dij(int s)
{
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		pii tp=pq.top();
		int u=tp.se;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto fir:e[u])
		{
			int v=fir.fi,w=fir.se;
			if((v>n&&yn[v-n]==1))continue;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				fa[v]=u;
				pq.push({dis[v],v});
			}
		}
	}
}

void dfs(int u)
{
	if(u>k)
	{
		for(int i=1;i<=n+k;i++)dis[i]=inf;
		for(int i=1;i<=n+k;i++)vis2[i]=0;
		for(int i=1;i<=n+k;i++)vis[i]=0;
		for(int i=1;i<=n+k;i++)fa[i]=0;
		dij(1);
		int ans2=0;
		vis2[1]=1;
		for(int i=2;i<=n;i++)
		{
			int s=i;
			while(!vis2[s])
			{
//				cerr<<s<<" ";
				int u=s,v=fa[s];
				if(u>v)swap(u,v);
//				cerr<<u<<"&"<<v<<"&"<<r[{u,v}]<<" ";
				ans2+=r[{u,v}];
				vis2[s]=1;
				s=fa[s];
//				cerr<<s<<"X"<<vis2[s]<<" ";
			}
			cerr<<dis[i];
//			cerr<<"|";
		}
//		cerr<<"//";
		for(int i=1;i<=k;i++)
		{
			if(!yn[i])
			{
				ans2+=c[i];
//				cerr<<i<<" ";
			}
		}
//		cerr<<ans2<<"\n";
		ans=min(ans,ans2);
		return ;
	}
	dfs(u+1);
	yn[u]=1;
	dfs(u+1);
	yn[u]=0;
}
void bfs(int s)
{
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		pii tp=pq.top();
		int u=tp.se;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto fir:e[u])
		{
			int v=fir.fi,w=fir.se;
			if(find(u)==find(v))continue;
			if(dis[v]>dis[u]+w)
			{
				uni(u,v);
				dis[v]=dis[u]+w;
				fa2[v]=u;
				pq.push({dis[v],v});
			}
		}
	}
	
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)minn[i]=inf;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		r[{u,v}]=w;
//		rd.pb({u,{v,w}});
		p_e(u,v,w);
		minn[u]=min(minn[u],w);
		minn[v]=min(minn[v],w);
	}
	
	for(int i=1;i<=n+k;i++)dis[i]=inf,fa[i]=i;
	bfs(1);
	if(k==0)
	{
		vis2[1]=1;
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			int s=i;
			while(!vis2[s])
			{
//				cerr<<s<<" ";
				int u=s,v=fa[s];
				if(u>v)swap(u,v);
				ans+=r[{u,v}];
				vis2[s]=1;
				s=fa2[s];
			}
		}
		cout<<ans;
		return 0;
	}
	bool spe=true;
	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)spe=false;
		for(int j=1;j<=n;j++)
		{
			cin>>cv[i][j];
			if(cv[i][j]!=0)spe=false;
		}
	}
	
//	cerr<<"\n";
	
	
	if(spe)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int u=i+n,v=j,w=cv[i][j];
				if(u>v)swap(u,v);
				r[{u,v}]=w;
				p_e(u,v,w);
			}
		}
		for(int i=1;i<=n+k;i++)dis[i]=inf;
		dij(1);
		vis2[1]=1;
		for(int i=2;i<=n;i++)
		{
			int s=i;
			while(!vis2[s])
			{
//				cerr<<s<<" ";
				int u=s,v=fa[s];
				if(u>v)swap(u,v);
				ans+=r[{u,v}];
				vis2[s]=1;
				s=fa[s];
			}
		}
		return 0;
	}
	vis2[1]=1;
	for(int i=2;i<=n;i++)
	{
		int s=i;
		while(!vis2[s])
		{
			cerr<<s<<" ";
			int u=s,v=fa[s];
			if(u>v)swap(u,v);
			ans+=r[{u,v}];
			vis2[s]=1;
			s=fa[s];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
5 8 0
1 5 1
1 4 6
2 4 5
2 5 8
2 3 7
3 4 4
3 5 2
4 5 4
*/
