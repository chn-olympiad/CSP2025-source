// //城市化改造.
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// int n, m, k;
// struct edge
// {
//     int u, v, w;
// } ;
// unordered_map <int, int> mp[15];
// vector <edge> ce, ee;
// int c[15], a[15][10005];
// int fa[10015], sz[10015];
// int fa2[10015], sz2[10015];
// set <int> st;
// inline int fd(int x)
// {
//     return fa[x] == x ? x : fd(fa[x]);
// }
// inline int fd2(int x)
// {
//     return fa2[x] == x ? x : fd(fa2[x]);
// }
// inline void mg(int x, int y)
// {
//     x = fd(x), y = fd(y);
//     if (sz[x] < sz[y])
//         swap(x, y);
//     for (int i = 1; i <= k; i++)
//     {
//         mp[i][x] = min(mp[i][x], mp[i][y]);
//         mp[i].erase(y);
//     }
//     st.erase(y);
//     sz[x] += sz[y];
//     fa[y] = x;
// }
// inline void mg2(int x, int y)
// {
//     x = fd2(x), y = fd2(y);
//     if (sz2[x] < sz2[y])
//         swap(x, y);
//     sz2[x] += sz2[y];
//     fa2[y] = x;
// }
// inline bool cmp(edge x, edge y)
// {
//     return x.w < y.w;
// }
// int ans = 0x3f3f3f3f3f3f3f3f;
// bool ks = 1;
// int CNT;
// inline void slv(int x)
// {
//     int res = 0x3f3f3f3f3f3f3f3f;
//     for (int i = ks; i < (1 << k); i++)
//     {
//         int cur = 0;
//         ce.clear();
//         for (int j = 1; j <= k; j++)
//         {
//             if (i & (1 << (j - 1)))
//             {
//                 cur += c[j];
//                 for (int l : st)
//                 {
//                     ce.emplace_back((edge){l, n + j, mp[j][l]});
//                 }
//                 fa2[n + j] = n + j, sz2[n + j] = 1;
//             }
//         }
//         sort(ce.begin(), ce.end(), cmp);
//         // CNT += ce.size() * (long long)log2(ce.size());
//         for (int l : st)
//             fa2[l] = l, sz2[l] = 1;
//         for (auto e : ce)
//         {
//             int u = e.u;
//             int v = e.v;
//             int w = e.w;
//             if (fd2(u) != fd2(v))
//             {
//                 mg2(u, v);
//                 cur += w;
//             }
//         }
//         res = min(res, cur);
//     }
//     ans = min(ans, res + x);
// }
// signed main()
// {
//     freopen("road.in", "r", stdin);
//     freopen("road.out", "w", stdout);
//     scanf("%lld %lld %lld", &n, &m, &k);
//     for (int i = 1; i <= m; i++)
//     {
//         int u, v, w;
//         scanf("%lld %lld %lld", &u, &v, &w);
//         ee.emplace_back((edge){u, v, w});
//     }
//     ee.resize(100000);
//     for (int i = 1; i <= k; i++)
//     {
//         scanf("%lld", &c[i]);
//         for (int j = 1; j <= n; j++)
//         {
//             scanf("%lld", &a[i][j]);
//             mp[i][j] = a[i][j];
//         }
//     }
//     for (int i = 1; i <= n + k; i++)
//         st.insert(i <= n ? i : 1), fa[i] = fa2[i] = i, sz[i] = sz2[i] = 1;
//     sort(ee.begin(), ee.end(), cmp);
//     slv(0);
//     int cnt = 0, cur = 0;
//     for (auto e : ee)
//     {
//         int u = e.u;
//         int v = e.v;
//         int w = e.w;
//         if (fd(u) != fd(v))
//         {
//             cnt++;
//             cur += w;
//             mg(u, v);
//             if (cnt == n - 1)
//                 ks = 0;
//             slv(cur);
//         }

//     }
//     printf("%lld", ans);
//     return 0;
// }

//城市化改造.
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
struct edge
{
    int u, v, w;
} ;
vector <edge> ce, ee;
int c[15], a[15][10005];
bool fl[15];
int fa[10015], sz[10015];
vector <pair <int, int> > ed[10015];
inline int fd(int x)
{
    return fa[x] == x ? x : fd(fa[x]);
}
inline void mg(int x, int y)
{
    x = fd(x), y = fd(y);
    if (sz[x] < sz[y])
        swap(x, y);
    sz[x] += sz[y];
    fa[y] = x;
}
inline bool cmp(edge x, edge y)
{
    return x.w < y.w;
}
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        ee.emplace_back((edge){u, v, w});
    }
    // ee.resize(100000);
    bool c0 = 1;
    for (int i = 1; i <= k; i++)
    {
        scanf("%lld", &c[i]);
        if (c[i])
            c0 = 0;
        bool h0 = 0;
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &a[i][j]);
            if (!a[i][j])
                h0 = 1;
            // ed[n + i].emplace_back(j, a[i][j]);
            // ed[a]
        }
        if (!h0)
            c0 = 0;
    }
    if (c0)
    {
        for (int i = 1; i <= k; i++)
        {
            int tar = 0;
            for (int j = 1; j <= n; j++)
            {
                if (!a[i][j])
                {
                    tar = j;
                    break;
                }
            }
            for (int j = 1; j <= n; j++)
            {
                if (j == tar)
                    continue;
                ee.emplace_back((edge){tar, j, a[i][j]});
            }
        }
        k = 0;
    }
    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < (1 << k); i++)
    {
        int cur = 0;
        ce = ee;
        for (int j = 1; j <= k; j++)
        {
            if (i & (1 << (j - 1)))
            {
                cur += c[j];
                fl[j] = 1;
                for (int l = 1; l <= n; l++)
                    ce.emplace_back((edge){n + j, l, a[j][l]});
            }
        }
        for (int i = 1; i <= n + k; i++)
            fa[i] = i, sz[i] = 1;
        sort(ce.begin(), ce.end(), cmp);
        for (auto e : ce)
        {
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if (fd(u) != fd(v))
            {
                cur += w;
                mg(u, v);
            }
        }
        ans = min(ans, cur);
    }
    printf("%lld", ans);
    return 0;
}