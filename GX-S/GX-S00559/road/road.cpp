#include <iostream>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
struct T
{
    int u, v, w;
    bool operator< (const T &a) const
    {
        return w < a.w;
    }
}a[N], b[N];
int n, m, k, len, c[N], f[N];
ll ans = 1e18;
int getf(int u)
{
    if (u == f[u])
        return u;
    return f[u] = getf(f[u]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> b[i].u >> b[i].v >> b[i].w;
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1, u, v; i <= m; i++)
    {
        u = getf(b[i].u), v = getf(b[i].v);
        if (u != v)
        {
            f[u] = v;
            a[++len] = {b[i].u, b[i].v, b[i].w};
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            len++;
            a[len].u = i + n;
            a[len].v = j;
            cin >> a[len].w;
        }
    }
    sort(a + 1, a + len + 1);
    for (int i = 0; i < (1 << k); i++)
    {
        ll sum = 0;
        for (int j = 1; j <= n + k; j++)
            f[j] = j;
        for (int j = 0; j < k; j++)
            if ((1 << j) & i)
                sum += c[j + 1];
        for (int j = 1, u, v; j <= len; j++)
        {
            if (a[j].u > n && (  (   1 << (a[j].u - n - 1)   ) & i  ) == 0)
                continue;
            u = getf(a[j].u), v = getf(a[j].v);
            if (u != v)
            {
                f[u] = v;
                sum += a[j].w;
                if (sum > ans)
                    break;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
