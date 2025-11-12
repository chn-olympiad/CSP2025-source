#include<bits/stdc++.h>
using namespace std;
int n,m,k,maxn,s,fl;
bool f[100010];
struct fun{int u,v;};
vector<fun> g[100010];
vector<int> d[100010];
void dfs(int x,int y,int fa)
{
	f[x]=1;
	for(int i=0;i<d[x].size();i++)
	{
		if(d[x][i]==y&&fa!=y)
		{
			fl=1;
			return ;
		}
		if(!f[d[x][i]]) dfs(d[x][i],y,x);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[w].push_back({u,v});
		maxn=max(maxn,w);
	}
	for(int i=1,c;i<=k;i++)
	{
		cin>>c;
		for(int j=1,t;j<=n;j++)
		{
			g[t].push_back({j,i+n});
			maxn=max(maxn,t);
		}
	}
	for(int i=0;i<=maxn;i++)
	{
		for(int k=0;k<g[i].size();k++)
		{
			fun j=g[i][k];
			d[j.v].push_back(j.u);
			d[j.u].push_back(j.v);
			fl=0;
			memset(f,0,sizeof(f));
			dfs(j.v,j.v,0);
			if(fl==0) s+=i;
			else
			{
				swap(d[j.v][d[j.v].size()-1],d[j.v][0]);
				d[j.v].pop_back();
				swap(d[j.u][d[j.u].size()-1],d[j.u][0]);
				d[j.u].pop_back();
			}
		}
	}
	cout<<s;
	return 0;
}
