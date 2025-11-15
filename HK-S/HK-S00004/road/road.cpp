#include <bits/stdc++.h>
using namespace std;
#define tendoualice
#ifdef tendoualice
ifstream input("road.in");
ofstream output("road.out");
#define cin input
#define cout output
#endif

#define ll long long

struct DSU{
    int n;
    vector<int> t, sz;
    DSU(int N) : n(N), t(N + 1), sz(N + 1) {
        for(int i = 1; i <= n; i++){
            t[i] = i, sz[i] = 1;
        }
    }
    void combine(int u, int v){
        u = find(u), v = find(v);
        if(u != v){
            if(sz[v] > sz[u]) swap(u, v);
            t[v] = u;
            sz[u] += sz[v];
        }
    }
    int find(int u){
        return (t[u] == u)? u:(t[u] = find(t[u]));
    }
    bool same(int u, int v){
        return find(u) == find(v);
    }
};

struct edge{
    int u, v, w;
};

bool cmp(const edge &a, const edge &b){
    return a.w < b.w;
}

const int maxn = 10100;
const int maxm = 1e6 + 100;


ll cal(vector<edge>& g, int ns, int ms){
    sort(g.begin(), g.end(), cmp);
    DSU t(ns);
    ll sum = 0;
    for(int i = 0; i < ms; i++){
        int u = g[i].u, v = g[i].v, w = g[i].w;
        if(!t.same(u, v)){
            t.combine(u, v);
            sum += w;
        }
    }
    return sum;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> g(m);
    for(int i = 0; i < m; i++){
        cin >> g[i].u >> g[i].v >> g[i].w;
    }
    int c[k][n + 1];
    for(int i = 0; i < k; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f;
    for(int t = 0; t < (1 << k); t++){
        ll sum = 0;
        int ns = n, ms = m;
        vector<edge> newg = g;
        for(int i = 0; i < k; i++){
            int tmp = (t >> i) % 2;
            if(tmp == 1){
                for(int j = 1; j <= n; j++){
                    newg.push_back({ns + 1, j, c[i][j]});
                }
                ns++, ms += n, sum += c[i][0];
            }
        }
        sum += cal(newg, ns, ms);
        ans = min(ans, sum);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
// g++ -O2 -std=c++14 -static road.cpp -o road