#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
struct Node {
    int u, v, w;
};
Node a[N];
int f[N], n, m, k, cnt = 1;
long long sum = 0;

bool cmp(Node x, Node y) {
    return x.w < y.w;
}

void init() {
    for (int i = 0; i <= n; i++) {
        f[i] = i;
    }
}

int myfind(int x) {
    if (f[x] == x) return x;
    return f[x] = myfind(f[x]);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
    }
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 1; j <= n; j++) {
            m++, a[m].u = 0, a[m].v = j;
            scanf("%d", &a[m].w);
            a[m].w += x;
        }
    }
    sort(a+1, a+m+1, cmp);
    init();
    for (int i = 1; i <= m; i++) {
        int fx = myfind(a[i].u), fy = myfind(a[i].v);
        if (fx != fy) {
            f[fx] = fy, sum += a[i].w;
            if (fx != 0) cnt++;
        }
        if (cnt == n) break;
    }
    printf("%lld\n", sum);
    return 0;
}
