#include <bits/stdc++.h>
using namespace std;

ifstream fin("road.in",ios_base::in);
ofstream fout("road.out",ios_base::out);

#define maxN 10005

int n,m,k;
long long exw[maxN][15];

struct graph
{
	vector<pair<int,int>> to[maxN];
	void addedge(int u,int v,int w)
	{
		to[u].push_back({v,w});
		to[v].push_back({u,w});
		return;
	}
} g1,g2;//存图，g1为原图,g2为最小生成树

//求最小生成树
long long dis[maxN];
bool vis[maxN];
long long ans = 0;
void Prim()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	struct node
	{
		int pos;
		int lst;
		long long w;
		bool operator<(const node A) const
		{
			return w > A.w;
		}
	};//一个可以到达的点，距离小的在队列头
	priority_queue<node> q;
	q.push({1,0,0});//以1为起点求
	//cout << "getting tree\n";
	for(int i = 1; i <= n; i++)
	{
		int pnow = q.top().pos,lnow = q.top().lst;
		long long wnow = q.top().w;
		q.pop();
		if(vis[pnow])
			continue;
 		vis[pnow] = 1;
		//cout << pnow << '\n';
		g2.addedge(pnow,lnow,wnow);//存入最小生成树图
		ans += wnow;
		for(pair<int,int> p : g1.to[pnow])
		{
			int np = p.first;
			long long nw = p.second;
			
			if(nw < dis[np] && !vis[np])
			{
				//cout << np << ' ';
				dis[np] = nw;
				q.push({np,pnow,nw});
			}//更新可以到达的点
		}
	}
	return;
}
long long f[maxN][15],g[maxN][15],c[15];
int ff[maxN];
void dfs(int u,int fa)//f表示该子树中最小的代价,g表示除了该子树外最小的代价
{
	ff[u] = fa;
	for(int i = 1; i <= k; i++)
		f[u][i] = exw[u][i];
	for(pair<int,int> p : g2.to[u])
	{
		int np = p.first;
		if(np != fa)
		{
			dfs(np,u);
			for(int i = 1; i <= k; i++)
				f[u][i] = min(f[u][i],f[np][i]);//最小代价即为所有子树的最小代价与该点的最小代价
		}
	}
	
	return;
}
void dfs2(int u,int fa)
{
	for(pair<int,int> p1 : g2.to[u])
	{
		int np1 = p1.first;
		if(np1 == fa)
			continue;
		for(int i = 1; i <= k; i++)
			g[np1][i] = min(g[u][i],exw[u][i]);
		for(pair<int,int> p2 : g2.to[u])
		{
			int np2 = p2.first;
			if(np2 == fa)
				continue;
			if(np1 != np2)
			{
				for(int i = 1; i <= n; i++)
					g[np1][i] = min(g[np1][i],f[np2][i]);
			}
		}//父亲节点、兄弟节点的最小代价
		dfs2(np1,u);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	fin.tie(0);
	fout.tie(0);
	fin >> n >> m >> k;
	long long u,v,w;
	for(int i = 1; i <= m; i++)
	{
		fin >> u >> v >> w;
		g1.addedge(u,v,w);
	}
	for(int i = 1; i <= k; i++)
	{
		fin >> c[i];
		for(int j = 1 ; j <= n; j++)
			fin >> exw[j][i];
	}
	Prim();
	dfs(1,0);
	for(int i = 1; i <= k; i++)
		g[1][i] = 1000000000000000;
	dfs2(1,0);
	for(int i = 1; i <= k; i++)
		g[1][i] = 0;
	/*for(int i = 1; i <= n; i++)//判断是否有更优的替代方案
	{
		for(pair<int,int> p : g2.to[i])
		{
			int np = p.first;
			long long w = p.second;
			if(np == ff[i])
				continue;
			long long minw = 1000000000000000;
			for(int j = 1; j < k; j++)
				minw = min(minw,c[j] + f[np][j] + g[np][j]);//断开该边，途径j的最小代价
			if(minw < w)
			{
				ans -= w;
				ans += minw;
			}
		}
	}*/
	fout << ans;
	fin.tie(0);
	fout.tie(0);
	return 0;
}
