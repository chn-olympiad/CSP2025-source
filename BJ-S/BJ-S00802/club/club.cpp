#include<iostream>
#include<algorithm>
using namespace std;
int a[100010],b[100010],c[100010],dp[2][210][210][210];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        bool flag1=0,flag2=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0) flag1=1;
            if(c[i]!=0) flag2=1;
        }
        if(!flag1&&!flag2)
        {
            sort(a+1,a+n+1);
            for(int i=n;i>=n/2+1;i--) ans+=a[i];
            cout<<ans<<endl;
            continue;
        }
        if(!flag2&&n>200)
        {
            int cnt1=0,cnt2=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]>b[i]) cnt1++;
                else cnt2++;
                ans+=max(a[i],b[i]);
            }
            if(cnt1>cnt2)
            {
                for(int i=1;i<=n;i++)
                {
                    c[i]=a[i]-b[i];
                    if(a[i]<b[i]) c[i]=1e9;
                }
                sort(c+1,c+n+1);
                for(int i=1;i<=cnt1-n/2;i++) ans-=c[i];
            }
            else if(cnt2>cnt1)
            {
                for(int i=1;i<=n;i++)
                {
                    c[i]=b[i]-a[i];
                    if(a[i]>b[i]) c[i]=1e9;
                }
                sort(c+1,c+n+1);
                for(int i=1;i<=cnt2-n/2;i++) ans-=c[i];
            }
            cout<<ans<<endl;
            continue;
        }
        for(int j=0;j<=n/2;j++)
        {
            for(int l=n/2-j;l<=n/2;l++)
            {
                int k=n-j-l;
                dp[0][j][l][k]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                for(int l=0;l<=i;l++)
                {
                    int k=i-j-l;
                    dp[i%2][j][l][k]=0;
                    if(j>0) dp[i%2][j][l][k]=max(dp[i%2][j][l][k],dp[(i-1)%2][j-1][l][k]+a[i]);
                    if(l>0) dp[i%2][j][l][k]=max(dp[i%2][j][l][k],dp[(i-1)%2][j][l-1][k]+b[i]);
                    if(k>0) dp[i%2][j][l][k]=max(dp[i%2][j][l][k],dp[(i-1)%2][j][l][k-1]+c[i]);
                }
            }
        }
        for(int j=0;j<=n/2;j++)
        {
            for(int l=n/2-j;l<=n/2;l++)
            {
                int k=n-j-l;
                ans=max(ans,dp[n%2][j][l][k]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
