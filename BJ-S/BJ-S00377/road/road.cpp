#include<cstdio>
#include<algorithm>
using namespace std;

struct node
{
    long long w, pos, u, v;
} z[2000005];

bool cmp(node x, node y)
{
    return x.w < y.w;
}

long long n, m, k, f[20005], minn, vis[15], c[15];

long long find(long long x)
{
    if(f[x] == x)
        return x;
    return f[x] = find(f[x]);
}

void merge(long long x, long long y)
{
    f[find(x)] = find(y);
}
long long t, ans, tot;
void dfs(long long step, long long tot, long long p)
{
    if(tot > minn) return;
    if(step > k)
    {
        for(int i = 1; i <= n + k; i ++)
            f[i] = i;
        t = 0, ans = 0;
        for(int i = 1; i <= m + k * n; i ++)
        {
            if(find(z[i].u) == find(z[i].v) || !vis[z[i].pos])
                continue;
            ans += z[i].w;
            merge(z[i].u, z[i].v);
            t ++;
            if(t == n + p - 1)
                break;
        }
        minn = min(minn, ans + tot);
        return;
    }
    dfs(step + 1, tot, p);
    vis[step] = 1;
    dfs(step + 1, tot + c[step], p + 1);
    vis[step] = 0;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &k);
    for(int i = 1; i <= m; i ++)
        scanf("%lld %lld %lld", &z[i].u, &z[i].v, &z[i].w);
    for(int i = 1; i <= k; i ++)
    {
        scanf("%lld", &c[i]);
        for(int j = 1; j <= n; j ++)
        {
            z[m + (i - 1) * n + j].u = n + i;
            z[m + (i - 1) * n + j].v = j;
            z[m + (i - 1) * n + j].pos = i;
            scanf("%lld", &z[m + (i - 1) * n + j].w);
        }
    }
    vis[0] = true;
    sort(z + 1, z + m + k * n + 1, cmp);
    for(int i = 1; i <= n; i ++)
        f[i] = i;
    for(int i = 1; i <= m + k * n; i ++)
    {
        if(find(z[i].u) == find(z[i].v) || !vis[z[i].pos])
            continue;
        minn += z[i].w;
        merge(z[i].u, z[i].v);
        tot ++;
        if(tot == n - 1)
            break;
    }
    dfs(1, 0, 0);
    printf("%lld\n", minn);
    return 0;
}
