#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long

using namespace std;

const int NR = 1e4 + 100;
const int KR = 20;
const int MR = 1e6 + 100;
struct Node {
    int u, v;
    ll w;
    bool operator < (const Node &_) const {
        return w < _.w;
    }
}b[MR];
Node c[NR * KR];
int fa[NR];
ll C[KR];

int Find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
}

void merge(int x, int y) {
    x = Find(x), y = Find(y);
    fa[x] = y;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%lld", &b[i].u, &b[i].v, &b[i].w);
    }
    sort(b + 1, b + 1 + m);
    for(int i = 1; i <= n; i++) fa[i] = i;
    int sz = 0;
    for(int i = 1; i <= m; i++) {
        if(Find(b[i].u) != Find(b[i].v)) {
            //cerr << b[i].u << " " << b[i].v << endl;
            merge(b[i].u, b[i].v);
            c[++sz] = b[i];
        }
    }
    for(int i = 1; i <= k; i++) {
        scanf("%lld", &C[i]);
        for(int j = 1; j <= n; j++) {
            ll wi;
            scanf("%lld", &wi);
            c[++sz] = {n + i, j, wi};
        }
    }
    sort(c + 1, c + 1 + sz);
    ll ans = 9e18;
    for(int op = 0; op < (1 << k); op++) {
        ll sum = 0;
        for(int i = 1; i <= k; i++) {
            if((op >> (i - 1)) & 1) {
                sum += C[i];
                //printf("C: %d %d\n", i, C[i]);
            }
        }
        for(int i = 1; i <= n + k; i++) fa[i] = i;
        for(int i = 1; i <= sz; i++) {
            if(c[i].u > n && ((op >> (c[i].u - n - 1)) & 1) == 0) {
                continue;
            }
            if(c[i].v > n && ((op >> (c[i].v - n - 1)) & 1) == 0) {
                continue;
            }
            if(Find(c[i].u) != Find(c[i].v)) {
                //printf("! %d %d %d\n", c[i].u, c[i].v, c[i].w);
                merge(c[i].u, c[i].v);
                sum += c[i].w;
            }
        }
        //printf("sum:%d\n", sum);
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}
