/*
road
如此困难？
T2 放 Boruvka？CCF 你坏事做尽啊……
不过好像不 Boruvka，如果你考虑 Prim 呢。
发现找到一个扩展点的时候它有两种可能的边权，要么走原来的边，要么你可以找虚点。
每次你开一个虚点其实意味着从所有已经联通的点中找开这个虚点的最小花费，再给所有未联通的点的联通花费取 $\min$。
然后你发现，如果你要开虚点，到要用的时候再开是一定不劣的。
所以如此一来你做 Prim 就可以在 $\mathcal{O}(n^2)$ 的复杂度内过掉。
$n\le 10^4$，事实上很可能真的打算让你这么做。
但是你考虑细节，如果有多个虚点都是一样的，怎么操作。
如果我们开错虚点了就会炸缸，这个做法的正确性比较脆弱。
为了不开错误的虚点，一个做法就是枚举并 ban 掉一些虚点，这样可能在 $\mathcal{O}(2^kn^2)$ 的复杂度内完成。
如果能够考虑反悔贪心，复杂度可能不带 $k$ 是个裸的平方就很有说法。

如果我直接枚举那些虚点被点了，我不就能直接跑普通的 MST 了？
所以直接有 $\mathcal{O}(2^kn^2)$？神秘。
但是它真的想启发我用 Prim 吧？$m$ 的范围让 Kruscal 根本占不到优势啊。

时间终究还是不够了。
如果我能正确实现 Prim 我可以拿到 64pts，与后面的分拼起来，总分是 201pts。
我尽力了。
我不懂，是我饭堂了还是今年真的这么难。
无妨，过去了，反正有分就能进 NOIP。
不过我怎么这么菜啊……太难过了。

我性质看错了，性质分似乎拿不到了。
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=10010;
ll dis[N];
vector<pair<int,ll>>G[N],EX[N];
int a[15][N],c[15];
bool vis[N];
inline ll Prim(int n,int s=1)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	ll res=0;
	dis[s]=0,vis[s]=true;
	for(auto[v,w]:G[s])dis[v]=min(dis[v],w);
	for(auto[v,w]:EX[s])dis[v]=min(dis[v],w);
	ll ans=0;
	for(int i=2;i<=n;i++)
	{
		int p=0;
		ll mn=LONG_LONG_MAX;
		for(int j=1;j<=n;j++)if(!vis[j]&&dis[j]<mn)mn=dis[j],p=j;
		vis[p]=true;
		res+=mn;
		for(auto[v,w]:G[p])dis[v]=min(dis[v],w);
		for(auto[v,w]:EX[p])dis[v]=min(dis[v],w);
	}
	return res;
}
namespace Kruscal
{
	vector<pair<int,pair<int,int>>>E;
	int dsu[N];
	int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
	inline int solve(int n,int m)
	{
		iota(dsu+1,dsu+n+1,1);
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			E.push_back(make_pair(w,make_pair(u,v)));
		}
		sort(E.begin(),E.end());
		ll ans=0;
		for(auto it:E)
		{
			int w=it.first,u=it.second.first,v=it.second.second;
			if(find(u)==find(v))continue;
			ans+=w;
			dsu[find(u)]=find(v);
		}
		printf("%lld\n",ans);
		return 0;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(k==0)return Kruscal::solve(n,m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	ll ans=LONG_LONG_MAX;
	for(int S=0;S<(1<<k);S++)
	{
		int id;
		ll cost=0;
		id=0;
		for(int i=0;i<k;i++)
		{
			if((S>>i)&1)
			{
				id++,cost+=c[i];
				for(int j=1;j<=n;j++)EX[j].push_back(make_pair(n+id,a[i][j])),EX[n+id].push_back(make_pair(j,a[i][j]));
			}
		}
		ans=min(ans,Prim(n+id)+cost);
		id=0;
		for(int i=0;i<k;i++)
		{
			if((S>>i)&1)
			{
				id++;
				for(int j=1;j<=n;j++)EX[j].pop_back(),EX[n+id].pop_back();
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

// 受不了了，我现在就要看 《世界计划：无法歌唱的初音未来》！！！