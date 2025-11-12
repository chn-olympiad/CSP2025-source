#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define lson (now<<1)
#define rson (now<<1|1) 
#define fi first
#define se second
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
typedef std::pair<int,int> pii;
constexpr int MAXN = (int)2e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = (int)1e9+7;
inline void IO(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
}
int n,m,k,u,v,w,ans;
int fa[MAXN],sz[MAXN];
struct Edge{
	int u,v,w;
	bool operator <(const Edge rhs){
		return w<rhs.w;
	}
};
std::vector<Edge>edge; 
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	x = find(x);y = find(y);
	if(sz[y]>sz[x]) std::swap(x,y);
	fa[y] = x;
	sz[x] += sz[y]; 
}
inline void init(int n){
	FOR(i,0,n+1){
		fa[i] = i;
		sz[i] = 1;
	}
}
inline int prim(){
	std::sort(edge.begin(),edge.end());
	int res = 0,cnt = 0;
	for(const Edge& e : edge){
		if(find(e.u)==find(e.v)) continue;
		res += e.w;
		merge(e.u,e.v);
	}
	return res;
}
//1-4ÓëÐÔÖÊA
//48 pts 
signed main(){
	IO();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(n+k);
	FOR(i,0,m){
		cin>>u>>v>>w;
		edge.emplace_back((Edge){u,v,w});
	}
	FOR(i,0,k){
		cin>>w;
		FOR(j,1,n+1){
			cin>>w;
			if(w) edge.emplace_back((Edge){n+i+1,j,w});
			else merge(n+i+1,j);
		}
	}
	ans = prim();
	cout<<ans;
	return 0;
}

