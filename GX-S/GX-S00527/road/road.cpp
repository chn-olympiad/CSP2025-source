#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for(int i = s, rep##i = t; i <= rep##i; ++i)
#define per(i, t, s) for(int i = t, per##i = s; i >= per##i; --i)
#define gc getchar
#define il inline
typedef long long ll;

il int rd() {
    int x = 0, f = 0;
    char ch = gc();
    while(!isdigit(ch)) {if(ch == '-') f = 1; ch = gc();}
    while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
    return f ? -x : x;
}

constexpr int N = 30005, M = 3000005;
struct Edge {
    int u, v, w;
} e[M];
int n, m, K, a[15][N], c[15];

bool cmp(const Edge &p, const Edge &q) {
    return p.w < q.w;
}

int fa[N]; ll ans = 0, ans0 = 0;
il int fnd(int x) {return x == fa[x] ? x : fa[x] = fnd(fa[x]);}
il void sub1() {
    sort(e + 1, e + m + 1, cmp);
    rep(i, 1, n) fa[i] = i;
    int cnt = 0;
    rep(i, 1, m) {
        if(cnt >= n - 1) break;
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(fnd(u) == fnd(v)) continue;
        ans += e[i].w;
        fa[fnd(u)] = fnd(v);
        cnt++;
    }
    printf("%lld\n", ans);
}


set<pair<int, ll>> st;
bool wrong[N];

il void calc(int t) {
    int t1 = t;
    while(t1) {
        if(wrong[t1]) return;
        t1 = t & (t1 - 1);
    }
    rep(i, 1, n) fa[i] = i;
    ll cc = 0, n1 = n, cnt1 = 0;
    rep(i, 1, 10) {
        if((t >> (i - 1)) & 1) {
            fa[n + i] = n + i;
            cc += c[i]; n1++;
            rep(j, 1, n) st.insert({a[i][j], ((ll)j << 20) + n + i});
        }
    }
    for(auto o : st) {
        if(cnt1 >= n1) break;
        int w = o.first, u = o.second >> 20, v = o.second - (u << 20);
        if(fnd(u) == fnd(v)) continue;
        cnt1++; cc += w;
        fa[fnd(u)] = fnd(v);
    }
    if(cc <= ans) ans = cc;
    else if(cc > ans0) wrong[t] = 1;
    rep(i, 1, 10) if((t >> (i - 1)) & 1) {
        rep(j, 1, n) st.erase({a[i][j], ((ll)j << 20) + n + i});
    }
}

il void suball() {
    sort(e + 1, e + m + 1, cmp);
    rep(i, 1, n) fa[i] = i;
    int cnt = 0;
    rep(i, 1, m) {
        if(cnt >= n - 1) break;
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(fnd(u) == fnd(v)) continue;
        st.insert({w, ((ll)u << 20) + v});
        fa[fnd(u)] = fnd(v); ans0 += w;
        cnt++;
    }
    ans = 1e18;
    rep(i, 0, (1 << K) - 1) {
        calc(i);
    }
    printf("%lld\n", ans);
}

il void solve() {
    n = rd(), m = rd(), K = rd();
    rep(i, 1, m) e[i].u = rd(), e[i].v = rd(), e[i].w = rd();
    rep(i, 1, K) {
        c[i] = rd();
        rep(j, 1, n) a[i][j] = rd();
    }
    if(K == 0) sub1();
    else suball();
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    solve();
    return 0;
}
