#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v;
    long long w;
    friend bool operator<(edge a, edge b) { return a.w < b.w; }
} e[1000005], g[150005];
int n, m, k, a[15][10005], p[10005], r, c, cnt;
long long sum, ans = 6e18 + 5;
void Init()
{
    for (int i = 1; i <= n + c; i++)
        p[i] = i;
}
int Find(int x) { return p[x] = (p[x] == x ? x : Find(p[x])); }
bool Judge(int x, int y) { return Find(x) == Find(y); }
void Merge(int x, int y) { p[Find(x)] = Find(y); }

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];
    for (int i = 0; i < (1 << k); i++)
    {
        r = c = cnt = sum = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i & (1 << (j - 1)))
            {
                c++, sum += a[j][0];
                for (int k = 1; k <= n; k++)
                    g[++r] = {n + j, k, a[j][k]};
            }
        }
        sort(g + 1, g + r + 1);
        Init();
        for (int i = 1, j = 1; i <= m; i++)
        {
            while (j <= r && e[i].w > g[j].w)
            {
                int u = g[j].u, v = g[j].v, w = g[j].w;
                j++;
                if (Judge(u, v))
                    continue;
                Merge(u, v);
                sum += w, cnt++;
                if (cnt == n + c - 1 || ans < sum)
                    break;
            }
            if (cnt == n + c - 1 || ans < sum)
                break;
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if (Judge(u, v))
                continue;
            Merge(u, v);
            sum += w, cnt++;
            if (cnt == n + c - 1 || ans < sum)
                break;
        }
        ans = min(ans, sum);
    }
    cout << ans;
}