#include<bits/stdc++.h>
using namespace std;
const int N=2e2+5;
const int M=1e5+5;
int a[M][5],dp[N][N][N],b[M],n;
int ans;
bool cmp(int x,int y)
{
    return x>y;
}
void work()
{
    int i,sum=0;
    for(i=1;i<=n;i++) b[i]=a[i][1];
    sort(b+1,b+1+n,cmp);
    for(i=1;i<=n/2;i++)
    {
        sum+=b[i];
    }
    printf("%d\n",sum);
    return ;
}
void tryit()
{
    int i,sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=max(a[i][1],max(a[i][2],a[i][3]));
    }
    printf("%d\n",sum);
    return ;
}
void sol()
{
    int i,j,k;
    bool f=true;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        if(a[i][3]!=0) f=false;
    }
    if(f)
    {
        work();
        return ;
    }
    if(n>200)
    {
        tryit();
        return ;
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=n;k++)
            {
                dp[i][j][k]=-0x3f3f3f3f;
            }
        }
    }
    dp[0][0][0]=0;
    ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            for(k=0;k<=i-j;k++)
            {
                if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
                if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
                if(j+k<i) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
            }
        }
    }
    for(i=1;i<=n/2;i++)
    {
        for(j=1;j<=n/2;j++)
        {
            if(i+j>=n/2)
            {
                ans=max(ans,dp[n][i][j]);
            }
        }
    }
    printf("%d\n",ans);
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--) sol();
    return 0;
}