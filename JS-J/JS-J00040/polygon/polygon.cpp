#include <bits/stdc++.h>
using namespace std;

const int maxn=5e3+10,mod=998244353;

int a[maxn];
int n,ans=0;

int dp[maxn];

bool check()
{
    for(int i=1;i<=n;i++)
        if(a[i]!=1)
            return false;
    return true;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
        {
            cout<<1;    return 0;
        }
        else
        {
            cout<<0;    return 0;
        }
    if(check()==true)
    {
        cout<<n-2;
        return 0;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=sum;j>=1;j--)
            dp[j]=max(dp[j],dp[j-a[i]+1])%mod;
    cout<<dp[n];
    return 0;
}
