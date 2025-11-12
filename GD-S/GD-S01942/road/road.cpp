#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+20;
const ll inf=1e18+10;

struct Edge{
	int u,v,w;
	bool operator<(const Edge &e)const{
		return w<e.w;
	}
};
using VE=vector<Edge>;

int n,k,fa[N],h[N];
int find(int u){
	return fa[u]?fa[u]=find(fa[u]):u;
}
bool merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return 0;
	if(h[u]>h[v])swap(u,v);
	else if(h[u]==h[v])++h[v];
	fa[u]=v;
	return 1;
}

ll Kruscal(int t,VE &E){
	memset(fa+1,0,(n+k)*4),memset(h+1,0,(n+k)*4);
	int m=0;ll sum=0;
	sort(E.begin(),E.end());
	for(Edge e:E){
		if(merge(e.u,e.v))sum+=e.w,E[m++]=e;
		if(m==t-1){
			E.erase(E.begin()+m,E.end());
			E.shrink_to_fit();
//			cout<<sum<<'\n';
			return sum;
		}
	}
	return inf;
}

int c[11],a[11][N];ll ans=inf;
void dfs(int i,int t,ll s,VE E){
//	cout<<i<<' '<<t<<' '<<s<<'\n';
	ans=min(ans,Kruscal(t,E)+s);
//	for(Edge e:E)cout<<e.u<<' '<<e.v<<' '<<e.w<<'\n';
//	cout<<'\n';
	if(i>k)return;
	dfs(i+1,t,s,E);
	E.reserve(E.size()+n);
	for(int j=1;j<=n;++j)
		E.push_back({n+i,j,a[i][j]});
	dfs(i+1,t+1,s+c[i],E);
}
int main(){
	freopen("road.in","r",stdin);
//	freopen("road4.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int m;VE E;
	cin>>n>>m>>k;
	E.reserve(m);
	for(int u,v,w;m--;){
		cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	}
	dfs(1,n,0,E),cout<<ans;
	return 0;
}
