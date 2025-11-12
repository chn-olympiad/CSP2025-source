#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    int b;
    int c;
}a[110000];
bool cmp(node x,node y)
{
    return (x.a-x.b)>(y.a-y.b);
}
int dp[5][220][220];
int b[110000];
int c[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,i,j,k,f,ans,x,y,pre,now;
    scanf("%d",&t);
    while(t--)
    {
        f=1;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
            if(a[i].c!=0)f=0;
        }
        if(f==1)
        {
            ans=0;
            sort(a+1,a+n+1,cmp);
            for(i=1;i<=n/2;i++)
            {
                b[i]=a[i].a;
            }
            for(i=(n/2)+1;i<=n;i++)
            {
                b[i]=a[i].b;
            }
            sort(b+1,b+n+1);
            for(i=1;i<=(n/2);i++)
            {
                if(b[i]<0)b[i]=0;
                else
                {
                    break;
                }
            }
            for(i=1;i<=n;i++)
            {
                ans+=b[i];
            }
            printf("%d\n",ans);
            continue;
        }
        if(n<=200)
        {
            pre=1;
            now=0;
            memset(dp,-1,sizeof(dp));
            dp[pre][0][0]=0;
            ans=0;
            for(i=1;i<=n;i++)
            {
                for(j=0;j<=n/2&&j<=i;j++)
                {
                    for(k=max(0,i-j-(n/2));k<=n/2&&(j+k)<=i;k++)
                    {
                        if(j>0)dp[now][j][k]=max(dp[now][j][k],dp[pre][j-1][k]+a[i].a);
                        if(k>0)dp[now][j][k]=max(dp[now][j][k],dp[pre][j][k-1]+a[i].b);
                        if(i-j-k>0)dp[now][j][k]=max(dp[now][j][k],dp[pre][j][k]+a[i].c);
                        if(i==n)ans=max(ans,dp[now][j][k]);
                    }
                }
                swap(now,pre);
            }
            printf("%d\n",ans);
            continue;
        }
    }
    return 0;
}
