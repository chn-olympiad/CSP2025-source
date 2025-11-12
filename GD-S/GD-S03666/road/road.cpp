#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <utility> 
typedef long long ll; 
using namespace std;
const int N = 1e5+5;
const int M = 1e7+5;
struct Edge
{
	int next,to,dis; 
}edge[M];
int head[N],num;
void get(int from,int to,int dis)
{
	edge[++num].next = head[from];
	edge[num].to = to;
	edge[num].dis = dis;
	head[from] = num; 
}
int n,m,k;
int main()
{
	ll total = 0;
	int cnt = 0;
	bool vis[N];
	int dist[N];
	for(int i = 0 ; i<N;i++)dist[i] = 0x3f3f3f3f;
	memset(head,-1,sizeof(head));
	dist[1] = 0;
	memset(vis,false,sizeof(vis));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0; i< m;i++)
	{
		int u ,v,w;
		scanf("%d%d%d",&u,&v,&w);
		get(u,v,w);get(v,u,w);
	}
	int c[k];int a[k][n];
	for(int l = 0 ; l < k;l++)
	{
		scanf("%d",&c[l]);
		for(int i = 0 ;i< n;i++)
		{
			
			scanf("%d",&a[l][i]);
		}
	 } 
	for(int i = n+1;i<=n+k;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			get(i,j,a[i][j]);
			get(j,i,a[i][j]);
		}
	}
	for(int l = 1 ;l<= n+k;l++)
	{
		int u = -1;
		int min_dist = 0x3f3f3f3f;
		for(int i = 1 ; i<=n+k;i++)
		{
			if(!vis[i]&&dist[i]< min_dist)
			{
				min_dist = dist[i];
				u = i;
			}
		}
		if(u == -1)break;
		vis[u] = true;
		total += min_dist;
//		printf("min:%d",min_dist);
		cnt++;
		for(int j = head[u];j!=-1;j=edge[j].next)
		{
			int v = edge[num].to;
			int d = edge[num].dis;
			if(!vis[v]&&d<dist[v])
			{
				dist[v] = d;
			}
		}
	}
	printf("%lld",total);
	return 0;
 } 
