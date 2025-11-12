#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace Jayfeather
{
	int n,m,k,c[20009],v2[20009],a[109][20009];
	vector<pair<int,int> > g[20009];
	int ans=10000000000000000;
	bitset<20009> mn,v;
	inline int kruskal(int num)
	{
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
		int res=0,cnt=0;
		memset(v2,0,sizeof(v2));
		v2[1]=1;
		for(int i=1;i<=k;i++)
		{
//			cout<<v[i]<<' ';
			if(v[i]) q.push({a[i][1],n+i});
		}
//		cout<<'\n';
		for(auto i:g[1])
		{
			q.push({i.second,i.first});
		}
		while(!q.empty())
		{
			auto x=q.top();
			q.pop();
			if(v2[x.second]) continue ;
			cnt++;
			res+=x.first;
//			cout<<x.second.first<<" "<<x.second.second<<" "<<x.first<<'\n';
			if(cnt==n+num-1) break ;
			v2[x.second]=1;
			if(x.second<=n)
			{
				for(int i=1;i<=k;i++)
				{
					if(!v2[n+i]&&v[i]) q.push({a[i][x.second],n+i});
				}
				for(auto i:g[x.second])
				{
					if(!v2[i.first]) q.push({i.second,i.first});
				}
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					if(!v2[i]) q.push({a[x.second-n][i],i});
				}
			}
		}
		return res;
	}
	inline void dfs(int d,int sum,int cnt)
	{
		if(d==k+1)
		{
			if(sum>ans) return ;
			int x=sum+kruskal(cnt);
			if(ans>x) ans=x;
//			cout<<'\n';
//			cout<<sum<<" "<<kruskal(cnt)<<'\n';
			return ;
		}
		dfs(d+1,sum,cnt);
		v[d]=1;
		dfs(d+1,sum+c[d],cnt+1);
		v[d]=0;
	}
	signed main()
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			g[x].push_back({y,z});
			g[y].push_back({x,z});
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&c[i]);
			for(int j=1;j<=n;j++)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		dfs(1,0,0);
		printf("%lld\n",ans);
		return 0;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return Jayfeather::main();
} 
/*
time: 1.31/1s
mem: 58.13/512MB
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
