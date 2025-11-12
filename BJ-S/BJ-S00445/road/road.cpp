#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
int n,m,k,f[N],ans,c[20][N];
struct Node{
    int u,v,w,id;
}a[N<<1];

bool cmp(Node x,Node y)
{
    if(x.w==y.w)
        return x.id<y.id;
    return x.w<y.w;
}

int findfa(int x)
{
    if(x==f[x])
        return x;
    return f[x]=findfa(f[x]);
}

void solve()
{
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        int x=findfa(a[i].u),y=findfa(a[i].v);
        if(x==y)
             continue;
        f[x]=y;
        ans+=a[i].w;
    }
    return ;
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
        a[i].id=i;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
            scanf("%lld",&c[i][j]);
    }
    bool fla=true;
    for(int i=1;i<=k;i++)
    {
        bool fl=false;
        if(c[i][0]!=0)
            fla=false;
        for(int j=1;j<=n;j++)
        {
            if(c[i][j]==0)
                fl=true;
        }
        if(fl==false)
            fla=false;
    }
    for(int i=1;i<=n;i++)
        f[i]=i;
    if(k==0)
    {
        solve();
        printf("%lld",ans);
        return 0;
    }
    if(fla)
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(c[i][j]==0)
                {
                    for(int k=1;k<=n;k++)
                    {
                        if(k==j)
                            continue;
                        a[++m].u=j,a[m].v=k,a[m].w=c[i][k],a[m].id=m;
                    }
                    break;
                }
            }
        }
        solve();
        printf("%lld",ans);
        return 0;
    }
    return 0;
}
