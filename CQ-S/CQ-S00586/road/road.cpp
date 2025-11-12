// Problem: road - ver1 (40tps) (17:03)
// Check: [freopen] [long long] [O()] [Bigdata]
// by 1000ttank
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct Node2 {
    ll u,v,w;
};
ll n,k,m;
vector<ll> fa;
vector<ll> c;
vector<vector<ll>> br;
vector<Node2> g;
vector<bool> ned;
ll ans;
ll find(ll x) {
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void merge(ll u,ll v) {
    u=find(u),v=find(v);
    if (u==v) return ;
    fa[u]=v;
}
void dfs(ll s) {
//	cerr << s+1 << endl;
    if (s==k+1) {
        vector<Node2> e=g;
        ll sum=0;
        for (ll i=1;i<=k;i++) {
            if (ned[i]) {
                sum+=c[i];
                for (ll j=1;j<=n;j++) {
                    for (ll k=1;k<=n;k++) {
                        if (j==k) continue;
                        e.push_back({j,k,br[i][j]+br[i][k]});
                    }
                }
            }
        }
        
        // for (ll i=1;i<=k;i++) {
        	// cerr << ned[i] << " ";
		// } cerr << endl;
        // for (auto i:e) {
        	// cerr << i.u << " " << i.v << " " << i.w << endl;
		// }
		sort(e.begin()+1,e.end(),[&](Node2 x,Node2 y)->bool { return x.w<y.w; });
        ll cnt=0;
        for (ll i=1;i<=n;i++) fa[i]=i;
        // cerr << endl;
        for (ll i=1;i<e.size();i++) {
            ll u=e[i].u,v=e[i].v,w=e[i].w;
            if (find(u)!=find(v)) {
                merge(u,v);
                cnt++;
                sum+=w;
                // cerr << u << " " << v << " " << w << endl; 
                if (cnt>=n-1) break;
            }
        }
        ans=min(ans,sum);
        // cerr << sum << endl << endl;
        return ;
    }
    ned[s]=1;
    dfs(s+1);
    ned[s]=0;
    dfs(s+1);
}
void solve() {
    cin >> n >> m >> k;
    // cerr << k << endl;
    // cerr << "Debug\n";
    c.assign(k+1,0);
    // cerr << "Debug\n";
    br.assign(k+1,vector<ll> (n+1,0));
    // cerr << "Debug\n";
	vector<Node2> a(m+1,{0,0,0});
    // cerr << "Debug\n";
	for (ll i=1;i<=m;i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    // cerr << "Debug\n";
    for (ll i=1;i<=k;i++) {
        cin >> c[i];
        for (ll j=1;j<=n;j++) {
            cin >> br[i][j];
        }
    }
    // cerr << "Debug\n";
    sort(a.begin()+1,a.end(),[&](Node2 x,Node2 y)->bool { return x.w<y.w; });
    // cerr << "Debug\n";
    fa.resize(n+1);
    // cerr << "Debug\n";
    for (ll i=1;i<=n;i++) fa[i]=i;
    // cerr << "Debug\n";
    g.assign(1,{0,0,0});
    // cerr << "Debug\n";
    for (ll i=1;i<=m;i++) {
        ll u=a[i].u,v=a[i].v,w=a[i].w;
        if (find(u)!=find(v)) {
            merge(u,v);
            g.push_back({u,v,w});
            if (g.size()-1>=n-1) break;
        }
    }
    // cerr << "Debug\n";
    ned.assign(k+1,0);
    // cerr << "Debug\n";
    ans=1e9;
    // cerr << "Debug\n";
    dfs(1);
    // cerr << "Debug\n";
    cout << ans << endl;
}
int main() {
    #define CONTEST
    
    #ifdef CONTEST
    #ifndef LOCAL
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll T=1;
    // cin >> T;
    while (T--) {
        solve();
    }
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