#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 100, M = 2e6;
struct edge{
    int u, v, w;
    bool operator <(edge t){
        return w < t.w;
    }
}es[M];
int n, m, k;
int fa[N], c[N];
int find(int u){
    if (fa[u] == u)return u;
    return fa[u] = find(fa[u]);
}
namespace run1{
    void run1(){
        for (int i = 1; i <= m; i++)
            cin >> es[i].u >> es[i].v >> es[i].w;
        for (int i = 1; i <= k; i++){
            cin >> c[i];
            for (int j = 1; j <= n; j++){
                cin >> es[++m].w;
                es[m].v = i + n;
                es[m].u = j;
            }
        }
        sort(es + 1, es + m + 1);
        ll ans = 1e18;
        for (int mask = 0; mask < (1 << k); mask++){// who be banned
            // cout << "mask: " << mask << endl;
            ll tot = 0;
            for (int i = 1; i <= n + k; i++)
                fa[i] = i;
            for (int i = 1; i <= m; i++)
                tot += c[i];
            for (int i = 1; i <= m; i++){
                int u = es[i].u , v = es[i].v;
                // cout << u << ' ' << v << ' ' << es[i].w << endl;
                if (u > n && (mask >> (u - n- 1)) % 2 == 1)continue;
                if (v > n && (mask >> (v - n- 1)) % 2 == 1)continue;
                // cout << u << ' ' << v << ' ' << es[i].w << endl;
                if (find(u) == find(v))continue;
                // cout << "ok" << endl;
                fa[find(u)] = find(v);
                tot += es[i].w;
            }
            ans = min(ans, tot);
            // cout << "tot: " << tot << endl;
        }
        cout << ans;
    }
};
int main(){
    freopen("road.in", "r", stdin);    
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    if (k <= 5){
        run1::run1();
        return 0;
    }
    for (int i = 1; i <= m; i++)
        cin >> es[i].u >> es[i].v >> es[i].w;
    for (int i = 1; i <= k; i++){
        cin >> c[i];
        for (int j = 1; j <= n; j++){
            cin >> es[++m].w;
            es[m].v = i + n;
            es[m].u = j;
        }
    }
    sort(es + 1, es + m + 1);
    for (int i = 1; i <= n + k; i++)
        fa[i] = i;
    ll ans = 0;
    for (int i = 1; i <= m; i++){
        int u = es[i].u , v = es[i].v;
        // cout << u << ' ' << v << ' ' << es[i].w << endl;
        if (find(u) == find(v))continue;
        // cout << "ok" << endl;
        fa[find(u)] = find(v);
        ans += es[i].w;
    }
    cout << ans;
    return 0;
}