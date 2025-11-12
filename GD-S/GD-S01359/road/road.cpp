#include <bits/stdc++.h>
namespace LIXUEAN{
	using std::cin ;
	using std::cout ;
	using std::endl ;
	using std::vector ;
	using std::sort ;
	typedef long long ll ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	const ll N = 1e4 + 5,M = 1e6 + 5,K = 1e1 + 5 ;
	struct Edge{ ll u,v,w,which ; } ;
	ll n,m,k ;
	ll fa[N + K],siz[N + K] ; 
	void init(){ For(i,1,n + K)fa[i] = i,siz[i] = 1 ; return ; }
	ll find(ll x){
		ll xx = x,tmp = 0 ;
		while(fa[xx] != xx)xx = fa[xx] ;
		while(x != xx)tmp = fa[x],fa[x] = xx,x = tmp ;
		return xx ;
	}
	void merge(ll x,ll y){
		x = find(x),y = find(y) ;
		if(x == y)return ;
		if(siz[x] < siz[y])fa[x] = y,siz[y] += siz[x] ;
		else fa[y] = x,siz[x] += siz[y] ;
		return ;
	}
	ll cost[N],road_num[K],adding_now ;
	bool cmpW(Edge a,Edge b){
		return a.w == b.w ? ll(a.which != adding_now) > ll(b.which != adding_now) : a.w < b.w ; }
	ll Kruskal(vector<Edge>& e){
		vector<Edge> newe ;
		init(),memset(road_num,0,sizeof(road_num)) ;
		sort(e.begin(),e.end(),cmpW) ;
		ll res = 0 ;
		for(auto it : e)
			if(find(it.u) != find(it.v)){
				res += it.w,newe.push_back(it) ;
				merge(it.u,it.v) ;
				++ road_num[it.which] ;
			}
		For(i,0,k)if(road_num[i])
			res += cost[i] ;
		newe.swap(e) ;
		return res ;
	}
	vector<Edge> country[K],used ;
	ll ans ;
	bool all_zero = true ;
	ll u,v,w ;
	int Main(){
		std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
		freopen("road.in","r",stdin),freopen("road.out","w",stdout) ;
		cin >> n >> m >> k ;
		For(i,1,m)
			cin >> u >> v >> w,used.push_back(Edge{u,v,w,0}) ;
		For(i,1,k){
			cin >> cost[i],all_zero &= bool(cost[i] == 0) ;
			For(o,1,n)
				cin >> w,country[i].push_back({n + i,o,w,i}) ;
		}
		if(all_zero){
			For(i,1,k)for(auto it : country[i])
				used.push_back(it) ;
			cout << Kruskal(used) ;
			return 0 ;
		}
		ans = Kruskal(used) ;
		For(i,1,k){
			adding_now = i ;
			vector<Edge> tried(used) ;
			for(auto it : country[i])
				tried.push_back(it) ;
			ll res = Kruskal(tried) ;
			if(res >= ans)continue ;
			ans = res,used.swap(tried) ;
		}
		cout << ans ;
		return 0 ;
	}
} ;
int main(){
	LIXUEAN::Main() ;
	return 0 ;
}
