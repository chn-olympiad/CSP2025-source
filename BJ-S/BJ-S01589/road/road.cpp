#include <bits/stdc++.h>
using namespace std;
#define For(i, x, y) for (int i = x; i <= y; i++)
#define foR(i, x, y) for (int i = x, i >= y; i--)
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e4 + 20, M = 1e6 + 5, K = 15;
int n, m, k, a[K][N], c[K];
ll ans = 0x3f3f3f3f3f3f3f3f;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge t) const
    {
        return w < t.w;
    }
};

struct disjoint_set
{
    int f[N];
    void init(int lmt)
    {
        For (i, 1, lmt)
            f[i] = i;
    }
    int find(int u)
    {
        if (u == f[u])
            return u;
        return f[u] = find(f[u]);
    }
    bool merge(int u, int v)
    {
        int x = find(u), y = find(v);
        if (x == y)
            return false;
        f[x] = y;
        return true;
    }
} ds;

void solve(int pos, vector<Edge> e, ll w)
{
    if (pos > k)
    {
        for (auto i : e)
            w += i.w;//, cout << i.u << ' ' << i.v << ' ' << i.w << endl;
        // cout << w << endl;
        ans = min(ans, w);
        return;
    }
    solve(pos + 1, e, w);
    For (i, 1, n)
        e.push_back({n + pos, i, a[pos][i]});
    sort(e.begin(), e.end());
    vector<Edge> e2;
    ds.init(n + k);
    for (auto i : e)
    {
        // if (i.u == 1 || i.v == 1)
        //     cout << i.u << ' ' << i.v << ' ' << ds.find(i.u) << ' ' << ds.find(i.v) << endl;
        if (ds.merge(i.u, i.v))
            e2.push_back(i);
    }
    solve(pos + 1, e2, w + c[pos]);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    vector<Edge> e, e2;
    int u, v, w;
    For (i, 1, m)
        scanf("%d%d%d", &u, &v, &w), e.push_back({u, v, w});
    For (i, 1, k)
    {
        scanf("%d", c + i);
        For (j, 1, n)
            scanf("%d", &a[i][j]);
    }
    sort(e.begin(), e.end());
    ds.init(n + k);
    for (auto i : e)
        if (ds.merge(i.u, i.v))
            e2.push_back(i);
    solve(1, e2, 0);
    cout << ans << endl;
    return 0;
}