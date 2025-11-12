#include<bits/stdc++.h>
using namespace std;

struct node {
    int x, y, z;
    bool operator < (const node &A) const {
        return z < A.z;
    }
}a[2000001];
int cnt, fa[20001], ans, c[20001], arr[11][20001];

int f(int x) {
    if (fa[x] != x) {
        fa[x] = f(fa[x]);
        return fa[x];
    }
    return fa[x];
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[++cnt] = {x, y, z};
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);
    }
    if (k == 0) {
        sort(a + 1, a + 1 + cnt);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= cnt; i++) {
            int u = a[i].x, v = a[i].y, w = a[i].z;
            if (f(u) != f(v)) {
                ans += w;
                fa[fa[v]] = fa[u];
            }
        }
        printf("%d\n", ans);
        return 0;
    }
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            a[++cnt] = {n + i, j, arr[i][j]};
    sort(a + 1, a + 1 + cnt);
    for (int i = 1; i <= n + k; i++)
        fa[i] = i;
    for (int i = 1; i <= cnt; i++) {
        int u = a[i].x, v = a[i].y, w = a[i].z;
        if (f(u) != f(v)) {
            ans += w;
            fa[fa[v]] = fa[u];
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
