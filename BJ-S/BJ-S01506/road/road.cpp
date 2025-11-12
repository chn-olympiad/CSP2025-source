#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, ll>
#define fi first
#define se second
#define ls (i << 1)
#define rs (i << 1 | 1)
#define mid (l + r >> 1)
using namespace std;

const int N = 1e4 + 15;
struct A{
    int u, v;
    ll w;
}a[N * 100], b[N], d[15][N], p[N], id;
int n, m, k, f[N], ct, cnt[15], ti;
ll c[15], ans;
vector<pii> g[N];
bitset<15> vis;
inline bool cmp(A x, A y){
    return x.w < y.w;
}
inline int find(int x){
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
inline void add(int x, int y){
    x = find(x), y = find(y);
    f[x] = y;
}
inline void solve(int pp, ll s){
   for (int i = 1; i <= n; ++i) f[i] = i;
   for (int i = 1; i <= k; ++i){
       f[i + n] = i + n, cnt[i] = 0;
   }
   ti += n + k;
   cnt[0] = ct = 0;
   bool fl = 1;
   ll now = 0;
   int cc = 0;
   while(fl && ct < pp * n + n - 1){
       int mn = 1e9 + 1, dk = 0;
       fl = 0;
       for (int i = 0; i <= k; ++i){
            if (!vis[i] || (i == 0 && cnt[0] >= n - 1) || cnt[i] >= n) continue;
            fl = 1;
            ti++;
            if (i == 0){
                if (mn > b[cnt[0] + 1].w){
                    mn = b[cnt[0] + 1].w;
                    dk = 0, id = b[cnt[0] + 1];
                }
            }
            else{
                if (mn > d[i][cnt[i] + 1].w){
                    mn = d[i][cnt[i] + 1].w;
                    dk = i;
                    id = d[i][cnt[i] + 1];
                }
            }
       }
       if (fl){
            int u = id.u, v = id.v;
            if (find(u) != find(v)){
                add(u, v), ++cc;
                now += mn;
                if (cc == n + pp - 1) break;
            }
            cnt[dk]++, ct++;
       }
   }
   ans = min(ans, now + s);
}
inline void dfs(int x, int cc, ll sum){
    if (sum >= ans || (ti >= 1e7 && k >= 5)) return;
    if (x > k){
        if (cc) solve(cc, sum);
        return;
    }
    vis[x] = 1;
    dfs(x + 1, cc + 1, sum + c[x]);
    vis[x] = 0;
    dfs(x + 1, cc, sum);
}
int main(){
   //freopen("data.in", "r", stdin);
   //freopen("T1.out", "w", stdout);
   freopen("road.in", "r", stdin);
   freopen("road.out", "w", stdout);
   scanf("%d%d%d", &n, &m, &k);
   for (int i = 1; i <= m; ++i){
        scanf("%d%d%lld", &a[i].u, &a[i].v, &a[i].w);
   }
   sort(a + 1, a + m + 1, cmp);
   for (int i = 1; i <= n; ++i) f[i] = i;
   for (int i = 1; i <= m; ++i){
        int u = a[i].u, v = a[i].v;
        ll w = a[i].w;
        if (find(u) != find(v)){
            add(u, v), ++ct;
            b[ct] = a[i];
            //g[u].push_back({v, w});
            //g[v].push_back({u, w});
            ans += w;
            if (ct == n - 1) break;
        }
   }
   for (int i = 1; i <= k; ++i){
       scanf("%lld", &c[i]);
       for (int j = 1; j <= n; ++j){
            scanf("%lld", &d[i][j].w);
            d[i][j].u = i + n, d[i][j].v = j;
       }
       if (c[i] >= ans){
           k--, i--;
           continue;
       }
       sort(d[i] + 1, d[i] + n + 1, cmp);
   }
   vis[0] = 1;
   dfs(1, 0, 0);
   cout << ans;
   return 0;
}
