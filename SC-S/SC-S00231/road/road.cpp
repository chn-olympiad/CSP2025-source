#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
const int maxm=1000000;
int n,m,k,cnt,t,ans;
int head[10*maxn+10],dis[10*maxn+10],vis[10*maxn+10],a[10*maxn+10];
struct ndoe
{
	int next,to,w;
}e[10*maxn+10];
void add(int a,int b,int c)
{
	e[++cnt].next=head[a];
	e[cnt].to=b;
	e[cnt].w=c;
	head[a]=cnt;
}
stack<int> st;
void dijsktra(int x)
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,x));
	dis[x]=0;
	t=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		vis[x]=1;
		if(t==n)
		{
			cout<<x<<' ';
			ans=min(ans,dis[x]);
			cout<<ans<<"\n";
			break;
		}
		for(int i=head[x];i;i=e[i].next)
		{
			int y=e[i].to ,z=e[i].w;
			if(dis[x]+z<dis[y])
			{
				dis[y]=dis[x]+z;
			}
			if(!vis[y])
			{
				t++;
				vis[y]=1;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("roed.in","r",stdin);
	freopen("roed.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		int u;
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
		}
	}
	ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<"-->";
		dijsktra(i);
	}
	cout<<ans;
}
/*
4 4 2 
1 4 6
2 3 7
4 2 5
4 3 4
1 0 0 0 0 
100 0 0 0 0
*/