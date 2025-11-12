#include <bits/stdc++.h>
using namespace std;
long long n,a[10010],dp[10010],k,sum,t=1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sum=a[1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>t;j--)
        {
            sum=sum^a[j];
        }
        if(sum==k)
        {
            t=i+1;
            sum=a[i+1];
            dp[i]=dp[i-1]+1;
        }
        else
        {
            sum=a[t];
            dp[i]=dp[i-1];
        }
    }
    cout<<dp[n];
    return 0;
}
