#include <bits/stdc++.h>
using namespace std;
const int Nc = 1e5 + 25;
int n, m, k, edge;
int f[Nc];
int find(int x)
{
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
struct node
{
    int x, y, id;
    long long w;
}a[1500000];
long long cost[15];
bool cmp(node x, node y)
{
    return x.w < y.w;
}
int popcnt(int x)
{
    int s = 0;
    while (x)
    {
        s++;
        x -= (x & -x);
    }
    return s;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    if ((1 << k) * (m + k * n) > 50000000)
    {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        edge++;
        scanf("%d%d%lld", &a[edge].x, &a[edge].y, &a[edge].w);
        a[edge].id = 0;
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%lld", &cost[i]);
        for (int j = 1; j <= n; j++)
        {
            edge++;
            scanf("%lld", &a[edge].w);
            a[edge].x = n + i; a[edge].y = j; a[edge].id = i;
        }
    }
    sort(a + 1, a + edge + 1, cmp);
    // for (int i = 1; i <= edge; i++) cout << a[i].x << ' ' << a[i].y << ' ' << a[i].w << ' ' << a[i].id << "\n";
    long long ans = 9e18;
    for (int s = 0; s < (1 << k); s++)
    {
        // cout << s << ' ';
        long long sum = 0;
        for (int i = 0; i < k; i++)
            if ((s >> i) & 1) sum += cost[i + 1];
        // cout << sum << "\n";
        if (sum >= ans) continue;
        for (int i = 1; i <= n + k; i++) f[i] = i;
        int cnt = n + popcnt(s);
        for (int i = 1; i <= edge && cnt > 1; i++)
        {
            if (sum >= ans) break;
            if (a[i].id != 0 && ((s >> (a[i].id - 1)) & 1) == 0) continue;
            int X = find(a[i].x), Y = find(a[i].y);
            if (X == Y) continue;
            // cout << a[i].x << ' ' << a[i].y << ' ' << a[i].w << ' ' << a[i].id << "\n";
            f[X] = Y; cnt--; sum += a[i].w;
        }
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}
