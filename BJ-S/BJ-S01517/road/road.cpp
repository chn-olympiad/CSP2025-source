#include <iostream>
#include <algorithm>
using namespace std;

struct edge
{
    int u, v, w;
} a[1000010], ne[100010], d[1100010];

int n, m, k;
int np[20], b[20][10010];
int c[20];
int fa[10050];
long long ans = 4e18;

inline bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

inline int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

inline long long query()
{
    int cur = 0;
    int cck = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (!c[i])
            continue;
        ++cck;
        for (int j = 1; j <= n; ++j)
            ne[++cur] = {i + n, j, b[i][j]};
    }
    sort(ne + 1, ne + cur + 1, cmp);
    int c1 = 1, c2 = 1;
    a[m + 1] = ne[cur + 1] = {0, 0, (int)2e9};
    //cout << "all---------:\n";
    for (register int i = 1; i <= m + n * cck; ++i)
    {
        if (cmp(a[c1], ne[c2]))
            d[i] = a[c1++];
        else
            d[i] = ne[c2++];
        //cout << d[i].u << ' ' << d[i].v << ' ' << d[i].w <<'\n';
    }
    //cout << '\n';
    //cout << "-------------\n";
    for (int i = 1; i <= n +k; ++i)
        fa[i] = i;
    long long s = 0;
    int  cnt = 0;
    for (register int i = 1; i <= m + n * cck; ++i)
        if (find(d[i].u) != find(d[i].v))
        {
            fa[find(d[i].u)] = find(d[i].v);
            s += d[i].w;
            //cout <<d[i].u <<' ' << d[i].v << ' ' << d[i].w << '\n';
            ++cnt;
            if (cnt >= n + cck - 1)
                break;
        }
    return s;
}

inline void dfs(int step, long long cst)
{
    if (step >k)
    {
        //for (int i = 1; i <= k; ++i)
        //    cout <<c[i] << ' ';
        //cout <<'\n';
        long long qq = query();
        ans = min(ans, cst + qq);
        //cout << cst << ' ' << qq <<'\n';
        return ;
    }
    c[step] = 0;
    dfs(step + 1, cst);
    c[step] = 1;
    dfs(step + 1, cst + np[step]);
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >>m >> k;
    for (int i = 1; i <= m; ++i)
        cin >>a[i].u >>a[i].v >>a[i].w;
    for (int i = 1; i <= k; ++i)
    {
        cin >>np[i];
        for (int j = 1; j <= n; ++j)
            cin >> b[i][j];
    }
    sort(a + 1, a + m + 1, cmp);
    dfs(1, 0);
    cout << ans <<'\n';
    return 0;
}
