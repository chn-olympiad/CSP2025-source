#include<bits/stdc++.h>
using namespace std;
long long t,n,d[100005][5],f[205][205][205],ans;
void dfs(long long a,long long b,long long c,long long sum,long long r)
{
   // if(sum<f[a][b][c])return ;
    f[a][b][c]=max(sum,f[a][b][c]);
    if(r==n)
    {
        ans=max(ans,f[a][b][c]);
        return ;
    }
    for(int i=r+1;i<=n;i++)
    {
        if(a+1<=n/2)dfs(a+1,b,c,sum+d[i][1],i);
        if(b+1<=n/2)dfs(a,b+1,c,sum+d[i][2],i);
        if(c+1<=n/2)dfs(a,b,c+1,sum+d[i][3],i);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.ans","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        ans=-0x3f3f3f3f;
        memset(f,-0x3f,sizeof(f));
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld%lld",&d[i][1],&d[i][2],&d[i][3]);
        dfs(0,0,0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
