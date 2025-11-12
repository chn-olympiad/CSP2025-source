#include<bits/stdc++.h>
using namespace std;

const int nr = 1e4 + 20;
const int mr = 1e6 + 20;
const int kr = 11;
int n, m, k, c[kr], a[kr][nr], ft[nr], gcnt; long long res;
struct edge { int u, v, w; friend bool operator < (const edge a, const edge b) { return a.w < b.w; } } e[mr], g[mr], use[mr];

int find(int x)
{
    if (ft[x] == x) return x;
    return ft[x] = find(ft[x]);
}

void merge(int x, int y)
{
    ft[find(x)] = find(y);
}

void dfs(int step, long long val, int up)
{
    if (step > k)
    {
        for (int i = 1; i <= n + up; i++) ft[i] = i;
        for (int i = 1; i <= gcnt; i++) use[i] = g[i];
        sort(g + 1, g + gcnt + 1);
        int cnt = 0; long long sum = 0;
        for (int i = 1; i <= gcnt; i++)
        {
            if (find(g[i].u) == find(g[i].v)) continue;
            merge(g[i].u, g[i].v);
            cnt++, sum += g[i].w;
            if (sum + val > res) break;
            if (cnt == n + up - 1) break;
        }
        res = min(res, sum + val);
        for (int i = 1; i <= gcnt; i++) g[i] = use[i];
        return;
    }
    dfs(step + 1, val, up);
    if (val + c[step] <= res)
    {
        int tmp = gcnt;
        for (int i = 1; i <= n; i++) g[++gcnt] = {n + up + 1, i, a[step][i]};
        dfs(step + 1, val + c[step], up + 1);
        gcnt = tmp;
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) ft[i] = i;
    sort(e + 1, e + m + 1);
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        if (find(e[i].u) == find(e[i].v)) continue;
        merge(e[i].u, e[i].v);
        cnt++, res += e[i].w;
        g[++gcnt] = {e[i].u, e[i].v, e[i].w};
        if (cnt == n - 1) break;
    }
    dfs(1, 0, 0);
    cout << res << '\n';
    return 0;
}
