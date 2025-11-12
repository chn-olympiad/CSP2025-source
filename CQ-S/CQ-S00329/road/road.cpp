#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define db double
#define str string
#define MP make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ms(a,t) memset(a,t,sizeof(a))
#define lowbit(x) ((x)&(-(x)))
const int maxn = 1e4+20;
const int maxm = 2e5+20;
const ll INF = 0x3f3f3f3f;
const db eps = 1e-6;
const int mod = 1e9+7;
struct DSU {
	int fa[maxn],siz[maxn];
	void init(int n) {
		for(int i = 1; i <= n; i++) {
			fa[i] = i; siz[i] = 1;
		}
	}
	int find(int x) {
		return ((fa[x] == x) ? x : (fa[x] = find(fa[x])));
	}
	bool merge(int x,int y) {
		x = find(x); y = find(y);
		if(x == y) return false;
		if(siz[x] > siz[y]) swap(x,y);
		fa[x] = y; siz[y] += siz[x];
		return true;
	}
}d;
int n,m,k;
struct Edge{
	int u,v,w;
};
bool cmp(Edge x,Edge y) {
	return x.w < y.w;
}
vector<Edge> G,f[20];
ll MST(vector<Edge> &t,vector<Edge> &res) {
	sort(all(t),cmp);
	d.init(n+k);
	ll ret = 0; res.clear();
	vector<Edge > rev;
	for(Edge x : t) {
		if(d.merge(x.u,x.v)) ret += x.w,res.pb(x);
	}
	return ret;
}
int c[20];
vector<Edge> res[1<<10];
void Solve() {
	cin >> n >> m >> k;
	for(int i = 1,u,v,w; i <= m; i++) {
		cin >> u >> v >> w;
		G.pb((Edge){u,v,w});
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1,x; j <= n; j++) {
			cin >> x;
			f[i].pb((Edge){i+n,j,x});
		}
	}
//	cerr<<k<<'\n';
	ll ans = MST(G,res[0]);
//		cerr<<ans<<'\n';
	for(int i = 1; i < (1<<k); i++) {
//		cerr<<i<<'\n';
		ll sum = 0;
		for(int j = 0; j < k; j++) if((i>>j)&1) {
			sum += c[j+1];
		}
		for(int j = 0; j < k; j++) if((i>>j)&1) {
			vector<Edge> tmp = res[i^(1<<j)];
			for(int p = 0; p < n; p++) tmp.pb(f[j+1][p]);
			sum += MST(tmp,res[i]); break;
		}
//		cerr<<i<<'\n';
		ans = min(ans,sum);
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int tt; cin >> tt; while(tt--)
	Solve();
	return 0;
}
