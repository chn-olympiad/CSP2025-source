#include <bits/stdc++.h>
using namespace std;

char ch;
inline void read(int &x)
{
    x = 0;
    while(ch < '0' || ch > '9')  ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
}

int a[15][10005];
int n, m, k, c[15], fa[10015], cur[15];
bool vis[15];
long long ans;

int fnd(int x)
{
    if(fa[x] == x)  return x;
    return fa[x] = fnd(fa[x]);
}

struct Edge
{
    int x, y, len;
    bool used;
};
Edge b[1000005], b2[110005];

inline bool cmp(Edge x, Edge y)
{
    if(x.used != y.used)  return x.used > y.used;
    return x.len < y.len;
}

void dfs(int x, long long now)
{
    if(now >= ans)  return;
    if(x > k)
    {
        //printf("### dfs %lld\n", now);
        for(int i = 1; i <= n + k; i++)  fa[i] = i;

        for(int i = 1; i <= (k + 1) * n; i++)
        {
            if(!b2[i].used)  continue;
            if(b2[i].x > n && !vis[b2[i].x - n])  continue;
            if(fnd(b2[i].x) == fnd(b2[i].y))  continue;
            fa[fnd(b2[i].x)] = fnd(b2[i].y);
            //printf("! %d %d %d\n", b2[i].x, b2[i].y, b2[i].len);
            now += b2[i].len;
            if(now >= ans)  return;
        }
        ans = min(ans, now);
        return;
    }
    vis[x] = true;
    dfs(x + 1, now + c[x]);
    vis[x] = false;
    dfs(x + 1, now);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    read(n);  read(m);  read(k);
    for(int i = 1; i <= n + k; i++)  fa[i] = i;
    for(int i = 1; i <= m; i++)
    {
        read(b[i].x);  read(b[i].y);  read(b[i].len);
    }
    for(int i = 1; i <= k; i++)
    {
        read(c[i]);
        for(int j = 1; j <= n; j++)
        {
            read(a[i][j]);
        }
    }

    sort(b + 1, b + m + 1, cmp);
    for(int i = 1; i <= m; i++)
    {
        if(fnd(b[i].x) == fnd(b[i].y))  continue;
        fa[fnd(b[i].x)] = fnd(b[i].y);
        //printf("! %d %d %d\n", b[i].x, b[i].y, b[i].len);
        b[i].used = true;
        ans += b[i].len;
    }
    //printf("%lld\n", ans);
    sort(b + 1, b + m + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        b2[i] = b[i];
    }
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int id = i * n + j;
            b2[id].x = n + i;
            b2[id].y = j;
            b2[id].len = a[i][j];
            b2[id].used = true;
        }
    }
    sort(b2 + 1, b2 + (k + 1) * n + 1, cmp);

    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
