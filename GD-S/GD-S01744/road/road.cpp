#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
const int N=1e4,M=1e6,K=10; 
int n,m,k,fa[N+50],c[K+5],a[K+5][N+5];
void init(){
	for(int i=1;i<=n+k;++i) fa[i]=i;
}
int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}
struct Edge{int u,v,w;};
bool add(Edge e){
	int x=find(e.u),y=find(e.v);
	if(x!=y){
		fa[x]=y;
		return 1;
	}
	return 0;
}
vector<Edge> E[1<<K];
bool operator<(const Edge &a,const Edge &b){
	return a.w<b.w;
}
ll work(vector<Edge> &e){
	vector<Edge> E;swap(E,e);
	sort(E.begin(),E.end());
	init();
	ll ans=0;
//	cout<<E.size()<<":\n";
	for(Edge i:E){
//		cout<<i.u<<' '<<i.v<<' '<<i.w<<'\n';
		if(add(i)) e.push_back(i),ans+=i.w;
	}
//	cout<<ans<<'\n';
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;
		E[0].push_back({u,v,w}); 
	}
	for(int i=0;i<k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>a[i][j];
	}
	ans=work(E[0]);
	for(int i=1;i<(1<<k);++i){
		int j=__lg(i&(-i));
		E[i]=E[i-(i&(-i))];
		ll val=0;
		for(int j=0;j<k;++j) if((i>>j)&1) val+=c[j];
		for(int k=1;k<=n;++k) E[i].push_back({n+j+1,k,a[j][k]});
		ll x=val+work(E[i]);
//		cout<<i<<":"<<(i-(i&(-i)))<<" "<<j<<'\n';
		ans=min(ans,x);
	}
	cout<<ans;
}

