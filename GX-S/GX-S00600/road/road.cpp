#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 1e5 + 5;
int n, c[15], m, k, u, v, w, a[15][N], fa[N << 3], _u, _v, cnt, tot, st;
ll sum, ans, cst[N][15], tmp[15][2];
bool fl[N][15];
struct node
{
    int u, v, w;
}e[M];
vector<node> mst;
bool cmp(node x, node y)
{
    return x.w <= y.w;
}
int getfa(int x)
{
    return (fa[x] == x ? x : fa[x] = getfa(fa[x]));
}
void clear_n()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    return;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    clear_n();
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    tot = m;
    for (int j = 1; j <= k; j++)
    {
        cin >> c[j];
        for (int i = 1; i <= n; i++)
            cin >> a[j][i];
        if (c[j] == 0)
        {
            fa[n + j] = n + j;
            st++;
            for (int i = 1; i <= n; i++)
            {
                tot++;
                e[tot].u = i, e[tot].v = n + j, e[tot].w = a[j][i];
            }
        }
    }
    sort(e + 1, e + tot + 1, cmp);
    for (int i = 1; i <= tot; i++)
    {
        u = e[i].u, v = e[i].v, w = e[i].w;
        _u = getfa(u), _v = getfa(v);
        if (_u == _v) continue;
        fa[_u] = _v;
        sum += w;
        cnt++;
        mst.push_back({u, v, w});
        if (cnt == n + st - 1) break;
    }
    ans = sum;
    if (k == 0)
    {
        cout << ans;
        return 0;
    }
    cout << ans;
    return 0;
}
