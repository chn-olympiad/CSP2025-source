/*
D
为什么倒开，因为C是字符串 我的字符串不太好，晚点做。 
B:
额，一眼题啊，为什么我不会D，为什么CD全部计数，有点想哭了www
B的话最后答案显然是一棵树啊（双向边，如果不是树的话肯定是删掉最优的） 
然后这题还简单了，所有路都是可以修的（如果有原本没坏的也没关系，直接把原本没坏的路的边权变成0即可）
然后对于乡镇，由于建立乡镇要花钱，所以我们不知道要怎么连边
哦明白了
枚举一下乡镇ci，乡镇连接的点u,v，我们就直接建一条代价为aiu+aiv+ci的路 
然后PRIM即可，111111
不过还是慢了，为什么呢？虽然k非常小（10）
但是每个k都要加n^2的边啊，慢死了
所以，我们可以先求原图最小生成树
然后可能要dp或者贪心或者分层图啊
我成sb了，想复杂了
原来，原来，原来，一个乡镇可以建很多条路啊。
看一眼数据，哦，特殊性质A输出0即可，，，，，
想个部分分，n^2k的话就是先求原图最小生成树然后暴力枚举建了几个乡镇
显然错了
算了，写n log (n^2k+m)过不去就骂C 
然后我就意识到，我一开始读的题是乡镇只能建一条路，但是实际上不是
所以说我不能直接建图跑最小生成树，这肯定是错的，应为建完第一个c会对后面的产生影响，但又不是超级源点
所以先求原图最小生成树，我们考虑在树上干一些事情
考虑我们自己去建，显然可能要去状压 
设dp state为建的形态为state的乡镇的最小答案，state才1024
然后给每种state都连边做prim
时间复杂度2^k*n*log(n^2k) 
期望失分20分 
流程：先求原图MST，然后在树上做MST 
这个sb电脑，一直黑屏。今天莫名其妙的一直处于想吐吐不出来的状态www
我恨计数 
这个时候，发现选完一个城镇不影响你选择另一个城镇，不可能说你同时选的城镇会互相影响
所以如果选择一个城镇让答案不劣，我们就选 
*/
#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,w;
	edge(int _to,int _w):to(_to),w(_w){}
};
struct MSTE
{
	int u,v,w;
	MSTE(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
const int INF=1e9;
int prim1(int n,vector<vector<edge>>&g,vector<vector<edge>>&res)//prim1要求形态 
{
	//cout<<g[1].size();
	vector<long long>dis(n+1,INF);
	vector<long long>pa(n+1,-1);
	vector<bool>vis(n+1,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	dis[1]=0;
	pq.push(make_pair(0,1));
	long long mst=0,cnt=0;
	while(!pq.empty()&&cnt<n)
	{
		
		pair<int,int>cur=pq.top();
		pq.pop();
		int u=cur.second,d=cur.first;
		if(vis[u])continue;
		vis[u]=1;
		mst+=d;
		cnt++;
		if(pa[u]!=-1)
		{
			res[u].push_back({pa[u],d});
			res[pa[u]].push_back({u,d});
		}
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].to,w=g[u][i].w;
			if(!vis[v]&&w<dis[v])
			{
				dis[v]=w;
				pa[v]=u;
				pq.push(make_pair(w,v));
			}
		}
	}
	return mst;
}
int prim2(int n,vector<vector<edge>>&g)//prim2不要求形态 
{
	vector<long long>dis(n+1,INF);
	vector<long long>pa(n+1,-1);
	vector<bool>vis(n+1,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	dis[1]=0;
	pq.push(make_pair(0,1));
	long long mst=0,cnt=0;
	while(!pq.empty()&&cnt<n)
	{
		pair<int,int>cur=pq.top();
		pq.pop();
		int u=cur.second,d=cur.first;
		if(vis[u])continue;
		vis[u]=1;
		mst+=d;
		cnt++;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].to,w=g[u][i].w;
			if(!vis[v]&&w<dis[v])
			{
				dis[v]=w;
				pa[v]=u;
				pq.push(make_pair(w,v));
			}
		}
	}
	return mst;
}
long long ret;
long long mp[12][1005];
long long c[12];
int maxk,maxn;
//void dfs(int nw,vector<vector<edge> >g,int cnt,vector<bool>vis)
//{	
//	if(nw==maxk)return ;
//			vis[nw]=1;
//			cnt+=c[nw];
//			for(int u=1;u<=maxn;u++)
//			{
//				for(int v=1;v<=maxn;v++)
//				{
//					g[u].push_back({v,(mp[nw][u]+mp[nw][v])});
//					g[v].push_back({u,(mp[nw][u]+mp[nw][v])});
//				}
//			}
//			ret=min(ret,prim2());
//			dfs(nw+1,g,cnt,vis);
//			vis[nw]=0;
//			cnt-=c[nw];
//			for(int u=1;u<=maxn;u++)
//			{
//				for(int v=1;v<=maxn;v++)
//				{
//					g[u].pop_back();
//					g[v].pop_back();
//				}
//			}
//			dfs(nw+1,g,cnt,vis);
//}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	
	cin>>n>>m>>k;
	vector<vector<edge> >g(n+1);
	vector<vector<edge> >res(n+1);
	vector<vector<edge> >g1(n+1);
	maxk=k,maxn=n;
	//g[1].push_back({1,2});
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	

	g1=g;
	ret=prim1(n,g,res);
	cout<<ret;
	bool flaga=true;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)flaga=false;
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j])flaga=false;
		}
	}
	if(flaga)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				g1[u].push_back({v,mp[i][u]+mp[i][v]});
				g1[v].push_back({u,mp[i][v]+mp[i][u]});
			}
		}
		
		if(prim2(n,g1)+c[i]<ret)
		{
			ret=prim2(n,g1)+c[i];
			g=g1;
		}
		else
		{
			g1=g;
		}
	}
	cout<<ret;
	//give me 100pts pls
}
