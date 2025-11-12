#include<bits/stdc++.h>
using namespace std;
namespace Aurora{ void Main(); }
signed main(){ return Aurora::Main(), 0; }
namespace Aurora{
    #define ll long long
    const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
    const ll INF = 1e18;
    int n, m, k, c[K], a[K][N], p[K], p2[K];  
    struct EDGE{ int fr, to, w; }edge[M], t[K][N], t2[K][N], S[1030][N], rec[N];   
    bool cmp(EDGE A, EDGE B){ return A.w < B.w; }
    int bel[N];
    void Reset(){ 
        for(int i = 1; i <= n; i++) bel[i] = i;
    }
    int Find(int x){ return (bel[x] == x) ? x : (bel[x] = Find(bel[x]));}
    void trans(int to, int fr, int nd){
        int p1 = 1, p2 = 1, cnt = 0;
        Reset();
        while(p1 < n || p2 < n){
            EDGE now;
            if(p1 == n){
                now = t[nd][p2]; p2++;
            }else if(p2 == n){
                now = S[fr][p1]; p1++; 
            }else{
                now = (t[nd][p2].w < S[fr][p1].w) ? t[nd][p2++] : S[fr][p1++];
            }
            int x = now.fr, y = now.to;
            int fx = Find(x), fy = Find(y);
            if(fx == fy) continue;
            bel[fx] = fy; S[to][++cnt] = now;
            if(cnt == n - 1) break;
        }
    }
    void trans2(int to, int nd){
        int p1 = 1, p2 = 1, cnt = 0;
        Reset();
        for(int i = 1; i < n; i++) rec[i] = S[to][i]; 
        while(p1 < n || p2 < n){
            EDGE now;
            if(p1 == n){
                now = t2[nd][p2]; p2++;
            }else if(p2 == n){
                now = rec[p1]; p1++; 
            }else{
                now = (t[nd][p2].w < rec[p1].w) ? t[nd][p2++] : rec[p1++];
            }
            int x = now.fr, y = now.to;
            int fx = Find(x), fy = Find(y);
            if(fx == fy) continue;
            bel[fx] = fy; S[to][++cnt] = now;
            if(cnt == n - 1) break;
        }
    }
    void Solve(){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= m; i++){
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            edge[i] = {x, y, z};
        }
        for(int i = 1; i <= k; i++){
            scanf("%d", &c[i]);
            for(int j = 1; j <= n; j++){
                scanf("%d", &a[i][j]);
                if(p[i] == 0 || a[i][j] < a[i][p[i]]) p[i] = j;
            }
            for(int j = n; j >= 1; j--){
                if(p[i] == 0 || a[i][j] < a[i][p2[i]]) p2[i] = j;
            }
            int tp = 0;
            for(int j = 1; j <= n; j++) if(p[i] != j) t[i][++tp] = {p[i], j, a[i][p[i]] + a[i][j]};
            tp = 0;
            for(int j = 1; j <= n; j++) if(p2[i] != j) t2[i][++tp] = {p2[i], j, a[i][p2[i]] + a[i][j]};
            sort(t[i] + 1, t[i] + n, cmp);
            sort(t2[i] + 1, t2[i] + n, cmp);
        }
        // for(int i = 1; i < n; i++){
        //     printf("spe: %lld %lld %lld\n", t[1][i].fr, t[1][i].to, t[1][i].w);
        // }
        sort(edge + 1, edge + m + 1, cmp); Reset();
        for(int i = 1, cnt = 0; i <= m; i++){
            int x = edge[i].fr, y = edge[i].to;
            int fx = Find(x), fy = Find(y);
            if(fx == fy) continue;
            // cout << x << " " << y << endl;
            bel[fx] = fy; S[0][++cnt] = edge[i];
            if(cnt == n - 1) break;
        }
        ll ans = INF;
        // cout << ans << endl;
        for(int s = 0; s < (1 << k); s++){
            ll ex = 0;
            for(int i = 0; i <= k - 1; i++) if((s & (1 << i))) ex += c[i + 1];
            for(int i = k - 1; i >= 0; i--){
                if((s & (1 << i))) break;
                trans(s | (1 << i), s, i + 1);
                trans2(s | (1 << i), i + 1);
            }
            ll res = 0;
            for(int i = 1; i < n; i++) res += S[s][i].w;
            res += ex;
            // printf("s:%lld ex:%lld\n res:%lld\n", s, ex, res);
            ans = min(ans, res);
        }
        printf("%lld\n", ans);
    }
    void Main(){
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
        Solve();
    }
}