#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << x << ":" << x << endl
#define dbg2(...) cerr << "[" << #__VA_ARGS__ << "] = " ,debug_out(__VA_ARGS__)

template <typename T> void debug_out(T t) { cerr << t << endl;}
template <typename T, typename  ... Ts> void debug_out(T t, Ts ... ts) {
    cerr << t << ", ";
    debug_out(ts...);

}

struct len
{
    int u, v, w;
}a[2000005];
int c[2000005], fa[2000005];

bool cmp(len x, len y)
{
    return x.w < y.w;
}

int fath(int x)
{
    if (fa[x] == x) return fa[x];
    else return fa[x] = fath(fa[x]);
}


int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[++cnt].u = u;
        a[cnt].v = v;
        a[cnt].w = w;
    }
    int sum = m + n + 1;
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i];
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            a[++cnt].u = m + i;
            a[cnt].v = j;
            a[cnt].w = x;
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    for (int i = 1; i <= 2e6; ++i)
    {
        fa[i] = i;
    }
    int cnt2 = 0;
    long long ans = 0;
    for (int i = 1; i <= cnt; ++i)
    {
        int x = a[i].u, y = a[i].v, w = a[i].w;
        x = fath(x), y = fath(y);
        if (x == y) continue;
        fa[x] = y;
        cnt2++;
        ans += w;
        if (cnt2 == n + k - 1) break;
    }
    cout << ans << endl;
    return 0;
}
