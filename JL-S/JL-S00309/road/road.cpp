#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 10015, M = 1000005;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
struct Edge{
    int a, b, c;
}g[M], g2[N];
int c[15], a[15][N], fa[N], d[N], n, m, k;
bool used[M], use[15];
LL ans;
bool cmp(Edge A,Edge B)
{
    return A.c < B.c;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void check()
{
    for (int i=1;i<n;i++)
        g[i] = g2[i];
    int tot = n - 1;
    LL sum = 0;
    for (int i=1;i<=k;i++)
    {
        if (!use[i])
            continue;
        sum += c[i];
        for (int j=1;j<=n;j++)
            g[++ tot] = {n + i, j, a[i][j]};
    }
    if (sum >= ans)
        return;
    sort(g + 1, g + tot + 1, cmp);
    for (int i=1;i<=n+k;i++)
        fa[i] = i, d[i] = 1;
    for (int i=1;i<=tot;i++)
    {
        int a = find(g[i].a), b = find(g[i].b);
        if (a != b)
        {
            if (d[a] < d[b])
                fa[a] = b, d[b] += d[a];
            else
                fa[b] = a, d[a] += d[b];
            sum += g[i].c;
            if (sum >= ans)
                return;
            //cout<<g[i].a<<' '<<g[i].b<<'\n';
        }
    }
    ans = min(ans, sum);
    //for (int i=1;i<=k;i++)if (use[i])cout<<i<<' ';cout<<":"<<sum<<'\n';
}
void dfs(int u)
{
    if (u > k)
    {
        check();
        return;
    }
    use[u] = true;
    dfs(u + 1);
    use[u] = false;
    dfs(u + 1);
}
void work()
{
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++)
        cin >> g[i].a >> g[i].b >> g[i].c;
    for (int i=1;i<=k;i++)
    {
        cin >> c[i];
        for (int j=1;j<=n;j++)
            cin >> a[i][j];
    }
    sort(g + 1, g + m + 1, cmp);
    for (int i=1;i<=n;i++)
        fa[i] = i, d[i] = 1;
    int tot = 0;
    for (int i=1;i<=m;i++)
    {
        int a = find(g[i].a), b = find(g[i].b);
        if (a != b)
        {
            if (d[a] < d[b])
                fa[a] = b, d[b] += d[a];
            else
                fa[b] = a, d[a] += d[b];
            g2[++ tot] = g[i];
            ans += g[i].c;
        }
    }
    dfs(1);
    cout << ans;
    // 15:15 finished
}
int main()
{
    freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _T = 1;
    //cin >> _T;
    while (_T--)
        work();
    return 0;
}