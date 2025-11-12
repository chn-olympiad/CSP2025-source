#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
#define per(a,b,c) for(int a=(c);a>=(b);a--)
#define fc freopen("road.in","r",stdin),freopen("road.out","w",stdout);
#define debug(x) cout<<x<<'\n';
int n,m,k; 
const int M=2e6+10;
//枚举k跑最小生成树
const int N=1e4+10;
vector<pair<int,int>> E[N];
int e[11][N];
int dis[N];
bool vis[N];
bool ud[11];
int prim(int i)
{
	for(int i=1;i<=n;i++) dis[i]=1e9,vis[i]=0;
	int ans=0;
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int mv=1e9,mp=-1;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])
			{
				if(dis[j]<mv)
				{
					mp=j;
					mv=dis[j];
				}
			}
		}
		ans+=mv;
		vis[mp]=1;
		for(int s=0;s<E[mp].size();s++)
		{
			int to=E[mp][s].fi,w=E[mp][s].se;
			dis[to]=min(dis[to],w);
		}
		for(int t=0;t<k;t++)
		{
			if(!ud[t]) continue;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]) continue;
				dis[j]=min(dis[j],e[t][mp]+e[t][j]);
			}
		}
	}
	return ans;
}
void Luo_Saisei()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		E[u].emplace_back(v,w);
		E[v].emplace_back(u,w);
	}
	for(int i=0;i<k;i++) {
		cin>>e[i][0];
		for(int t=1;t<=n;t++) cin>>e[i][t];
	}
	int ans=1e18;
	for(int i=0;i<1<<k;i++)
	{
		int tmp=0;
		for(int j=0;j<k;j++) ud[j]=0;
		for(int j=0;j<k;j++) if(i>>j&1) tmp+=e[j][0],ud[j]=1;
		ans=min(ans,tmp+prim(i)); 
	}
	cout<<ans<<'\n';
}
signed main()
{
	fc;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) Luo_Saisei();
} 
