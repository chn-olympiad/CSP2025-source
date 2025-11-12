#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
using namespace std;
struct dsu
{
	basic_string<int> fa;
	dsu(int n){fa.resize(n);iota(fa.begin(),fa.end(),0);}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline int unite(int x,int y)
	{
		int fx=find(x),fy=find(y);
		if(fx==fy) return 0;
		return fa[fx]=fy,1;
	}
};
int town[11][10001],tval[10001];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,m,k; cin>>n>>m>>k;
	vector<tuple<int,int,int>> e(m);
	for(auto &[u,v,w]:e) cin>>u>>v>>w;
	sort(e.begin(),e.end(),[&](auto x,auto y){return get<2>(x)<get<2>(y);});
	int conn=0,wsum=0;
	dsu d(n+1); vector<int> e_w;
	vector<tuple<int,int,int>> ee;
	for(auto [u,v,w]:e)
	{
		if(d.unite(u,v)) ++conn,wsum+=w,ee.emplace_back(u,v,w);
		if(conn==n-1) break;
	}
	sort(ee.begin(),ee.end(),[&](auto x,auto y){return get<2>(x)<get<2>(y);});
	int prop=1;
	rep(i,1,k)
	{
		cin>>tval[i],prop&=!tval[i];
		rep(j,1,n) cin>>town[i][j];
	}
	if(prop)
	{
		e.clear(),e.shrink_to_fit(),e=ee;
		rep(i,1,k) rep(j,1,n) e.emplace_back(i+n,j,town[i][j]);
		sort(e.begin(),e.end(),[&](auto x,auto y){return get<2>(x)<get<2>(y);});
		int _conn=0,_wsum=0;
		dsu _d(n+k+2);
		for(auto [u,v,w]:e)
		{
			if(_d.unite(u,v)) ++_conn,_wsum+=w;
			if(_conn==n+k-1) break;
		}
		cout<<_wsum<<'\n',exit(0);
	}
	int ans=wsum;
	rep(st,1,(1<<k)-1)
	{
		e=ee,e.reserve(n*2);
		int ext=0;
		basic_string<int> mv; mv.resize(n+1,1e18);
		basic_string<int> mp; mp.resize(n+1,0);
		rep(j,1,n)
		{
			rep(i,1,k) if((st>>(i-1))&1) if(town[i][j]<mv[j]) mv[j]=town[i][j],mp[j]=i;
			e.emplace_back(n+mp[j],j,mv[j]);
		}
		rep(i,1,k) if((st>>(i-1))&1) ext+=tval[i];
		sort(e.begin(),e.end(),[&](auto x,auto y){return get<2>(x)<get<2>(y);});
		int _conn=0,_wsum=0;
		dsu _d(n+k+2);
		for(auto [u,v,w]:e)
		{
			if(_d.unite(u,v)) ++_conn,_wsum+=w;
			if(_conn==n+k-1) break;
		}
		ans=min(ans,_wsum+ext);
	}
	cout<<ans<<'\n';
	return 0;
}
