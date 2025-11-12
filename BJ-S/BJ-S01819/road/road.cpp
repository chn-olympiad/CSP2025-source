#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;
const int M = 1e6 + 9;
const int K = 15;
struct road {
    int u, v, w;
} r[M];
int c[K], a[K][N];
int f[N];
long long minn = 0ll;

bool is(int n) {
    bool cnt = 0
    ; for (int i = 1; i <= n; i++) {
        if (f[i] == 0) {
            if (cnt) return 0;
            cnt = 1;
        }
    }
    return 1;
}

void bfs(int step, int n, long long val) {
    if (step == n + 1) {
        if (is(n)){
            if (!minn) minn = val;
            else minn = min(minn, val);
        }
        return;
    }
    bfs(step + 1, n, val);
    int i = step;
    int u = r[i].u, v = r[i].v, w = r[i].w;
    while (f[u]) {
        u = f[u];
    }
    while (f[v]) {
        v = f[v];
    }
    int temp = f[v];
    if (u != v)
    {
    f[v] = u;
    }
    bfs(step + 1, n, val + w);
    f[v] = temp;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        cin >> r[i].u >> r[i].v >> r[i].w;
        if (r[i].u > r[i].v) swap(r[i].u, r[i].v);
    }
    for (int j = 1; j <= k; j++) {
        cin >> c[j];
        for (int i = 1; i <= n; i++) {
            cin >> a[j][i];
        }
    }
    if (!k)
    bfs(1, m, 0ll);
    cout << minn << endl;
    return 0; 
}