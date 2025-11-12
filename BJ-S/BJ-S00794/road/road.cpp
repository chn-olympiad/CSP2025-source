#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 5;
const ll maxm = 2e6 + 5;
const ll maxk = 15;
const ll inf = 1e18;
struct st{
    int u, v;
    ll w;
}ed[maxm];
ll n, M, m, k, fa[maxn], siz[maxn], cnt, a[maxk][maxn], c[maxk], ans = inf, sum, tot, flagA;
int find(ll x){ return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y){
    if(siz[x] < siz[y]) fa[x] = y, siz[y] += siz[x];
    else fa[y] = x, siz[x] += siz[y];
}
bool cmp(st a1, st a2){ return a1.w < a2.w; }
ll kruskal(int N){
    ll res = 0;
    cnt = 0;
    for(int i = 1; i <= n + k; ++i) fa[i] = i, siz[i] = 1;
    sort(ed + 1, ed + m + 1, cmp);
    for(int i = 1; i <= m; ++i){
        int u = ed[i].u, v = ed[i].v;
        ll w = ed[i].w;
        int fu = find(u), fv = find(v);
        if(fu != fv){
            merge(fu, fv), res += w, cnt++;
            if(cnt >= N - 1){
                return res;
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
    for(int i = 1; i <= m; ++i) cin >> ed[i].u >> ed[i].v >> ed[i].w;
    for(int i = 1; i <= k; ++i){
        cin >> c[i];
        flagA = max(flagA, c[i]);
        for(int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    if(!flagA){
        for(int i = 1; i <= k; ++i)
            for(int j = 1; j <= n; ++j) ed[++m] = {n + i, j, a[i][j]};
        cout << kruskal(n + k);
        return 0;
    }
    if(k <= 5 || m <= 100000){
        M = m;
        for(int i = 0; i < (1 << k); ++i){
            m = M, tot = n;
            sum = 0;
            for(int j = 1; j <= k; ++j)
                if((i >> (j - 1)) & 1){
                    for(int l = 1; l <= n; ++l) ed[++m] = {n + j, l, a[j][l]};
                    sum += c[j], tot++;
                }
            ans = min(ans, kruskal(tot) + sum);
        }
        cout << ans;
        return 0;
    }
    cout << kruskal(n);
    return 0;
}
