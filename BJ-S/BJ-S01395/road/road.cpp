#include <bits/stdc++.h>
#define ll long long
#define ull unsign ll
#define lb long double
using namespace std;

ll n, m, k, ans, pos, Min = 1e18, ana;

int a[20][10010];
int c[20];
int ok;
int f[100010];

struct edge{
    int u, v, w, is;
};
edge e[20000010];

bool cmp(edge x, edge y){
    return x.w < y.w;
}

ll find(ll x){
    return (f[x] == x ? x : f[x] = find(f[x]));
}

void kruskal(){
    sort(e + 1, e + m + 1, cmp);
    ll cnt = 0;
    for (ll i = 1; i <= m; i++){
        ll fu = find(e[i].u);
        ll fv = find(e[i].v);
        if (fu != fv){
            f[fu] = fv;
            if (e[i].is && !ok)
                e[i].w += Min;
            ok = 1;
            ans += e[i].w;
            if (++cnt == n - 1)
                break;
        }
    }
}

void kruskal2(){
    sort(e + 1, e + m + 1, cmp);
    ll cnt = 0;
    for (ll i = 1; i <= m; i++){
        //cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << ' ' << e[i].is << endl;

        ll fu = find(e[i].u);
        ll fv = find(e[i].v);
        if (fu != fv){
            f[fu] = fv;
            ana += e[i].w;
            cout << e[i].w << endl;
            if (++cnt == n - 1)
                break;
        }
    }
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (ll i = 1; i <= m; i++){
            cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;

    kruskal2();
    for (ll i = 1; i <= k; i++){
        cin >> c[i];
        if (c[i] < Min){
            Min = c[i];
            pos = i;
        }
        for (ll j = 1; j <= n; j++){
            cin >> a[i][j];
            f[j] = j;
        }
    }
    for (ll j = 1; j <= n; j++){
        for (ll k = j + 1; k <= n; k++)
            e[++m] = {j, k, a[pos][j] + a[pos][k], 1};
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;

    kruskal();
    cout << ans<< ' ' <<  ana;
    return 0;
}
