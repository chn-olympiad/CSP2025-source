#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 15;
struct node
{
    int u, v, dis;
    friend bool operator <(node a, node b)
    {
        return a.dis < b.dis;
    }
} edge[1000005];
int n, m, k, fa[maxn];
int a[15][maxn], c[15];
vector<pair<short, short>> vec[1030];
bool cmp(pair<short, short> x, pair<short, short> y)
{
    return a[x.first][x.second] < a[y.first][y.second];
}
ll ans = 1e18;
int fd(int x) { return fa[x] != x ? fa[x] = fd(fa[x]) : x; }
void un(int x, int y)
{
    fa[fd(x)] = y;
}
ll get(int X)
{
    ll sum = 0;
    int now = n - 1;
    for (int i = 1; i <= n + 10; i++) fa[i] = i;
    for (int i = 0; i < k; i++)
        if (X >> i & 1)
            sum += c[i + 1], now++;
    if (__builtin_popcount(X) > 1)
    {
        int tmp = X & (-X), tmp2 = X ^ tmp;
        int l = 0, r = 0, s1 = vec[tmp].size(), s2 = vec[tmp2].size();
        while (l < s1 && r < s2)
        {
            int x1 = vec[tmp][l].first, y1 = vec[tmp][l].second, x2 = vec[tmp2][r].first, y2 = vec[tmp2][r].second;
            if (a[x1][y1] < a[x2][y2]) vec[X].emplace_back(x1, y1), l++;
            else vec[X].emplace_back(x2, y2), r++;
        }
        while (l < s1)
        {
            int x1 = vec[tmp][l].first, y1 = vec[tmp][l].second;
            vec[X].emplace_back(x1, y1), l++;
        }
        while (r < s2)
        {
            int x2 = vec[tmp2][r].first, y2 = vec[tmp2][r].second;
            vec[X].emplace_back(x2, y2), r++;
        }
    }
    int l = 1, r = 0;
    while (l <= m && r < vec[X].size())
    {
        if (edge[l].dis < a[vec[X][r].first][vec[X][r].second])
        {
            int x = edge[l].u, y = edge[l].v;
            if (fd(x) != fd(y))
                un(x, y), now--, sum += edge[l].dis;
            l++;
        }
        else
        {
            int x = vec[X][r].first, y = vec[X][r].second;
            if (fd(x + n) != fd(y))
                un(x + n, y), now--, sum += a[x][y];
            r++;
        }
        if (sum >= ans) return ans;
        if (!now) break;
    }
    while (l <= m)
    {
        int x = edge[l].u, y = edge[l].v;
        if (fd(x) != fd(y))
            un(x, y), now--, sum += edge[l].dis;
        l++;
        if (!now) break;
    }
    while (r < vec[X].size())
    {
        int x = vec[X][r].first, y = vec[X][r].second;
        if (fd(x + n) != fd(y))
            un(x + n, y), now--, sum += a[x][y];
        r++;
        if (!now) break;
    }
    return sum;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].dis;
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], vec[(1 << i - 1)].emplace_back(i, j);
        sort(vec[(1 << i - 1)].begin(), vec[(1 << i - 1)].end(), cmp);
    }
    for (int i = 0; i < (1 << k); i++)
        ans = min(ans, get(i));
    cout << ans;
    return 0;
}