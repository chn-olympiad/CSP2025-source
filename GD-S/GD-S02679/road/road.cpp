#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
const int INF = 0x3f3f3f3f;
int n,m,k,ans;
struct node
{
	int v,w;
};
vector<node> vc[N];
int c[N];
priority_queue<pair<int,int> > q;
int dis[N];
bool vis[N];
bool cg[N];
void pri()
{
	memset(dis,INF,sizeof(dis));
	dis[1]=0;
	for(int i=0;i<vc[1].size();i++)
	{
		int v = vc[1][i].v;
		int w = vc[1][i].w;
		if(v<=n) 
		{
			dis[v] = w;
			q.push(make_pair(-dis[v],v));
		}
		else 
		{
			q.push(make_pair(-w-c[v],v));
		}
	}
	//cout<<endl;
	vis[1] = 1;
	while(!q.empty())
	{
		int cw = q.top().first;
		int u = q.top().second;
		//cout<<-w<<" "<<u<<endl;
		q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(int i=0;i<vc[u].size();i++)
		{
			int v = vc[u][i].v;
			int w = vc[u][i].w;
			if(v<=n)
			{
				if(u>n&&!cg[u])
				{
					if(!vis[v]&&dis[v]>=w+c[u])
					{
						dis[v] = w;
						ans+=c[u];
						cg[u]=1;
						dis[u] = -cw-c[u];
						//cout<<dis[u]<<endl;
						q.push(make_pair(-dis[v],v));
					}
				}
				else
				{
					if(!vis[v]&&dis[v]>=w)
					{
						dis[v] = w;
						q.push(make_pair(-dis[v],v));
					}
				}
			}
			else
			{
				if(!vis[v]&&dis[v]>=w+c[v])
				{
					q.push(make_pair(-w-c[v],v));
				}
			}
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		vc[u].push_back(node{v,w});
		vc[v].push_back(node{u,w});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[n+i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%lld",&x);
			vc[n+i].push_back(node{j,x});
			vc[j].push_back(node{n+i,x});
		}
	}
	//cout<<endl;
	pri();
	for(int i=1;i<=n+k;i++)
	{
		if(i<=n) 
		{
			ans+=dis[i];
			//cout<<i<<endl;
		}
		else if(cg[i]) 
		{
			ans+=dis[i];
			//cout<<"a"<<i<<endl;
		}

	}
	cout<<ans;
}

