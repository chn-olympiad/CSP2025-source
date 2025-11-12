#include<cstdio>
#include<algorithm>
#include<utility>
#include<queue>
#include<functional>
using namespace std;

#define N 10005
#define M 1000005
#define K 15
#define int long long

namespace code
{
	int n,m,k;
	pair<pair<int,int>,int> edges[M+K*N];
	pair<pair<int,int>,int> newedges[N],edges2[N<<1];
	int newcnt;
	pair<int,int> xcroad[K][N];
	int xc[K];
	int fa[N+K];
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > heap;
	
	inline int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
	
	int bitcnt(int x)
	{
		int res=0;
		while(x) ++res,x-=(x&-x);
		return res;
	}
	
	signed main()
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i<=m;++i)
			scanf("%lld%lld%lld",&edges[i].first.first,&edges[i].first.second,&edges[i].second);
		bool ts=1;
		for(int i=1;i<=k;++i)
		{
			scanf("%lld",&xc[i]);
			if(xc[i])
				ts=0;
			for(int j=1;j<=n;++j)
				scanf("%lld",&xcroad[i][j].first),
				xcroad[i][j].second=j;
			sort(xcroad[i]+1,xcroad[i]+n+1);
		}
		if(!k||ts)
		{
			for(int i=1;i<=k;++i)
				for(int j=1;j<=n;++j)
					edges[++m]=make_pair(make_pair(i+n,xcroad[i][j].second),xcroad[i][j].first);
			sort(edges+1,edges+m+1,[](pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){return a.second<b.second;});
			for(int i=1;i<=n+k;++i)
				fa[i]=i;
			int ans=0;
			for(int i=1;i<=m;++i)
			{
				int u=edges[i].first.first,v=edges[i].first.second,w=edges[i].second;
				if(find(u)!=find(v))
					fa[find(u)]=find(v),
					ans+=w;
			}
			printf("%lld",ans);
			return 0;
		}
		sort(edges+1,edges+m+1,[](pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){return a.second<b.second;});
		for(int i=1;i<=n;++i)
			fa[i]=i;
		int t=0;
		for(int i=1;i<=m;++i)
		{
			int u=edges[i].first.first,v=edges[i].first.second,w=edges[i].second;
			if(find(u)!=find(v))
				t=i,
				newedges[++newcnt]=edges[i],
				fa[find(u)]=find(v);
			else if(newcnt&&w<=newedges[newcnt].second)
				t=i,
				newedges[++newcnt]=edges[i];
		}
		if(newcnt)
			for(int i=t+1;i<=m;++i)
			{
				int u=edges[i].first.first,v=edges[i].first.second,w=edges[i].second;
				if(w<=newedges[newcnt].second)
					newedges[++newcnt]=edges[i];
				else break;
			}
		int ans=2e9;
		for(int i=0;i<(1<<k);++i)
		{
			int res=0;
			int bits=bitcnt(i);
			for(int j=1;j<=k;++j)
				if(i&(1<<j-1))
				{
					res+=xc[j];
					heap.push(make_pair(xcroad[j][1].first,make_pair(j,1)));
				}
			for(int j=1;j<=newcnt;++j)
				edges2[j]=newedges[j];
			int maxw=(newcnt?newedges[newcnt].second:-2e9);
			int g=newcnt;
			for(int j=1;j<=n+bits;++j)
				fa[j]=j;
			for(int j=1;j<=bits&&heap.size();)
			{
				int u=heap.top().second.first,eidx=heap.top().second.second,w=xcroad[u][eidx].first;heap.pop();
				if(find(u+n)!=find(xcroad[u][eidx].second))
					++j,
					edges2[++newcnt]=make_pair(make_pair(u+n,xcroad[u][eidx].second),xcroad[u][eidx].first),
					fa[find(u+n)]=find(xcroad[u][eidx].second),
					maxw=max(maxw,w);
				else if(newcnt&&w<=maxw)
					edges2[++newcnt]=make_pair(make_pair(u+n,xcroad[u][eidx].second),xcroad[u][eidx].first);
				if(++eidx<=n)
					heap.push(make_pair(xcroad[u][eidx].first,make_pair(u,eidx)));
			}
			if(newcnt)
			{
				while(heap.size())
				{
					int u=heap.top().second.first,eidx=heap.top().second.second,w=xcroad[u][eidx].first;heap.pop();
					if(w<=maxw)
						edges2[++newcnt]=make_pair(make_pair(u+n,xcroad[u][eidx].second),xcroad[u][eidx].first);
					if(++eidx<=n)
						heap.push(make_pair(xcroad[u][eidx].first,make_pair(u,eidx)));
				}
			}
			sort(edges2+1,edges2+newcnt+1,[](pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){return a.second<b.second;});
			for(int j=1;j<=n+bits;++j)
				fa[j]=j;
			for(int j=1;j<=newcnt;++j)
			{
				int u=edges2[j].first.first,v=edges2[j].first.second,w=edges2[j].second;
				if(find(u)!=find(v))
					fa[find(u)]=find(v),
					res+=w;
			}
			ans=min(ans,res);
			newcnt=g;
		}
		printf("%lld",ans);
		return 0;
	}
}

signed main()
{
	// freopen("err.txt","w",stderr);
	// freopen("road3.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	code::main();
	return 0;
}/*
1 4 6
2 3 7
4 2 5
4 3 4


*/