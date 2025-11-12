#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010],dp[5010],cnt[5010],ans;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[1]=0;
    dp[2]=0;
    for(int i=3;i<=n;i++)
    {
        for(int j=2;j<i;j++)
        {
            for(int z=1;z<j;z++)
            {
                if(a[j]+a[z]>=a[i])cnt[i]=cnt[j]+cnt[z]+1;
                if(a[j]+a[z]>a[i])dp[i]+=(cnt[j]+cnt[z]+1);
            }
        }
    }
    for(int i=3;i<=n;i++)
    {
        ans+=dp[i];
    }
    cout<<ans;
    return 0;
}
