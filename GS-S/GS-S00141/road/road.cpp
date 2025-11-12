#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 25, M = 1e6 + 5;
struct edge {
    ll u, v, w;
};
vector<edge> e;
ll n, m, k, ans, c[15], a[15][N], fa[N], siz[N];

bool cmp(edge x, edge y) {return x.w < y.w;}

ll getf(ll x) {
    return (fa[x] == x)? x : (fa[x] = getf(fa[x]));
}

void hebing(ll x, ll y) {
    ll tx = getf(x), ty = getf(y);
    if (siz[tx] < siz[ty]) fa[tx] = ty, siz[ty] += siz[tx];
    else fa[ty] = tx, siz[tx] += siz[ty];
}

void kruskal() {
    for (auto x : e) {
        if (getf(x.u) == getf(x.v)) continue;
        else {
            hebing(x.u, x.v);
            ans += x.w;
        }
    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    ll x, y, z;
    while (m--) {
        cin >> x >> y >> z;
        e.push_back({x, y, z});
    }
    for (int j = 1; j <= k; j++) {
        ll t = n + j;
        cin >> c[j];
        ans += c[j];
        for (int i = 1; i <= n; i++) {
            cin >> a[j][i];
            e.push_back({t, i, a[j][i]});
        }
    }

    for (int i = 1; i <= n + k; i++) fa[i] = i;
    sort(e.begin(), e.end(), cmp);
    kruskal();

    cout << ans;
    return 0;
}
