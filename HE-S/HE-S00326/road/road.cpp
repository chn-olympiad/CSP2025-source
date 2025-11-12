#include<bits/stdc++.h>

using namespace std;

// #define int long long

int n, m, k;

const int N = 10000 + 1000, M = 1000000 + 1000;

struct edge {
    int u, v, val;
} e[M], fu[M];

int fa[N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

edge a[12][N];

int vis[11], c[12];

long long ans = LLONG_MAX;

inline void calc() {
    for(int i = 0; i <= n + k; i ++) fa[i] = i;
    int cnt2 = 0, cnt = 0;
    long long res = 0;
    int tp1 = 1, tp2 = 1;
    for(int i = 1; i <= k; i ++) {
        if(vis[i]) {
            cnt2 ++;
            res += c[i];
        }
    }
    cnt = cnt2;
    cnt2 *= n;
    int cne = 0;
    int tp[11] = {};
    for(int i = 1; i <= k; i ++) tp[i] = 1;
    while(cne != cnt2) {
        int mi = 123123123, id = 0;
        for(int i = 1; i <= k; i ++) {
            if(vis[i] and tp[i] <= n) {
                if(mi > a[i][tp[i]].val) {
                    id = i;
                    mi = a[i][tp[i]].val;
                }
            }
        }
        fu[++cne] = a[id][tp[id]++];
    }
    cnt += n - 1;
    while(cnt) {
        if(res > ans) return;
        edge ee;
        if(tp2 == cnt2 + 1 || (tp1 <= m and e[tp1].val <= fu[tp2].val)) {
            ee = e[tp1++];
        }
        else {
            ee = fu[tp2++];
        }
        int u = ee.u, v = ee.v, val = ee.val;
        u = find(u), v = find(v);
        if(u == v) continue;
        fa[u] = v;
        res += val;
        cnt --;
    }
    ans = min(ans, res);
}   

inline void dfs(int u) {
    if(u == k + 1) {
        calc();
        return;
    }
    dfs(u + 1);
    vis[u] = 1;
    dfs(u + 1);
    vis[u] = 0;
}

inline bool cmp(edge a, edge b) {
    return a.val < b.val;
}

inline int in() {
    int n = 0; char p = getchar_unlocked();
    while(!isdigit(p)) p = getchar_unlocked();
    do n = (n << 1) + (n << 3) + p - '0', p = getchar_unlocked();
    while(isdigit(p));
    return n;
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin >> n >> m >> k;
    n = in(), m = in(), k =in();
    for(int i = 1, u, v, w; i <= m; i ++) {
        // cin >> u >> v >> w;
        u = in(), v = in(), w = in();
        e[i] = {u, v, w};
    }   
    bool c0 = 1;
    for(int i = 1; i <= k; i ++) {
        // cin >> c[i];
        c[i] = in();
        if(c[i] != 0) c0 = 0;
        for(int j = 1, v; j <= n; j ++) {
            // cin >> v;
            v = in();
            a[i][j] = {j, n + i, v};
        }
        sort(a[i] + 1, a[i] + 1 + n, cmp);
    }
    sort(e + 1, e + 1 + m, cmp);
    if(!c0) dfs(1);
    else {
        for(int i = 1; i <= k; i ++) vis[i] = 1;
        calc();
    }
    cout << ans;
    return 0;
}
