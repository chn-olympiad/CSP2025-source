#include <bits/stdc++.h>
#define int ll
#define endl '\n'
#define fi first
#define il inline
#define se second
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
int n, m, k, ans, val[N], f[N], cnt[N], lst[N], vis[N], dis[20][N];
vector<pair<int, pii>> e;
int find(int x) { return (~f[x] ? f[x] = find(f[x]) : x); }
void uunion(int x, int y) { f[find(x)] = find(y); }
int calc(vector<pair<int, pii>> &e)
{
    sort(e.begin(), e.end());
    memset(f, -1, sizeof f);
    memset(cnt, 0, sizeof cnt);
    vector<pair<int, pii>> tmp;
    int res = 0;
    for (auto x : e)
    {
        int u = x.se.fi, v = x.se.se, w = x.fi;
        if (vis[u] || vis[v])
            continue;
        if (find(u) == find(v))
            continue;
        cnt[u]++, cnt[v]++, lst[u] = lst[v] = w;
        uunion(u, v), res += w;
        tmp.pb({w, {u, v}});
    }
    e.swap(tmp);
    return res;
}
void work(int o, int &ans, vector<pair<int, pii>> &e)
{
    vector<pair<int, pii>> tmp(e);
    for (int i = 1, x; i <= n; i++)
        tmp.pb({dis[o][i], {i, n + o}});
    int res = calc(tmp);
    for (int i = n + 1; i <= n + k; i++)
        if (cnt[i] == 1)
            res -= lst[i];
    if (ans > res + val[n + o])
    {
        ans = res, e.swap(tmp);
        for (int i = n + 1; i <= n + k; i++)
            if (cnt[i] == 1)
                vis[i] = 1;
    }
    else
        vis[n + o] = 1;
}
int solve(int o)
{
    memset(vis, 0, sizeof vis);
    int ans = calc(e);
    vector<pair<int, pii>> tmp(e);
    work(o, ans, tmp);
    for (int i = 1; i <= k; i++)
        if (i != o)
            work(i, ans, tmp);
    for (int i = 1; i <= k; i++)
        if (!vis[n + i])
            ans += val[i + n];
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1, x, y, w; i <= m; i++)
        cin >> x >> y >> w, e.pb({w, {x, y}});
    ans = calc(e);
    for (int i = 1; i <= k; i++)
    {
        cin >> val[n + i];
        for (int j = 1; j <= n; j++)
            cin >> dis[i][j];
    }
    for (int i = 1; i <= k; i++)
        ans = min(ans, solve(i));
    cout << ans << endl;
    return 0;
}