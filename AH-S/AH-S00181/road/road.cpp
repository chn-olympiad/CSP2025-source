#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e4+1;
int n,m,k;
LL ans=LLONG_MAX;
int mp[MAXN][MAXN];
bool vis[MAXN];
int c[MAXN],a[11][MAXN];
int u,v,w;
bool fa=1,f[11];
map<string,LL>jyh;
LL ww;
bool changed;
void dfs(int t,LL cnt,int ts)
{
	if(cnt>=ans) return ;
	if(ts>=n)
	{
		ans=min(ans,cnt);
		return ;
	}
	vis[t]=1;
	for(int i=1;i<=n;i++)
	{
		if(mp[t][i]!=-1)
		{
			if(!vis[i]) dfs(i,cnt+mp[t][i],ts+1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		for(int j=1;j<=k;j++)
		{
			ww=0;
			changed=0;
			if(!f[j])
			{
				ww+=c[j];
				f[j]=1;
				changed=1;
			}
			dfs(i,cnt+ww+a[j][t]+a[j][i],ts+1);
			if(changed) f[j]=0;	
		}
	}
	vis[t]=0;
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mp[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) fa=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]) fa=0;
		}
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
