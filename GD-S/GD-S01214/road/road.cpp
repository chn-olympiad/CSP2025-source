#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,long long>> edges[1015];
long long c[15];
bool vis[1015];
long long dis[1015];
long long ans,keep;
vector<pair<int,long long>> last;
void solve()
{
	for(int i=1;i<=n+k;i++) vis[i]=false,dis[i]=LLONG_MAX;
	dis[1]=0;
	for(int i=1;i<=n+k;i++)
	{
		long long mins=LLONG_MAX;
		int mini=-1;
		for(int j=1;j<=n+k;j++)
			if(!vis[j]&&dis[j]<mins) mins=dis[j],mini=j;
		vis[mini]=true,last.push_back({mini,0});
		for(auto j:edges[mini])
			if(dis[j.first]>j.second)
				last.back().second+=dis[j.first]-j.second,dis[j.first]=j.second;
	}
}
long long solve(const vector<int>& nodes)
{
	long long res=0;
	for(int i:nodes) vis[i]=false,dis[i]=LLONG_MAX;
	dis[1]=0;
	for(size_t i=nodes.size();i;i--)
	{
		long long mins=LLONG_MAX;
		int mini=-1;
		for(int j:nodes)
			if(!vis[j]&&dis[j]<mins) mins=dis[j],mini=j;
		vis[mini]=true,res+=mins;
		for(auto j:edges[mini]) dis[j.first]=min(dis[j.first],j.second);
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		long long w;
		scanf("%d%d%lld",&x,&y,&w);
		edges[x].push_back({y,w}),edges[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",c+i);
		for(int j=1;j<=n;j++)
		{
			long long w;
			scanf("%lld",&w);
			edges[n+i].push_back({j,w}),edges[j].push_back({n+i,w});
		}
	}
	solve();
	sort(last.begin(),last.end(),[](auto x,auto y)
		{return x.first>n&&y.first>n?(x.second>y.second):(x.first<y.first);});
	vector<int> x;
	for(auto i:last)
	{
		x.push_back(i.first);
		cout<<x.back()<<" ";
		if(i.first==n) ans=solve(x);
		if(i.first>n) keep+=c[i.first-n],ans=min(ans,solve(x)+keep);
	}
//	vector<int> x,y;
//	for(int i=1;i<=n;i++) x.push_back(i);
//	ans=solve(x);
//	for(int i=1;i<=k;i++)
//	{
//		x.push_back(i+n);
//		auto res=solve(x)+c[i];
//		if(res*0.95<=ans) ans=min(ans,res),y.push_back(n+i);
//		x.pop_back();
//	}
//	for(int i=1<<y.size();i;i--)
//	{
//		long long ctot=0;
//		for(size_t j=0;j<y.size();j++) if(i&(1<<j)) ctot+=c[y[j]-n],x.push_back(y[j]);
//		ans=min(ans,solve(x)+ctot);
//		for(size_t j=0;j<y.size();j++) if(i&(1<<j)) x.pop_back();
//	}
	printf("%lld",ans);
	return 0;
}
