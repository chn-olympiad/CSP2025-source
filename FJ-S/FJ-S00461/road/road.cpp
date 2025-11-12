#include<cstdio>
#include<algorithm>
using namespace std;

struct edge
{
    int u, v, w;
}a[1000005], b[11][10015], f[1 << 10][10015];

bool cmp(const edge &A, const edge &B)
{
    return A.w < B.w;
}

int n, m, k, c[11], fa[10015], sz[10015], cc;
long long s, ans;

int getf(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = getf(fa[x]);
}

inline void mg(int x, int y)
{
    x = getf(x);
    y = getf(y);
    if(sz[x] < sz[y]) swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
    sort(a + 1, a + m + 1, cmp);
    for(int i = 1; i <= k; i++)
    {
        scanf("%d", &c[i]);
        for(int j = 1; j <= n; j++)
        {
            b[i][j].u = n + i;
            b[i][j].v = j;
            scanf("%d", &b[i][j].w);
        }
        sort(b[i] + 1, b[i] + n + 1, cmp);
    }
    for(int i = 1; i <= n + k; i++)
        fa[i] = i;
    s = 0;
    for(int i = 1; i <= m; i++)
        if(getf(a[i].u) != getf(a[i].v))
        {
            f[0][++cc] = a[i];
            mg(a[i].u, a[i].v);
            s += a[i].w;
        }
    ans = s;
    for(int i = 1; i < (1 << k); i++)
    {
        for(int j = 1; j <= n + k; j++)
            fa[j] = j;
        s = 0;
        int v = 0, t = n;
        for(int j = 1; j <= k; j++)
            if(i & (1 << j - 1))
            {
                s += c[j];
                v = j;
                t++;
            }
        int l = i - (1 << v - 1);
        int c1 = 1, c2 = 1, cc = 0;
        for(int j = 1; j <= t - 2 + n; j++)
        {
            if(c2 > n || f[l][c1].w < b[v][c2].w)
            {
                if(getf(f[l][c1].u) != getf(f[l][c1].v))
                {
                    f[i][++cc] = f[l][c1];
                    mg(f[l][c1].u, f[l][c1].v);
                    s += f[l][c1].w;
                }
                c1++;
            }
            else
            {
                if(getf(b[v][c2].u) != getf(b[v][c2].v))
                {
                    f[i][++cc] = b[v][c2];
                    mg(b[v][c2].u, b[v][c2].v);
                    s += b[v][c2].w;
                }
                c2++;
            }
        }
        ans = min(ans, s);
    }
    printf("%lld", ans);
    return 0;
}
