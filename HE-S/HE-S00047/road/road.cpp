#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
    ll u,v,w;
}a[1000005];

ll b[15][10005];
ll mo[15];
int n,m,k;
int fa[10005];
int vis[15];

bool cmp(node x,node y)
{
    return x.w < y.w;
}

int fin(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = fin(fa[x]);
}

ll kru()
{
    sort(a+1,a+m+1,cmp);

    int cnt = 0;
    ll ans = 0;
    for(int i = 1;i <= m;i++)
    {
        int u = a[i].u;
        int v = a[i].v;

        int f1 = fin(u),f2 = fin(v);

        if(f1 != f2)
        {
            fa[f1] = f2;
            long long minn = 1e18;
            int minp = 0;
            if(n-cnt-1 <= k)
            {
                 for(int p = 1;p <= n;p++)
                {
                    if(p == u) continue;
                    for(int j = 1;j <= k;j++)
                    {
                        if(vis[j] == 1) continue;

                        if(mo[j]+b[j][u]+b[j][p] < minn)
                        {

                            minn = mo[j]+b[j][u]+b[j][p];

                            minp = j;
                        }
                    }
                }

                for(int p = 1;p <= n;p++)
                {
                    if(p == v) continue;
                    for(int j = 1;j <= k;j++)
                    {
                        if(vis[j] == 1) continue;
                        if(mo[j]+b[j][v]+b[j][p] < minn)
                        {
                            minn = mo[j]+b[j][v]+b[j][p];
                            minp = j;
                        }
                    }
                }

                vis[minp] = 1;
            }

            cout << minn << " " << a[i].w << "\n";
            cnt++;
            ans += min(minn,a[i].w);

            if(cnt == n-1) return ans;
        }
    }
    return -1;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d %d %d",&n,&m,&k);

    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d %lld",&a[i].u,&a[i].v,&a[i].w);
    }

    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 1;i <= k;i++)
    {
        int k1;
        scanf("%lld",&k1);
        mo[i] = k1;

        for(int j = 1;j <= n;j++)
        {
            scanf("%lld",&b[i][j]);
        }
    }

    cout << kru();

    return 0;
}
