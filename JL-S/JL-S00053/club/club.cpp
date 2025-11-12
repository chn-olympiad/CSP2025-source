#include <bits/stdc++.h>
#define int long long
using namespace std;
struct nd
{
    int x,y,z;
}a[100005];
bool cmp(nd x,nd y)
{
    return (x.x-x.y)>(y.x-y.y);
}
int t,n,ans=0;
void dfs(int u,int x,int y,int z,int res)
{
    if(u==n)
    {
        ans=max(ans,res);
        return;
    }
    if(x<(n/2))
        dfs(u+1,x+1,y,z,res+a[u+1].x);
    if(y<(n/2))
        dfs(u+1,x,y+1,z,res+a[u+1].y);
    if(z<(n/2))
        dfs(u+1,x,y,z+1,res+a[u+1].z);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        bool fl=1;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
            if(a[i].z!=0)
                fl=0;
        }
        if(fl)
        {
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++)
                ans+=a[i].x;
            for(int i=n/2+1;i<=n;i++)
                ans+=a[i].y;
            printf("%lld\n",ans);
        }
        else if(n<=30)
        {
            dfs(0,0,0,0,0);
            printf("%lld\n",ans);
        }
        memset(a,0,sizeof(a));
    }
    return 0;
}
