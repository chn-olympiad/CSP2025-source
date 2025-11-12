#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4+10;
constexpr int maxm = 1e6+10;
constexpr int maxbase = 1050;
using ll = long long;
constexpr ll INF = 1e18;

struct DSU{
	int fa[maxn], siz[maxn];
	void init(){
		for(int i = 0;i < maxn;i++){
			fa[i] = i;
		}
	}
	inline int find(int x){
		return (x == fa[x])?(x):(fa[x] = find(fa[x]));
	}
	inline void merge(int x,int y){
		x = find(x),y = find(y);
		fa[y] = x;
	}
	inline bool same(int x,int y){
		x = find(x),y = find(y);
		return x == y;
	}
};
ll ans[maxbase];
struct edge{
	int u, v;
	ll w;
	int from;
	bool operator<(const edge other) const{
		return w < other.w;
	}
};
vector<edge> edges;
ll citycost[20];
ll linkcost[20][maxn];
int n, m, K;
int limit;
DSU dsu[maxbase];
void slove(){
	sort(edges.begin(),edges.end());
	int N = edges.size();
	//cerr<<N<<" "<<limit<<endl;
	for(register int i = 0;i < N;i++){
		auto now = edges[i];
		int u = edges[i].u,v = edges[i].v;
		ll w = edges[i].w;
		//cout<<u<<" "<<v<<" "<<w<<endl;
		if( now.from == 0){
			for(register int base = 0;base < limit;++base){
				if(dsu[base].same(u,v)) continue;
				dsu[base].merge(u,v);
				ans[base] += w;
			}
		}
		else{
			for(register int base = 0;base < limit;++base){
				if((base & now.from) != 0){
					if(dsu[base].same(u,v)) continue;
					dsu[base].merge(u,v);
					ans[base] += w;
					//cout<<base<<" "<<w<<endl;
				}
			}		
		}
		
	}
	//cerr<<"step2"<<endl;
	ll res = INF;
	for(int base = 0;base < limit;base++){
		ll now = base;
		ll addcost = 0;
		int cnt = 1;
		while(now){
			if(now & 1)addcost += citycost[cnt];
			cnt++;
			now>>=1;
		}
		res = min(res,ans[base] + addcost);
	}
	//cerr<<"step4"<<endl;
	cout<<res<<endl;
	return;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>K;
	limit = pow(2,K);
	for(int i = 0;i <= limit;i++){
		dsu[i].init();
	}
	edges.reserve(m+n*K+10);
	for(int i = 1;i <= m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w,0});
	}
	for(int i = 1;i <= K;i++){
		cin>>citycost[i];
		for(int j = 1;j <= n;j++){
			cin>>linkcost[i][j];
			edges.push_back({n+i,j,linkcost[i][j],(1<<(i-1))});
		}
	}
//	cerr<<"step1"<<endl;
//	for(auto x : edges){
//		cout<<x.u<<" "<<x.v<<" "<<x.w<<" "<<x.from<<endl;
//	}
	
	slove();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
