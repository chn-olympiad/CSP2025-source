#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

#define int long long

using pii = pair <int, int>;

#define fi first
#define se second

pair <int, pii> e[N << 1], last[N << 1];
int f[N], a[11][12000], K[12];

int Find(int x)
{
    if (f[x] != x) return f[x] = Find(f[x]);
    return f[x];
}

signed main()
{
    freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
    freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m, k, tot = 0; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) 
    {
        int x, y, w; cin >> x >> y >> w;
        last[++tot] = {w, {x, y}};
        e[i] = {w, {x, y}};
    }
    sort(e + 1, e + 1 + tot);
    for (int i = 1; i <= n; i++) f[i] = i;
    tot = 0; // This is a key!
    for (int i = 1; i <= m; i++)
    {
        int x = Find(e[i].se.fi), y = Find(e[i].se.se);
        if (x == y) continue;
        f[x] = y;
        last[++tot] = {e[i].fi, {e[i].se.fi, e[i].se.se}};
    }
    sort(last + 1, last + 1 + tot);
    for (int i = 1; i <= k; i++)
    {
        cin >> K[i];
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < (1 << k); i++)
    {
        int now = 0;
        for (int i = 1; i <= n; i++) f[i] = i;
        tot = n;
        for (int j = 1; j <= tot; j++) e[j] = last[j];
        for (int j = 1; j <= k; j++)
        {
            f[n + j] = n + j;
            if (!(i & (1 << (j - 1)))) continue;
            now += K[j];
            for (int t = 1; t <= n; t++)
                e[++tot] = {a[j][t], {n + j, t}};
        }
        sort(e + 1, e + 1 + tot);
        int tot3 = 0;
        for (int j = 1; j <= tot; j++)
        {
            int x = Find(e[j].se.fi), y = Find(e[j].se.se);
            if (x == y) continue;
            ++tot3;
            f[x] = y;
            now += e[j].fi;
        }
        ans = min(ans, now);
    }
    cout << ans << '\n';

    return 0;
}