#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m,k,u,v,w;
int cnt=0;
int head[N],f[N],c[N],a[N][N];
bool vis[N];
struct Edge
{
	int v,w,nxt;
}edge[N*2];
struct node
{
	int u,val;
	bool operator < (const node &o) const
	{
		return val>o.val;
	}
};
void add(int u,int v,int w)
{
	cnt++;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) f[i]=0;
	f[s]=1;
	priority_queue<node>q;
	q.push({s,f[s]});
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].v,w=edge[i].w;
			if(vis[v]) continue;
			vis[i]=1;
			if(f[u]+w<f[v])
			{
				f[v]=f[u]+w;
				q.push({v,f[v]});
			}
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(c[i]<=n) add(c[i],j,a[i][j]);
			if(c[i]<=n) add(j,c[i],a[i][j]);
		}
	} 
	dij(1);
	cout<<f[n]<<"\n";
	return 0;
}