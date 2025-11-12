#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int,int>
#define fr first
#define sc second
const int N=1e4+10+100,K=15;
int n,m,k,c[K],a[K][N];
LL d[N]; bool vis[N];
vector<PII> g[N],gt[N];
int frm[N],frw[N];
//struct edge {
//	int u,v,w;
//}; vector<int> ei,eg,ef;
//bool cmp(edge x,edeg y) {
//	return x.w<y.w; 
//}
//int Find(int x) {
//	if(fa[x]==x) return x;
//	return fa[x]=Find(fa[x]);
//}
struct node {
	int u; LL d;
	bool operator<(const node&rhs) const {
		return rhs.d<d;
	}
};
LL prim() {
	priority_queue<node> q; q.push({1,0});
	memset(d,0x3f,sizeof(d)); d[1]=frw[1]=0;
	memset(vis,false,sizeof(vis)); memset(frw,0,sizeof(frw));
	LL res=0;
	while(!q.empty()) {
		int u=q.top().u; q.pop();
		if(vis[u]) continue;
//		cout<<"        "<<u<<' '<<d[u]<<"    "<<g[u].size()<<'\n';
		vis[u]=true; res+=d[u];
		for(auto it:g[u]) {
			int v=it.fr,w=it.sc;
//			cout<<"                     "<<v<<' '<<d[v]<< ' '<<w<<"    "<<vis[v]<<'\n';
			if(d[v]>w&&!vis[v]) {
				d[v]=w;
				frm[v]=u; frw[v]=w;
				q.push({v,d[v]});
			}
		}
	}
	return res;
}
int work() {
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++) {
		cin>>u>>v>>w;
		g[u].push_back({v,w}); g[v].push_back({u,w});
//		gf[u].push_back({v,w}); gf[v].push_back({u,v});
//		ei.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	LL ans=prim();
//	cout<<"  "<<ans<<'\n';
//	for(int i=1;i<=n;i++) gf[i].clear();
	for(int i=1;i<=n;i++) {
		int v=frm[i],w=frw[i];
//		cout<<"    "<<i<<' '<<v<<' '<<w<<'\n';
		if(v) gt[i].push_back({v,w}), gt[v].push_back({i,w});
	}
//	for(int i=1;i<=n;i++)  {
//		for(auto it:gt[i]) cout<<it.fr<<' '<<it.sc<<"      ";
//		cout<<'\n';
//	}

//	sort(ei.begin(),ei.end(),cmp);
//	for(int i=1;i<=n;i++) fa[i]=i;
//	LL sum=0;
//	for(auto it:ei) {
//		int u=it.u,v=it.v,w=it.w;
//		u=Find(u); v=Find(v);
//		if(u!=v) {
//			fa[u]=v; eg.push_back(it); sum+=it;
//		}
//	}
//	LL ans=sum;
	for(int t=0;t<(1<<k);t++) {
		for(int i=1;i<=n;i++) {
			g[i].clear();
			for(auto it:gt[i]) g[i].push_back(it);
		}
		LL sum=0;
//		ef.clear(); for(auto it:eg) ef.push_back(it); sum=0;
		for(int i=1;i<=k;i++) {
			if((t>>(i-1))&1) {
				sum+=c[i];
				for(int j=1;j<=n;j++) {
					g[j].push_back({i+n,a[i][j]});
					g[i+n].push_back({j,a[i][j]});
				}
			}
		}
//		cout<<"      "<<t<<' '<<sum<<' '<<'\n';
		ans=min(ans,sum+prim());
	}
	cout<<ans;
	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) {
		work();
	}
	return 0;
}

