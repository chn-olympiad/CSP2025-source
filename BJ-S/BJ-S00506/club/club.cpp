#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010],dp[100010][5];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        bool flag1=false,flag2=false,flag3=false;
        cin>>n;
        for(int i=1;i<=n;i++)dp[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(a[i])flag1=true;
            if(b[i])flag2=true;
            if(c[i])flag3=true;
        }
        if(!flag2&&!flag3)
        {
            long long sum=0;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++)sum+=a[i];
            cout<<sum<<endl;
            continue;
        }
        else if(!flag1&&!flag3)
        {
            long long sum=0;
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n/2;i++)sum+=b[i];
            cout<<sum<<endl;
            continue;
        }
        else if(!flag1&&!flag2)
        {
            long long sum=0;
            sort(c+1,c+n+1,cmp);
            for(int i=1;i<=n/2;i++)sum+=c[i];
            cout<<sum<<endl;
            continue;
        }
        else if(!flag3)
        {
            for(int i=1;i<=n;i++)
            {
                long long t1=dp[i-1][2]+b[i];
                long long t2=dp[i-1][1]+a[i];
                dp[i][1]=max(dp[i][1],t1);
                dp[i][2]=max(dp[i][2],t2);
            }
            cout<<max(dp[n][1],dp[n][2])<<endl;
            continue;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                long long t1=max(dp[i-1][2]+b[i],dp[i-1][3]+c[i]);
                long long t2=max(dp[i-1][1]+a[i],dp[i-1][3]+c[i]);
                long long t3=max(dp[i-1][2]+b[i],dp[i-1][1]+a[i]);
                dp[i][1]=max(dp[i][1],t1);
                dp[i][2]=max(dp[i][2],t2);
                dp[i][3]=max(dp[i][3],t3);
            }
            cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
        }
    }
    return 0;
}
