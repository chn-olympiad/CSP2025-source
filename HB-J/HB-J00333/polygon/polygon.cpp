#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=1000001,MOD=998244353;
ll v[N],a[N],n,dp[N],ans=0,mv;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    scanf("%lld",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        mv=max(a[i],mv);
    }
    sort(a+1,a+1+n);
    mv*=2;
    ll cnt=0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        cnt*=2;
        if(cnt>MOD)
        {
            cnt%=MOD;
        }
        for(int j=mv-a[i]+1;j<=mv;j++)
        {
            cnt+=dp[j];
            if(cnt>MOD)
            {
                cnt%=MOD;
            }
        }
        for(int j=a[i]+1;j<=mv;j++)
        {
            if(a[i]+j<=mv)ans+=dp[j];
            if(ans>MOD)
            {
                ans%=MOD;
            }
            //out<<dp[j]<<" ";
        }
       // cout<<endl;
        for(int j=mv;j>=a[i];j--)
        {
            dp[j]+=dp[j-a[i]];
            if(dp[j]>MOD)
            {
                dp[j]%=MOD;
            }
        }
        /*cout<<cnt<<endl;
        for(int j=0;j<=mv;j++)
        {
            cout<<dp[j]<<" ";
        }
        cout<<endl;
        cout<<ans<<endl<<endl;*/
    }
    /*for(int i=1;i<=n;i++)
    {
        dp[a[i]]--;
        for(int j=1;j<=n;j++)
        {
            if(j==i)continue;
            dp[a[i]+a[j]]--;
        }
    }*/
    ans+=cnt;
    ans%=MOD;
    //ans-=n*(n-1)/2;
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=mv;j++)
        {
            if(j>i*2)
            {
                ans+=dp[j];
            }
        }
    }*/
    printf("%lld",ans);
    return 0;
}