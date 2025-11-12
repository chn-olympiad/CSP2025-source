#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
struct node
{
    int u,v;
    ll w;
}edge[2000010];
int fa[200010];
ll c[15],a[15][100010];
node add[200010];
bool cmp(node x,node y)
{
    return x.w < y.w;
}
ll aans = LLONG_MAX;
int fi(int x)
{
    if(fa[x] == x)
        return x;
    return fa[x] = fi(fa[x]);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //cin >> n >> m >> k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++)
        //cin >> edge[i].u >> edge[i].v >> edge[i].w;
        scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    sort(edge + 1,edge + m + 1,cmp);
    bool flag = 0;
    for(int i = 1;i <= k;i++)
    {
        //cin >> c[i];
        scanf("%lld",&c[i]);
        if(c[i])
            flag = 1;
        for(int j = 1;j <= n;j++)
            //cin >> a[i][j];
            scanf("%lld",&a[i][j]);
    }
    if(flag)
    {
        int o = (1 << k) - 1;
        while(o >= 0)
        {
            int cnt = 0;
            ll ans = 0;
            int p = o;
            o--;
            for(int i = 1;i <= k;i++)
            {
                if(p % 2)
                {
                    for(int j = 1;j <= n;j++)
                        add[++cnt] = {i + n,j,a[i][j]};
                    ans += c[i];
                }
                p /= 2;
            }
            sort(add + 1,add + cnt + 1,cmp);
            for(int i = 1;i <= n + k + 1;i++)
                fa[i] = i;
            int pos1 = 1,pos2 = 1;
            int sum = 0;
            for(int i = 1;i <= m + cnt;i++)
            {
                int u1,v1,w1;
                if(pos1 > m || (pos2 <= cnt && add[pos2].w <= edge[pos1].w))
                {
                    u1 = add[pos2].u,v1 = add[pos2].v,w1 = add[pos2].w;
                    pos2++;
                }
                else
                {
                    u1 = edge[pos1].u,v1 = edge[pos1].v,w1 = edge[pos1].w;
                    pos1++;
                }
                int fu = fi(u1),fv = fi(v1);
                if(fu == fv)
                    continue;
                fa[fu] = fv;
                ans += w1;
                //cout << u1 << " " << v1 << " " << w1 << " " << ans << endl;
                sum++;

                if(sum == n + cnt - 1)
                    break;
            }
            //if(ans < aans)
                //cout << ans << " "<< o << endl;
            aans = min(aans,ans);
        }
        printf("%lld",aans);
    }
    else
    {
        int qwq = m,sum = 0;
        ll ans = 0;
        for(int i = 1;i <= n + k + 1;i++)
            fa[i] = i;
        for(int i = 1;i <= k;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                edge[++qwq] = {i + n,j,a[i][j]};
            }
        }
        sort(edge + 1,edge + qwq + 1,cmp);
        for(int i = 1;i <= qwq;i++)
        {
            int u1 = edge[i].u,v1 = edge[i].v,w1 = edge[i].w;
            int fu = fi(u1),fv = fi(v1);
            if(fu == fv)
                continue;
            fa[fu] = fv;
            ans += w1;
            //cout << u1 << " " << v1 << " " << w1 << " " << ans << endl;
            sum++;
            if(sum == n + k - 1)
                break;
        }
        printf("%lld",ans);
        return 0;
    }
}
