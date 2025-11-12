#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct edge
{
    int u, v, w;
    bool operator<(const edge& other) const
    {
        return w < other.w;
    }
};
int nside, cpyn;
edge edges[2000005], cpye[2000005];
int c[10][11005];
int fa[11005], sz[11005];
int get(int x)
{
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
bool merge(int u, int v)
{
    int fu = get(u), fv = get(v);
    if (fu == fv)
    {
        return false;
    }
    --cpyn;
    if (sz[fu] < sz[fv])
    {
        swap(fu, fv);
    }
    fa[fv] = fu;
    sz[fu] += sz[fv];
    return true;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    bool A = true;
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i][0];
        A = A && c[i][0] == 0;
        int flag = false;
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j] == 0)
            {
                flag = true;
            }
        }
        A = A && flag;
    }
    //cout << "Pass\n";
    if (A)
    {
        //cout << "A\n";
        nside = m + k * n;
        cpyn = n + k;
        for (int i = 1; i <= k; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                edges[m + (i - 1) * n + j] = {j, n + i, c[i][j]};
            }
        }
        sort(edges + 1, edges + nside + 1);
        for (int i = 1; i <= cpyn; ++i)
        {
            fa[i] = i;
            sz[i] = 1;
        }
        long long ans = 0;
        for (int i = 1; i <= nside && cpyn > 1; ++i)
        {
            if (merge(edges[i].u, edges[i].v))
            {
                ans += edges[i].w;
            }
        }
        cout << ans;
    }
    else
    {
        bitset<11> b;
        int _b = 0;
        long long mi = 1e18;
        while (_b < (1 << k))
        {
            //cout << _b << '\n';
            b = _b;
            long long ans = 0;
            copy(edges + 1, edges + m + 1, cpye + 1);
            nside = m;
            cpyn = n;
            int ind = 0;
            for (int i = 0; i < k; ++i)
            {
                if (!b[i])
                {
                    continue;
                }
                ans += c[i + 1][0];
                ++ind;
                nside += n;
                ++cpyn;
                for (int j = 1; j <= n; ++j)
                {
                    cpye[m + (ind - 1) * n + j] = {j, n + ind, c[i + 1][j]};
                }
            }
            sort(cpye + 1, cpye + nside + 1);
            for (int i = 1; i <= cpyn; ++i)
            {
                fa[i] = i;
                sz[i] = 1;
            }
            for (int i = 1; i <= nside && cpyn > 1; ++i)
            {
                if (merge(cpye[i].u, cpye[i].v))
                {
                    ans += cpye[i].w;
                }
            }
            mi = min(mi, ans);
            ++_b;
        }
        cout << mi;
    }
    return 0;
}
