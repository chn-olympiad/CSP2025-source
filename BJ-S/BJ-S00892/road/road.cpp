#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
struct N
{
    int u, v, w, xid, lf, rg;
    bool operator<(const N &b) const {
        return w > b.w;
    }
}e[1000010];
priority_queue<N> pq;
int c[20];
struct P
{
    int id, num;
}a[20][10010];

bool cmp(P x, P y) {
    return x.num < y.num;
}
int fa[10010];
int fdfa(int p) {
    if(fa[p] == p) return p;
    return fa[p] = fdfa(fa[p]);
}
void merge(int p, int q) {
    fa[fdfa(q)] = fdfa(p);
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    bool f = 0;
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        if(c[i] != 0) f = 1;
        for(int j = 1; j <= n; j++) cin >> a[i][j].num, a[i][j].id = j;
        sort(a[i] + 1, a[i] + n + 1, cmp);
    }
    int st = 0;
    if(!f) st = (1 << k) - 1;
    int ans = 4e18;
    for(int i = st; i < (1 << k); i++) {
        while(!pq.empty()) pq.pop();
        for(int j = 1; j <= n; j++) fa[j] = j;
        int s = 0;
        for(int j = 0; j < k; j++) {
            if((i >> j) & 1) s += c[j + 1];
        }
        for(int j = 1; j <= m; j++) {
            pq.push({e[j].u, e[j].v, e[j].w, 0, 0, 0});
        }
        for(int j = 0; j < k; j++) {
            if((i >> j) & 1) pq.push({a[j + 1][1].id, a[j + 1][1].id, 2 * a[j + 1][1].num, j + 1, 1, 1});
        }
        //cout << i << '\n';
        int cnt = 0;
        while(!pq.empty() && cnt != n - 1) {
            N t = pq.top();
            //cout << t.u << ' ' << t.v << ' ' << t.w << ' ' << t.xid << ' ' << t.lf << ' ' << t.rg << '\n';
            pq.pop();
            if(fdfa(t.u) == fdfa(t.v)) {
                if(t.xid == 0) continue;
                if(t.lf == n && t.rg == n) continue;
                if(t.rg == n) swap(t.lf, t.rg);
                if(t.lf == n) pq.push({a[t.xid][n].id, a[t.xid][t.rg + 1].id, a[t.xid][t.rg + 1].num + a[t.xid][n].num, t.xid, n, t.rg + 1});
                else {
                    pq.push({a[t.xid][t.lf].id, a[t.xid][t.rg + 1].id, a[t.xid][t.rg + 1].num + a[t.xid][t.lf].num, t.xid, t.lf, t.rg + 1});
                    pq.push({a[t.xid][t.lf + 1].id, a[t.xid][t.rg].id, a[t.xid][t.rg].num + a[t.xid][t.lf + 1].num, t.xid, t.lf + 1, t.rg});
                }
                continue;
            }
            merge(t.u, t.v);
            cnt++;
            s += t.w;
            if(t.xid == 0) continue;
            if(t.lf == n && t.rg == n) continue;
            if(t.rg == n) swap(t.lf, t.rg);
            if(t.lf == n) pq.push({a[t.xid][n].id, a[t.xid][t.rg + 1].id, a[t.xid][t.rg + 1].num + a[t.xid][n].num, t.xid, n, t.rg + 1});
            else {
                pq.push({a[t.xid][t.lf].id, a[t.xid][t.rg + 1].id, a[t.xid][t.rg + 1].num + a[t.xid][t.lf].num, t.xid, t.lf, t.rg + 1});
                pq.push({a[t.xid][t.lf + 1].id, a[t.xid][t.rg].id, a[t.xid][t.rg].num + a[t.xid][t.lf + 1].num, t.xid, t.lf + 1, t.rg});
            }
        }
        ans = min(ans, s);
    }
    cout << ans;
    return 0;
}