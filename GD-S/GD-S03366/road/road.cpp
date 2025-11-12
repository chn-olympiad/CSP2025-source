#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)

using namespace std;

constexpr int N=1e4+10,M=1e6+1e5+10,inf=0x3f3f3f3f3f3f3f3f;

int n,m,k;
struct Edge{
	int u,v,w;
	Edge(){}
	Edge(int u,int v,int w):u(u),v(v),w(w){}
	bool operator<(const Edge &o)const{
		return w<o.w;
	}
}edge[M];
int c[12],a[12][N];

int fa[N],rk[N];

int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return 0;
	if(rk[fx]>rk[fy]) fa[fy]=fx;
	else if(rk[fx]<rk[fy]) fa[fx]=fy;
	else fa[fx]=fy,rk[fy]++;
	return 1;
}

int solve(int S){
	vector<Edge> eg;
	rep(i,1,m) eg.emplace_back(edge[i]);
	int cost=0;
	rep(i,0,k-1){
		if((S>>i)&1){
			cost+=c[i+1];
			rep(j,1,n) eg.emplace_back(i+1,j,a[i+1][j]);
		}
	}
	rep(i,1,n) fa[i]=i;
//	printf("eg:\n");
	sort(eg.begin(),eg.end());
	int res=0;
	for(auto e:eg){
//		printf("%lld %lld %lld\n",e.u,e.v,e.w);
		if(merge(e.u,e.v)){
			res+=e.w;
		}
	}
//	printf("res:%lld\n",res);
	return res+cost;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,1,m){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	
	int ans=inf;
	rep(S,0,(1<<k)-1){
		ans=min(ans,solve(S));
	}
	
	cout<<ans;
	
	return 0;
}














