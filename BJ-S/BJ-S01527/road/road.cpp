#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, c[10], a[10][10005], fa[20005], l, num, ans = 2e9;

struct node
{
    int u, v, w;
    bool operator <(const node &x) const
    {
        return w < x.w;
    }
}e[2000005], t[2000005];

int find(int x)
{
    return (fa[x] == x)?x:fa[x] = find(fa[x]);
}

int kru()
{
    for (int i = 1; i <= l; ++i) t[i] = e[i];
    sort(t + 1, t + l + 1);
    for (int i = 1; i <= num; ++i) fa[i] = i;
    int res = 0, cnt = 0, u, v;
    for (int i = 1; i <= l; ++i)
    {
        u = t[i].u, v = t[i].v;
        if (find(u) != find(v))
        {
            fa[find(u)] = find(v);
            res += t[i].w;
            ++cnt;
            if (cnt == num - 1) return res;
        }
    }
}

void dfs(int x, int s)
{
    if (x > k)
    {
        ans = min(ans, kru() + s);
        return;
    }
    if (c[x] > 0) dfs(x+1, s);
    if (s + c[x] >= ans) return;
    ++num;
    for (int i = 1; i <= n; ++i) e[++l] = {num, i, a[x][i]};
    dfs(x+1, s + c[x]);
    --num;
    l -= n;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v >> e[i].w;
    l = m;
    num = n;
    ans = kru();
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i];
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}
