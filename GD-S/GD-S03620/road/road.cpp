#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
const int N=10015,K=15; 
struct edg {
	int u,v;
	ll w;
	edg(): u(0),v(0),w(0) {}
	edg(int a,int b,ll c): u(a),v(b),w(c) {}
	bool operator <(const edg& o) const {
		return w<o.w;
	}
};
vector<edg> vec,vv,e,qwq,tmp[K];
int n,m,k,c[K],a[K][N];
int fa[N],siz[N];
void init() { // O(n+k)
	for(int i=1;i<=n+k;i++)
		fa[i]=i,siz[i]=1;
}
int find(const int u) {
	return fa[u]==u?u:(fa[u]=find(fa[u]));
}
void mg(int u,int v) {
	u=find(u),v=find(v);
	if(u==v) return;
	siz[u]+=siz[v],fa[v]=u;
}
ll ans=1000000000000000000ll;
bool used[K];
void gao(ll cnt,const int tot) { // O(nk*log(nk))
	if(cnt>ans) return;
	init();
	vv.clear();
	for(int i=1;i<=k;i++)
		if(used[i]) {
			for(auto& j: tmp[i])
				vv.push_back(j);
		}
	sort(vv.begin(),vv.end());
	qwq.clear();
	qwq.resize(vv.size()+e.size());
	merge(e.begin(),e.end(),vv.begin(),vv.end(),qwq.begin());
	for(auto& i: qwq) if(find(i.u)!=find(i.v)) { // O(nk)
		mg(i.u,i.v);
		cnt+=i.w;
		if(cnt>=ans) return;
		if(siz[find(i.u)]==tot) break;
	}
	ans=cnt;
}
void dfs(const int u,ll cnt,int tot) {
	if(u>k) {
		gao(cnt,tot);
		return;
	}
	dfs(u+1,cnt,tot);
	used[u]=1;
	dfs(u+1,cnt+c[u],++tot);
	used[u]=0;
}
int main() { // O(2^k*nk*log(nk))
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int u,v,w,i=1;i<=m;i++) {
		cin>>u>>v>>w;
		vec.push_back(edg(u,v,w));
	}
	sort(vec.begin(),vec.end());
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
			tmp[i].push_back(edg(n+i,j,a[i][j]));
		}
	}
	init();
	for(auto i: vec) if(find(i.u)!=find(i.v)) {
		mg(i.u,i.v);
		e.push_back(i);
	}
	vec.clear();
	dfs(1,0,n);
	cout<<ans;
	return 0;
}

