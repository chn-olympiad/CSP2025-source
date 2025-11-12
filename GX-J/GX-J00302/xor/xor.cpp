#include<bits/stdc++.h>
using namespace std;
long long sum[500005],ans,dp[500005];
long long xor_o(long long a,long long b)
{
    long long num=1;
    while(a+b>0)
    {
        num*=10;
        if(a%2-b%10!=0) num++;
        a/=2;
        b/=10;
    }
    return num;
}
long long xor_t(long long a,long long b)
{
    long long num=1;
    while(a+b>0)
    {
        num*=10;
        if(a%10-b%10!=0) num++;
        a/=10;
        b/=10;
    }
    int y=num;
        num=0;
        while(y!=1)
        {
            num*=10;
            num+=y%10;
            y/=10;
        }
    return num;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin >>n>>k;
    int y=k;
    k=1;
    while(y!=0)
    {
        k*=10;
        k+=y%2;
        y/=2;
    }
    y=k;
    //cout<<k<<endl;
    k=0;
    while(y!=1)
    {
        k*=10;
        k+=y%10;
        y/=10;
    }
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin >>x;
        sum[i]=xor_o(x,sum[i-1]);
        y=sum[i];
        sum[i]=0;
        while(y!=1)
        {
            sum[i]*=10;
            sum[i]+=y%10;
            y/=10;
        }
        //cout<<sum[i]<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            dp[j]=dp[j-1];
            if(xor_t(sum[j],sum[i-1])==k)
                {

                dp[j]=min(dp[j-1]+1,dp[i-1]+1);

            }ans=max(ans,dp[j]);
            //cout<<dp[j]<<" "<<j<<endl;
        }
    }
    cout<<ans;//<<" "<<k;
    //cout<<xor_o(4,xor_t(xor_o(4,101),10));
    return 0;
}
