#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+15;
struct Edge{
	int u,v;
	ll w;
	Edge(int u0=0,int v0=0,ll w0=0):
		u(u0),v(v0),w(w0){}
};
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int n,m,k,c[15];
vector<Edge> g[15],h[15];
ll ans=LLONG_MAX;
struct dsu{
	int fa[N],sz[N];
	void init(){
		iota(fa+1,fa+n+k+1,1);
		fill(sz+1,sz+n+k+1,1);
	}
	int find(int u){
		return (u==fa[u])?u:(fa[u]=find(fa[u]));
	}
	void unite(int u,int v){
		u=find(u),v=find(v);
		if(u==v) return;
		if(sz[u]<sz[v]) swap(u,v);
		fa[v]=u;
		sz[u]+=sz[v];
	}
} ds;

void renew_g(vector<Edge> &g){
	ds.init();
	vector<Edge> h;
	sort(g.begin(),g.end(),cmp);
	for(auto eg:g){
		if(ds.find(eg.u)==ds.find(eg.v)) continue;
		ds.unite(eg.u,eg.v);
		h.emplace_back(eg);
	}
	reverse(h.begin(),h.end());
	g=h;
}
ll solve(int x){
	ds.init();
	ll ret=0;
//	vector<Edge> gset=g;
//	cout<<g.size()<<endl;
	for(int i=0;i<k;i++){
		if((x>>i)&1){
			ret+=c[i+1];
			h[i+1]=g[i+1];
		}else{
			h[i+1].clear();
		}
	}
	h[0]=g[0];
	
//	cout<<"bg!"<<endl;
//	for(int i=0;i<=k;i++){
//		cout<<"i: "<<i<<endl;
//		for(auto eg:h[i]){
//			cout<<eg.u<<" "<<eg.v<<" "<<eg.w<<endl;
//		}
//		cout<<endl;
//	}
	
	while(1){
		int id=-1;
		for(int i=0;i<=k;i++){
			if(h[i].empty()) continue;
			if(id==-1 || h[i].back().w < h[id].back().w){
				id=i;
			}
		}
		if(id==-1) break;
		Edge eg=h[id].back();
		h[id].pop_back();
		if(ds.find(eg.u)==ds.find(eg.v)) continue;
		ds.unite(eg.u,eg.v);
		ret+=eg.w;
	}
	
	
//	sort(gset.begin(),gset.end(),cmp);
	
	
//	for(auto eg:gset){
//		int u=eg.u,v=eg.v;
//		ll w=eg.w;
//		if(ds.find(u)==ds.find(v)) continue;
//		ds.unite(u,v);
//		ret+=w;
//		
//		
//	}
//	cout<<bitset<11>(x)<<" "<<ret<<" "<<"?"<<endl;
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[0].emplace_back(u,v,w);
	}
	renew_g(g[0]);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			g[i].emplace_back(n+i,j,a);
		}
		renew_g(g[i]);
	}
	
//	cout<<solve(0);
//	return 0;
	
	for(int i=0;i<(1<<k);i++){
		ans=min(ans,solve(i));
	}
	cout<<ans;
	return 0;
}
