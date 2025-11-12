#include<bits/stdc++.h>
using namespace std;
int t,n,dp[202][202],dp2[202][202];
struct node
{
    int p[5];
}a[100005];
bool cmp(node x,node y)
{
    if(x.p[1]==y.p[1])
    {
        if(x.p[2]==y.p[2])return x.p[3]>y.p[3];
        return x.p[2]>y.p[2];
    }
    return x.p[1]>y.p[1];
}
void f3()
{
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n/2;i++)
    {
        ans+=a[i].p[1];
    }
    cout<<ans<<"\n";
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].p[1]>>a[i].p[2]>>a[i].p[3];
        }
        if(n<=200)
        {
            memset(dp,0,sizeof(dp));
            memset(dp2,0,sizeof(dp2));
            dp[1][0]=a[1].p[1];
            dp[0][1]=a[1].p[2];
            dp[0][0]=a[1].p[3];
            for(int i=2;i<=n;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    for(int k=0;k<=n;k++)
                    {
                        dp2[j+1][k]=max(dp2[j+1][k],dp[j][k]+a[i].p[1]);
                        dp2[j][k+1]=max(dp2[j][k+1],dp[j][k]+a[i].p[2]);
                        dp2[j][k]=max(dp2[j][k],dp[j][k]+a[i].p[3]);
                    }
                }
                for(int j=0;j<=n;j++)
                {
                    for(int k=0;k<=n;k++)
                    {
                        dp[j][k]=dp2[j][k];
                    }
                }
            }
            int ans=0;
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    if(j<=n/2&&k<=n/2&&(n-j-k)<=n/2&&dp[j][k]!=0)
                    {
                        ans=max(ans,dp[j][k]);
                    }
                }
            }
            cout<<ans<<"\n";
        }
        else
        {
            int q=0;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i].p[1]>>a[i].p[2]>>a[i].p[3];
                if(a[i].p[2]!=0)q=1;
                if(a[i].p[3]!=0)q=2;
            }
            if(q==2)
            {
                f3();
            }
        }
    }
    return 0;
}
