#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N =1e4+5;

int n,m,k,dis[N],a[N],ans,c,w;
bool vis[N],yon[N];

vector<PII> g[N];

void dij(int x)
{
	priority_queue<PII,vector<PII>,greater<PII> > q;
	memset(dis,0x3f,sizeof dis);
	dis[x]=0;
	q.push({dis[x],x});
	while(q.size())
	{
		auto t = q.top();
		q.pop();
		int u = t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto tt:g[u])
		{
			int v=tt.first,w=tt.second;
			if(dis[v]>dis[u]+w)
			{
				
				dis[v]=dis[u]+w;
				ans=dis[v];
				//cout<<ans<<" "<<endl;
				if(yon[u]==1)
				{
					ans-=yon[u];
					
				}
				//cout<<ans<<" "<<endl;
				yon[u]=1;
				
				q.push({dis[v],v});
			}
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		if(k>0)
		{
			for(int i=m+1;i<=m+k;i++)
			{
				scanf("%d",&c);
				for(int j=1;j<=n;j++)
				{
					scanf("%d",&a[j]);
					g[i].push_back({j,a[j]});
					g[j].push_back({i,a[j]});
				}
			}
		}
	dij(1);
	printf("%d",ans);
	
	return 0;
}
