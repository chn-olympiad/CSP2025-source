#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 1e5 + 5, MAXM = 1e6 + 5;
ll n, m, k, c[MAXN], ans = 1e18, x[20], cnt, fa[MAXN];
struct node{
    ll u, v, w;
}adj[MAXM * 2];
bool cmp(node A, node B){
    return A.w < B.w;
}
ll find(ll x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void dfs(ll step){
    if(step > k){
        ll res = 0, tmp = 0;
        for(ll i = 1; i <= n; i++) fa[i] = i;
        for(ll i = 1; i <= k; i++) if(x[i]) fa[i + n] = i + n;
        for(ll i = 1; i <= k; i++) if(x[i]) res += c[i];
        for(ll i = 1; i <= k; i++) if(x[i]) tmp++;
        set <ll> se;
        for(ll i = 1; i <= n; i++) se.insert(i);
        for(ll i = 1; i <= k; i++) if(x[i]) se.insert(i + n);
        for(ll i = 1; i <= cnt; i++){
            ll u = adj[i].u, v = adj[i].v, w = adj[i].w;
            if(!(se.count(u) && se.count(v))) continue;
            ll fu = find(u), fv = find(v);
            if(fu != fv){
                fa[fu] = fv;
                res += w;
                cnt++;
                if(cnt == n + tmp - 1) break;
            }
        }
        ans = min(ans, res);
        return;
    }
    for(ll i = 0; i <= 1; i++){
        x[step] = i;
        dfs(step + 1);
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i++) cin >> adj[i].u >> adj[i].v >> adj[i].w;
    cnt = n;
    ll f = 1;
    for(ll i = 1; i <= k; i++){
        cin >> c[i];
        if(c[i] != 0) f = 0;
        for(ll j = 1; j <= n; j++){
            adj[++cnt].u = i + n;
            adj[cnt].v = j;
            cin >> adj[cnt].w;
        }
    }
    sort(adj + 1, adj + 1 + cnt, cmp);
    if(f == 1){
        ll res = 0;
        for(ll i = 1; i <= n; i++) fa[i] = i;
        for(ll i = 1; i <= k; i++) fa[i + n] = i + n;
        set <ll> se;
        for(ll i = 1; i <= n; i++) se.insert(i);
        for(ll i = 1; i <= k; i++) if(x[i]) se.insert(i + n);
        for(ll i = 1; i <= cnt; i++){
            ll u = adj[i].u, v = adj[i].v, w = adj[i].w;
            if(!(se.count(u) && se.count(v))) continue;
            ll fu = find(u), fv = find(v);
            if(fu != fv){
                fa[fu] = fv;
                res += w;
                cnt++;
                if(cnt == n + k - 1) break;
            }
        }
        cout << res;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}