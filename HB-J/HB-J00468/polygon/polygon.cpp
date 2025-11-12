#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],dp[10005],maxn;
long long ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        maxn+=a[i];
    }
    sort(a+1,a+n+1);
    dp[0]=1;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=maxn;j>=a[i];j--)
        {
            dp[j]+=dp[j-a[i]];
            dp[j]%=998244353;
            if(j>a[i]*2)
            {
                ans+=dp[j-a[i]];
                ans%=998244353;
            }
        }
    }
    cout << ans;
    return 0;
}
