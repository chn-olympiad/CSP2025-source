#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#define vpii vector<pair<int,int>>
using namespace std;
int n,m,k,u,v,w,c,tmp;
int minCost = 0x3f3f3f3f;
vpii way[1010020];//城市名称,路权 
bool vis[1010020] = {};
void bfs(int start,int cnt)
{
	queue<vpii> q;
	int sum = cnt;
	q.push(way[start]);
	while(!q.empty())
	{
		vpii current = q.front();
		q.pop();
		for(auto x: current)
		{
			if(!vis[x.first])
			{
				sum = cnt+x.second;
				q.push(way[x.first]);
				vis[x.first] = true;
				minCost = min(minCost,sum);
			}
		}
	}
}

void dfs(int start)
{
	if(vis[start])return;
	for(auto x: way[start])
	{
		if(!vis[x.first])
		{
			vis[x.first] = true;
			
			dfs(x.first);
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= m; i++)//道路数量 
	{
		scanf("%d%d%d",&u,&v,&w);
		way[u].push_back({v,w});
		way[v].push_back({u,w});
	}
	for(int i = 1; i <= k; i++)//村庄数量 
	{
		scanf("%d",&c);
		for(int j = 1; j <= n; j++)//城市数量 
		{
			scanf("%d",&tmp);
			way[n+i].push_back({j,c+tmp});
		}
	}
	bfs(1,0);
	printf("%d",minCost);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
