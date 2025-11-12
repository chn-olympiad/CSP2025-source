#include <cstdio>
#include <algorithm>
#define project int
#define sekai main
#define pjsk 10005
#define ll long long
using namespace std;
int fa[pjsk], cnt = 0;
struct node
{
    short frm;
    short to;
    ll w;
    friend bool operator < (node a, node b)
    {
        return a.w < b.w;
    }
}edg[1000001], edgpia[pjsk];
int find(int x)
{
    if(fa[x] == x)
    {
        return x;
    }
    fa[x] = find(fa[x]);
    return fa[x];
}
ll tmp[pjsk];
bool fl[pjsk];
project sekai()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%hd %hd %lld", &edg[i].frm, &edg[i].to, &edg[i].w);
    }
    ll ans = 0;
    sort(edg + 1, edg + m + 1);
    for(int i = 1; i <= m; i++)
    {
        int fau = find(edg[i].frm);
        int fav = find(edg[i].to);
        if(fau == fav)
        {
            continue;
        }
        fa[fau] = fav;
        cnt += 1;
        edgpia[cnt].frm = edg[i].frm;
        edgpia[cnt].to = edg[i].to;
        edgpia[cnt].w = edg[i].w;
        ans += edg[i].w;
    }
    for(int i = 1; i <= k; i++)
    {
        int c;
        scanf("%d", &c);
        ll jy = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &tmp[i]);
        }
        for(int i = 1; i <= cnt; i++)
        {
            fl[i] = 0;
            if(edgpia[i].w > tmp[edgpia[i].frm] + tmp[edgpia[i].to])
            {
                fl[i] = 1;
                jy += edgpia[i].w - tmp[edgpia[i].frm] - tmp[edgpia[i].to];
            }
        }
        if(jy > c)
        {
            ans -= jy;
            ans += c;
            for(int i = 1; i <= cnt; i++)
            {
                if(!fl[i])
                {
                    continue;
                }
                edgpia[i].w = tmp[edgpia[i].frm] + tmp[edgpia[i].to];
            }
        }
    }
    printf("%lld", ans);
    return 0;
}