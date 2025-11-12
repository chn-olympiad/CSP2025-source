#include <bits/stdc++.h>

using namespace std;

int fa[100010] , n , m , k , dis[20] , flag = 1 , b[1200] , t , f[20] , siz[100010];
long long ans = 1e18 , sum[20];

struct node
{
    long long u , v , w;
} a[2000010] , c[2000010];

int find(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

bool cmp(node x , node y)
{
    return x.w < y.w;
}

void work(int sum)
{
    long long cnt = 0;
    for(int i = 1; i <= k; ++ i)
    {
        if(sum & 1) dis[i] = 1 , cnt += f[i];
        else dis[i] = 0;
        sum >>= 1;
    }
    for(int i = 1; i <= n + k; ++ i) fa[i] = i , siz[i] = 1;
    for(int i = 1; i <= t; ++ i)
    {
        if(c[i].u > n && dis[c[i].u - n] == 0) continue;
        // cout << i << " ";
        int x = find(c[i].u) , y = find(c[i].v);
        if(x == y) continue;
        // cout << i << " ";
        if(siz[x] < siz[y]) siz[y] += siz[x] , fa[x] = y;
        else siz[x] += siz[y] , fa[y] = x;
        cnt += c[i].w;
        // cout << i << " ";
    }
    // cout << cnt << '\n';
    ans = min(ans , cnt);
}

void dfs(int x , int sum)
{
    if(x == k + 1)
    {
        work(sum);
        return;
    }
    dfs(x + 1 , (sum << 1));
    dfs(x + 1 , (sum << 1 | 1));
}

int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++ i)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a + 1 , a + m + 1 , cmp);
    for(int i = 1; i <= n; ++ i)
    {
        fa[i] = i;
    }
    for(int i = 1; i <= m; ++ i)
    {
        int x = find(a[i].u) , y = find(a[i].v);
        if(x == y) continue;
        fa[x] = y;
        c[++ t] = a[i];
    }
    for(int i = 1; i <= k; ++ i)
    {
        cin >> f[i];
        for(int j = 1; j <= n; ++ j)
        {
            t ++;
            c[t].u = n + i , c[t].v = j;
            cin >> c[t].w;
        }
    }
    sort(c + 1 , c + t + 1 , cmp);
    // for(int i = 1; i <= t; ++ i)
    // {
    //     cout << c[i].u << " " <<c[i].v << " " << c[i].w << '\n';
    // }
    dfs(1 , 0);
    cout << ans;
    // for(int i = 1; i <= k; ++ i)
    // {
    //     m ++;
    //     a[m].u = n + k + i , a[m].v = n + i;
    //     cin >> a[m].w;
    //     if(a[i].w != 0) flag = 0;
    //     for(int j = 1; j <= n; ++ j)
    //     {
    //         m ++;
    //         a[m].u = n + i , a[m].v = j;
    //         cin >> a[m].w;
    //     }
    // }
    // if(flag == 1)
    // {

    // sort(a + 1 , a + m + 1 , cmp);
    // for(int i = 1; i <= m; ++ i)
    // {
    //     int x = find(a[i].u) , y = find(a[i].v);
    //     if(x == y) continue;
    //     fa[x] = y;
    //     ans += a[i].w;
    //     if(a[i].u > n && a[i].u <= n + k)
    //     {
    //         dis[a[i].u - n] ++;
    //         sum[a[i].u - n] += a[i].w;
    //     }
    //     if(a[i].v > n && a[i].v <= n + k)
    //     {
    //         sum[a[i].v - n] += a[i].w;
    //     }
    // }
    // for(int i = 1; i <= k; ++ i)
    // {
    //     if(dis[i] == 1)
    //     {
    //         ans -= sum[i];
    //     }
    // }
    // cout << ans;
    // return 0;
    // }
    // sort(a + 1 , a + m + 1 , cmp);
    // for(int )
    return 0;
}