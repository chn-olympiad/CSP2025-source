#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

inline int read()
{
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}

const int NR = 1e4 + 20;
const int KR = 20;
const int MR = 4e6 + 10;
int n, m, k;

int c[KR];

int aw[KR][NR];

struct edgeb
{
    int x, y;
    long long w;
    bool operator < (const edgeb &b) const
    {
        return w < b.w;
    }
} eb[MR], et[MR];

int f[NR];

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    f[x] = y;
}

void brute()
{
    for (int i = 1; i <= m; i ++)
    {
        eb[i].x = read();
        eb[i].y = read();
        eb[i].w = read();
    }
    for (int j = 1; j <= k; j ++)
    {
        c[j] = read();
        for (int i = 1; i <= n; i ++)
        {
            aw[j][i] = read();
        }
    }
    long long ans = 1e18;
    for (int s = 0; s < (1 << k); s ++)
    {
        int mt = m;
        for (int i = 1; i <= m; i ++)
        {
            et[i] = eb[i];
        }
        long long sum = 0;
        int nowcnt = 0;
        for (int j = 1; j <= k; j ++)
        {
            if (((s >> (j - 1)) & 1) == 1)
            {
                nowcnt ++;
                sum += c[j];
                for (int i = 1; i <= n; i ++)
                {
                    et[++mt] = (edgeb){i, n + nowcnt, aw[j][i]};
                    et[++mt] = (edgeb){n + nowcnt, i, aw[j][i]};
                }
            }
        }
        sort(et + 1, et + mt + 1);
        for (int i = 1; i <= n + nowcnt; i ++)
        {
            f[i] = i;
        }
        for (int i = 1; i <= mt; i ++)
        {
            int x = et[i].x, y = et[i].y;
            if (find(x) == find(y)) continue;
            merge(x, y);
            sum += et[i].w;
        }
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);
}

int mtot;

void worksub()
{
    sort(eb + 1, eb + mtot + 1);
    for (int i = 1; i <= n + k; i ++)
    {
        f[i] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= mtot; i ++)
    {
        int x = eb[i].x, y = eb[i].y;
        if (find(x) == find(y)) continue;
        merge(x, y);
        ans += eb[i].w;
    }
    printf("%lld\n", ans);
}

struct edge
{
    int nxt, to;
    long long w;
} e[MR];

int head[NR], cnt;

void add(int x, int y, long long w)
{
    e[++cnt].nxt = head[x];
    e[cnt].to = y;
    e[cnt].w = w;
    head[x] = cnt;
}

long long dis[NR];
int from[NR];
int vis[NR];
int memt[KR];
long long memv[KR];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read();
    m = read();
    k = read();
    if ((m <= (int)1e5 && k <= 5) || k <= 0)
    {
        brute();
        return 0;
    }
    for (int i = 1; i <= n + k; i ++)
    {
        head[i] = -1;
    }
    for (int i = 1; i <= m; i ++)
    {
        int x = read(), y = read(), w = read();
        add(x, y, w);
        add(y, x, w);
        eb[++mtot] = (edgeb){x, y, w};
    }
    bool subt = true;
    for (int j = 1; j <= k; j ++)
    {
        c[j] = read();
        if (c[j] != 0) subt = false;
        int cntt = 0;
        for (int i = 1; i <= n; i ++)
        {
            int a = read();
            add(n + j, i, a);
            add(i, n + j, a);
            if (a == 0) cnt ++;
            eb[++mtot] = (edgeb){i, n + j, a};
        }
        if (cnt == 0) subt = false;
    }
    if (subt)
    {
        worksub();
        return 0;
    }
    for (int i = 1; i <= n + k; i ++)
    {
        dis[i] = 1e18;
        from[i] = 0;
    }
    dis[1] = 0;
    long long ans = 0;
    for (int i = 1; i <= n + k; i ++)
    {
        int x = 0;
        long long mnd = 1e18;
        for (int j = 1; j <= n + k; j ++)
        {
            if (vis[j]) continue;
            if (dis[j] < mnd)
            {
                x = j;
                mnd = dis[j];
            }
        }
        if (x == 0) break;
        vis[x] = 1;
        ans += dis[x];
        if (x > n) memt[x - n] ++;
        if (from[x] > n) memt[from[x] - n] ++;
        if (x > n) memv[x - n] = dis[x];
        dis[x] = 0;
        for (int j = head[x]; j != -1; j = e[j].nxt)
        {
            int y = e[j].to;
            if (vis[y]) continue;
            long long now = e[j].w;
            if (y > n) now += c[y - n];
            if (now < dis[y])
            {
                dis[y] = now;
                from[y] = x;
            }
        }
    }
    for (int j = 1; j <= k; j ++)
    {
        if (memt[j] == 1) ans -= memv[j];
    }
    printf("%lld\n", ans);
    return 0;
}
