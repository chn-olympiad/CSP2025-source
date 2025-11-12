#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 10020, M = 1000010;

int n, m, k;
int p[N];
struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
}edge[M];
vector<Edge> S[1 << 10], now;
int a[N], c[10];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    for (int i = 1; i <= m; i ++ )
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; i ++ )
    {
        int pa = find(edge[i].a), pb = find(edge[i].b);
        if (pa != pb) S[0].push_back(edge[i]), p[pa] = pb;
    }
    for (int i = 0; i < k; i ++ )
    {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j ++ )
        {
            scanf("%d", &a[j]);
            S[1 << i].push_back({n + i + 1, j, a[j]});
        }
        for (auto j : S[0]) S[1 << i].push_back(j);
        sort(S[1 << i].begin(), S[1 << i].end());
        for (int j = 1; j <= n + k; j ++ ) p[j] = j;
        now.clear();
        for (auto j : S[1 << i])
        {
            int pa = find(j.a), pb = find(j.b);
            if (pa != pb) now.push_back(j), p[pa] = pb;
        }
        S[1 << i] = now;
        //cout << (1 << i) << ' ' << now.size() << endl;
    }

    for (int i = 1; i < 1 << k; i ++ )
    {
        int lowbit = (i & (-i));
        if (lowbit == i) continue;
        int sz1 = S[lowbit].size(), sz2 = S[lowbit ^ i].size(), pos1 = 0, pos2 = 0;
        while (pos1 < sz1 && pos2 < sz2)
        {
            if (S[lowbit][pos1].w < S[lowbit ^ i][pos2].w) S[i].push_back(S[lowbit][pos1]), pos1 ++ ;
            else S[i].push_back(S[lowbit ^ i][pos2]), pos2 ++ ;
        }
        for (int j = 1; j <= n + k; j ++ ) p[j] = j;
        now.clear();
        for (auto j : S[i])
        {
            int pa = find(j.a), pb = find(j.b);
            if (pa != pb) now.push_back(j), p[pa] = pb;
        }
        S[i] = now;
    }

    LL ans = 1e18;
    for (int i = 0; i < 1 << k; i ++ )
    {
        //cout << i << ' ' << S[i].size() << endl;
        //if (S[i].size() != n - 1) continue;
        LL res = 0;
        for (int j = 0; j < k; j ++ )
            if (i >> j & 1) res += c[j];
        for (auto j : S[i]) res += j.w;
        // if (i == 1)
        // {
        //     for (auto j : S[i]) cout << j.a << ' ' << j.b << ' ' << j.w << endl;
        // }
        // cout << i << ' ' << res << endl;
        ans = min(ans, res);
    }

    printf("%lld\n", ans);

    return 0;
}