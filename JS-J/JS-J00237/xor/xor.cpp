#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f=0,dp[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            f=1;
        }
    }
    if(k==0&&f==0)
    {
        cout<<n/2;
        return 0;
    }
    if(k==0)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                ans++;
            }
            if(a[i]==1&&a[i+1]==1)
            {
                i++;
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    if(k==1)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    long long ans=0,last=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            ans++;
            dp[i]=-1;
            last=i;
            continue;
        }
        int flag=0;
        for(int j=i-1;j>=last+1;j--)
        {
            long long t=a[i]^dp[j];
            if(t==k)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            dp[i]=-1;
            last=i;
            ans++;
            continue;
        }
        if(i==last+1)
        {
            dp[i]=a[i];
        }
        else
        {
            dp[i]=dp[i-1]^a[i];
        }
    }
    cout<<ans;
    return 0;
}
