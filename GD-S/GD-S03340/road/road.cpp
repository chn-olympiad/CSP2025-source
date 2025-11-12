#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a) ; i <= (b) ; i++)
// #define DEBUG
void read(int &x){
    x = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        f = (ch == '-' ? -1 : 1), ch = getchar();
    while(ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x *= f;
}
int fa[20000];
int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
struct edge{
    int u, v, w;
    edge(){}
    edge(int a, int b, int c){
        u = a, v = b, w = c;
    }
    bool operator<(const edge &b)const{
        return w < b.w;
    }
};
int n, m, k;
int cost[20];
long long ans = 0x3f3f3f3f3f3f3f3f;
bool flag[20];
signed main(){
    #ifndef DEBUG
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    #endif 
    vector<edge> pre, e;
    read(n), read(m), read(k);
    rep(i, 1, m){
        int u, v, w;
        read(u), read(v), read(w);
        pre.emplace_back(u, v, w);
    }
    sort(pre.begin(), pre.end());
    rep(i, 1, n) fa[i] = i;
    for(auto edg : pre){
        int u = edg.u, v = edg.v, w = edg.w;
        int fx = Find(u), fy = Find(v);
        if(fx != fy){
            fa[fx] = fy;
            e.push_back(edg);
        }
    }
    // cerr << "!" << e.size() << endl;
    rep(i, 1, k){
        read(cost[i]);
        rep(j, 1, n){
            int x;
            read(x);
            e.emplace_back(n + i, j, x);
        }
    }
    sort(e.begin(), e.end());
    rep(l, 0, (1 << k) - 1){
        // cerr << ans << endl;
        long long res = 0;
        int tot = n;
        rep(i, 1, k){
            flag[i] = l >> (i - 1) & 1;
            if(flag[i])
                res += cost[i], tot++;
        }
        rep(i, 1, n + k) fa[i] = i;
        for(auto &edg : e){
            int u = edg.u, v = edg.v, w = edg.w;
            if(u > n && !flag[u - n]) continue;
            int fx = Find(u), fy = Find(v);
            if(fx != fy){
                res += w;
                fa[fx] = fy;
                tot--;
                if(tot == 1)
                    break;
            }
        }
        if(res < ans)
            ans = res;
    }
    printf("%lld\n", ans);
    return 0;
}
