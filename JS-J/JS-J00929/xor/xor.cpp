#include<bits/stdc++.h>
using namespace std;
int yh(int a,int b)
{
    int aa[22]={0},bb[22]={0};
    int aq=22;
    while(a)
    {
        aq=aq-1;
        aa[aq]=a%2;
        a=a/2;
    }
    int bq=22;
    while(b)
    {
        bq=bq-1;
        bb[bq]=b%2;
        b=b/2;
    }
    int ans[23-min(aq,bq)]={0};
    int w=0;
    for(int i=21;i>=min(aq,bq);i--)
    {
        w=w+1;
        if(aa[i]!=bb[i])ans[w]=1;
        else ans[w]=0;
    }
    int nans=0;
    for(int i=1;i<=w;i++)nans=nans+ans[i]*pow(2,i-1);
    return nans;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    int a[n+1];
    bool b[n+1];
    for(int i=1;i<=n;i++)b[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            b[i]=1;
            ans=ans+1;
        }
    }
    int dp[n+1];
    for(int i=0;i<=n;i++)dp[i]=0;
    while(dp[0]==0)
    {
        int j=n;
        while(dp[j]==1)
        {
            dp[j]=0;
            j=j-1;
        }
        dp[j]=1;
        int f=1;
        int yl=0;
        int s=1;
        while(dp[s]==0)s=s+1;
        for(int i=s;i<=j;i++)
        {
            if(dp[i]==0)
            {
                f=0;
                break;
            }
            if(b[i]==1)
            {
                f=0;
                break;
            }
            yl=yh(yl,a[i]);
        }
        if(yl==k && f==1)
        {
            ans=ans+1;
            for(int i=s;i<=j;i++)b[i]=1;
        }
    }
    cout<<ans;
    return 0;
}
