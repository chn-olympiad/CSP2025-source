#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long dp[2][5010];
long long a[5010],sm,mod=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    scanf("%lld",&n);
   // cerr<<'k';
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    //    cerr<<i<<endl;
        sm+=a[i];
    }
    //cerr<<'k';
    sort(a,a+n);
    dp[1][0]=1;
    long long ans=0,di=0;
   // cerr<<'k';
    for(int i=0;i<n;i++)
    {
       // cerr<<'a';
        for(int j=a[i]+1;j<=5001;j++)
        {

            ans+=dp[(i+1)%2][j];
            ans%=mod;
        }
    //    cerr<<'b';
        for(int j=0;j<=5001;j++)
        {
            dp[i%2][j]=dp[(i+1)%2][j];
        }
        dp[i%2][5001]+=dp[i%2][5001];
        dp[i%2][5001]%=mod;
     //   cerr<<'c';
        for(int j=0;j<5001;j++)
        {
            if(j+a[i]>5000)
            {
                dp[i%2][5001]+=dp[(i+1)%2][j];
                dp[i%2][5001]%=mod;
            }
            else
            {
                dp[i%2][j+a[i]]+=dp[(i+1)%2][j];
                dp[i%2][j+a[i]]%=mod;
            }
        }
      //  cerr<<'d';
    }
    printf("%lld",ans);
    return 0;
}
