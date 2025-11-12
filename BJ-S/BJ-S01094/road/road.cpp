#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
using namespace std;
struct E {
    int u, v;
    ll w;
};
int n, m, k;
ll mx;
vector<pil> edge[10005];
ll c[15], a[15][10005];
bool b[10005];
vector<E> e, vec;
int fa[10005];
int Find(int x) {
    if(fa[x] == x) {
        return x;
    }
    return (fa[x] = Find(fa[x]));
}
bool cmp(E x, E y) {
    return x.w < y.w;
}
ll kruscal() {
    ll res = 0;
    sort(e.begin(), e.end(), cmp);
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for(E i : e) {
        int fax = Find(i.u);
        int fay = Find(i.v);
        if(fax != fay) {
            fa[fax] = fay;
            res += i.w;
        }
    }
    return res;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
        e.push_back({u, v, w});
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    sort(e.begin(), e.end(), cmp);
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for(E i : e) {
        int fax = Find(i.u);
        int fay = Find(i.v);
        if(fax != fay) {
            fa[fax] = fay;
            vec.push_back(i);
            mx = max(mx, i.w);
            if(vec.size() == n - 1) {
                break;
            }
        }
    }
    ll ans = LLONG_MAX;
    for(int i = 0; i < (1 << k); i++) {
        ll res = 0;
        e = vec;
        for(int j = 1; j <= k; j++) {
            if(i & (1 << (j - 1))) {
                //cout << '1';
                res += c[j];
                for(int x = 1; x <= n; x++) {
                    if(a[j][x] >= mx) {
                        continue;
                    }
                    for(int y = 1; y <= n; y++) {
                        if(x == y || a[j][x] + a[j][y] >= mx) {
                            continue;
                        }
                        e.push_back({x, y, a[j][x] + a[j][y]});
                    }
                }
            }
        }
        //cout << ": " << kruscal() << " + " << res << endl;
        ans = min(ans, kruscal() + res);
    }
    cout << ans << endl;
    return 0;
}
