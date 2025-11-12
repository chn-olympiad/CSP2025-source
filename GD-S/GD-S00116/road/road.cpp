#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pair<int,int> PII
const int N=1e4+10;
int n,m,k,p[N];
bool is_used[N];
int find(int x){
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}
struct edge{
	int u,v,w;
	bool is_new;
	bool operator<(const edge &o)const{
		return w<o.w;
	}
};
vector<edge> e;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) p[i]=i;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w,0});
		e.push_back({v,u,w,0}); 
	}
	for(int i=1;i<=k;++i){
		int c;
		cin>>c;
		for(int j=1;j<=n;++j){
			int w;
			cin>>w;
			w+=c;
			e.push_back({i,j,w,1});
			e.push_back({j,i,w,1});
		}
	}
	sort(e.begin(),e.end());
	int cnt=0,cost=0;
	for(auto x:e){
		int u=x.u,v=x.v,w=x.w;
		int pu=find(u),pv=find(v);
		if(pu==pv) continue;
//		cerr<<w<<'\n';
		cost+=w;
		p[pu]=pv;
		if(++cnt==n-1){
			break;
		}
 	}
 	cout<<cost;
	return 0;
}
