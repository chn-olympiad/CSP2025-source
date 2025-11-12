#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4 + 5, M = 1e6 + 5;
struct node{
    ll u, v, w;
} e[M];
struct edge{
    ll u, v, w, x;
} t[M];
ll n, m, k;
ll p[M];
ll a[15][N];
ll cnt;
ll Find(ll x){
    return p[x] == x ? x : p[x] = Find(p[x]);
}
void init(){
    for (ll i = 1;i <= n + k;i++){
        p[i] = i;
    }
}
bool cmp(node x, node y){
    return x.w < y.w;
}
bool cmp2(edge x, edge y){
    return x.w < y.w;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (ll i = 1;i <= m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (ll i = 1;i <= k;i++){
        cin >> a[i][0];
        for (ll j = 1;j <= n;j++){
            cin >> a[i][j];
            t[++cnt] = {n + i, j, a[i][j], i - 1};
        }
    }
    sort(e + 1, e + m + 1, cmp);
    init();
    for (ll i = 1;i <= m;i++){
        ll u = e[i].u, v = e[i].v, w = e[i].w;
        ll x = Find(u), y = Find(v);
        if (x == y) continue;
        p[y] = x;
        t[++cnt] = {u, v, w, -1};

    }
    sort(t + 1, t + cnt + 1, cmp2);
    ll all = (1 << k) - 1;
    ll ans = 1e18;
    for (ll i = 0;i <= all;i++){
        ll sum = 0;
        for (ll j = 1;j <= k;j++){
            if (((i >> (j - 1)) & 1) == 1) sum += a[j][0];
        }
        init();
        for (ll j = 1;j <= cnt;j++){
            ll u = t[j].u, v = t[j].v, w = t[j].w, x = t[j].x;
            if (x != -1 && ((i >> x) & 1) == 0) continue;
            ll y = Find(u), z = Find(v);
            if (y == z) continue;
            p[z] = y;
            sum += w;
        }
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}
