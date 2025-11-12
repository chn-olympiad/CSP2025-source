#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+12;
namespace tianyu{
    int n, m, k;
    struct edge{
        int u, v, w;
    }a[N*100];
    int b[11], c[11][N], pa[N], siz[N];
    int find(int x){return x == pa[x] ? x : pa[x] = find(pa[x]);}
    void merge(int x, int y){
        if (siz[x] > siz[y]) swap(x, y);
        siz[y] += siz[x];
        pa[x] = y;
    }
    bool ish[11];
    ll Ans = 1e18;
namespace subA{
    int m1;
    edge a1[N * 10];
    ll solve(){
        for (int i = 1;i <= n + k;i++) pa[i] = i, siz[i] = 1;
        m1 = 0;
        int C = 0;
        for (int i = 1;i <= k;i++){
            if (!ish[i]) continue;
            ++C;
            for (int j = 1;j <= n;j++){
                ++m1;
                a1[m1] = (edge){i + n, j, c[i][j]};
            }
        }
        sort(a1 + 1, a1 + 1 + m1, [](edge a, edge b){
            return a.w < b.w;
        });
        int cnt = 0;
        ll ans = 0;
        for (int i = 1;i <= k;i++) if (ish[i]) ans += b[i];
        if (ans > Ans) return 1e18;
        for (int i = 1, j = 1;cnt < n + C - 1;){
            int u, v, w;
            if (j > m1 || a[i].w <= a1[j].w) u = a[i].u, v = a[i].v, w = a[i].w, ++i;
            else u = a1[j].u, v = a1[j].v, w = a1[j].w, ++j;
            u = find(u), v = find(v);
            if (u == v) continue;
            ++cnt;
            ans += w;
            if (ans > Ans) return 1e18;
            merge(u, v);
        }
        return ans;
    }
}
    void awa(){
        cin >> n >> m >> k;
        for (int i = 1;i <= m;i++){
            cin >> a[i].u >> a[i].v >> a[i].w;
        }
        sort(a + 1, a + 1 + m, [](edge a, edge b){
            return a.w < b.w;
        });
        bool FFF = 1;
        for (int i = 1;i <= k;i++){
            cin >> b[i];
            if (b[i]) FFF = 0;
            for (int j = 1;j <= n;j++) cin >> c[i][j];
        }
        if (FFF){
            for (int i = 1;i <= k;i++) ish[i] = 1;
            cout << subA::solve();
            return;
        }
        for (int o = 0;o < (1 << k);o++){
            for (int i = 0;i < k;i++) ish[i + 1] = ((o >> i) & 1);
            ll t = subA::solve();
            Ans = min(Ans, t);
        }
        cout << Ans;
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int T = 1;
    while (T--) tianyu::awa();
    return 0;
}
/*
wo zen me bu hui t1????
t2 kan zhe xiang mst

???????
how
wo gan jue wo yao fei le
/ll/ll/ll/ll

hrgf;gr;ehgersou;hgesr
ffffffff
*/