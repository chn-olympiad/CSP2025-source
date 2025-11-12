#include <bits/stdc++.h>
using namespace std;

long long read()
{
    long long x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
        x *= 10, x += c - '0', c = getchar();
    return x * f;
}

void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

struct Edge
{
    int u, v;
    long long w;
};

int n, m, k;
Edge e[1000005];
vector<int> v, g;
int fa[10025];
long long oo[11];
pair<long long, int> a[11][10005];
long long res = 0;

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void check(int s)
{
    long long tmp = 0;
    int cnt = n - 1;
    int pos[11];
    pos[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        if (s & (1 << (i - 1)))
        {
            tmp += oo[i];
            cnt++;
        }
        pos[i] = 1;
    }
    for (int i = 1; i <= k + n; i++)
        fa[i] = i;
    while (cnt)
    {
        if (pos[0] == n - 1)
            return ;
        int p = 0;
        long long minn = e[g[pos[p]]].w;
        // find the mininum
        for (int i = 1; i <= k; i++)
        {
            if (s & (1 << (i - 1)))
            {
                if (pos[i] <= n and a[i][pos[i]].first < minn)
                {
                    p = i;
                    minn = a[i][pos[i]].first;
                }
            }
        }
        if (tmp + minn >= res)
            return ;
        int u, v;
        if (p == 0)
            u = e[g[pos[p]]].u, v = e[g[pos[p]]].v;
        else
            u = p + n, v = a[p][pos[p]].second;
        pos[p]++;
        int fx = find(u), fy = find(v);
        if (fx == fy)
            continue;
        // if (s == 1)
            // cout << "s = 1: " << u << " " << v << " " << minn << "\n";
        fa[fy] = fx;
        tmp += minn;
        cnt--;
    }
    // if (s == 1)
    //     cout << "nihao " << tmp << "\n";
    res = min(res, tmp);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // cout << 1e3 * 1e5 * log2(1e5) + 1e6 * log2(1e6) << "\n";
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    // cin >> n >> m >> k;
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    {
        // cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u = read(), e[i].v = read(), e[i].w = read();
        v.push_back(i);
    }
    for (int i = 1; i <= k; i++)
    {
        // cin >> oo[i];
        oo[i] = read();
        for (int j = 1; j <= n; j++)
        {
            // cin >> a[i][j].first;
            a[i][j].first = read();
            a[i][j].second = j;
        }
        sort(a[i] + 1, a[i] + n + 1);
    }
    sort(v.begin(), v.end(), [&] (int x, int y) {
        return e[x].w < e[y].w;
    });
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (auto i : v)
    {
        int u = e[i].u, v = e[i].v;
        int fx = find(u), fy = find(v);
        if (fx == fy)
            continue;
        res += e[i].w;
        fa[fy] = fx;
        g.push_back(i);
        if ((int)g.size() >= n - 1)
            break;
    }
    for (int s = 1; s < (1 << k); s++)
        check(s);
    // cout << res << "\n";
    write(res), putchar('\n');
}
