#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],ans;
bool f;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i) 
    {
        cin>>a[i];
        if(a[i]!=1&&a[i]!=0) f=true;
    } 
    if(n>1000&&!f&&k<=1)
    {
        int gs1=0;
        for(int i=1;i<=n;++i)
            if(a[i]==1)
                gs1++;
        if(k==1) cout<<gs1;
        else
        {
            int ls=0;
            for(int i=1;i<=n;++i)
                if(a[i]==1&&a[i+1]==1)
                {
                    i++;
                    ls++;
                }
            cout<<n-gs1+ls;
        }
        return 0;
    }
    int yh=0;
    for(int i=1;i<=n;++i)
    {
        yh=yh^a[i];
        int ls=yh,lsmax=0;
        if(yh==k) dp[i]=1;
        for(int j=1;j<=i-1;++j)
        {
            ls=ls^a[j];
            lsmax=max(lsmax,dp[j]);
            if(ls==k) dp[i]=max(dp[i],lsmax+1);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}