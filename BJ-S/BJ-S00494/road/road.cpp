#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4+4;
const int inf = 0x7fffffff;

int n, m, k;

struct road {
    int u, v, w;
} r[N*N];

bool cmp(road x, road y) {
    return x.w < y.w;
}

int c[10], a[10][N];

int fa[N];

int fi (int x) {
    if (fa[x] == x) return x;
    return fa[x] = fi(fa[x]);
}

int main() {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n * n; i++) r[i].w = inf;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x > y) swap(x, y);
        int t = x * n + y;
        r[t].u = x, r[t].v = y, r[t].w = min(r[t].w, z);
    }

    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
        int id = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (!a[i][j]) id = j;
        }
        for (int j = 0; j < n; j++) {
            if (id < j) r[id * n + j].w = min(r[id * n + j].w, a[i][j]);
            else if (id > j) r[j * n + id].w = min(r[j * n + id].w, a[i][j]);
        }
    }

    sort(r+1, r+1 + n*n, cmp);

    for (int i = 1; i <= n; i++) fa[i] = i;

    int ind = 0, i = 1, sum = 0;
    while (ind < n-1) {
        if (fi(r[i].u) == fi(r[i].v)) {
            i++;
            continue;
        }
        sum += r[i].w;
        fa[r[i].v] = fi(r[i].u);
        ind++;
    }

    printf("%d\n", sum);

    return 0;
}
