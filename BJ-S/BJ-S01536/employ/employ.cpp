#include<iostream>
#include<string>
using namespace std;

#define ll long long
const int maxn=500+10,mod=998244353;
int n,m,ci[maxn],dp[1<<18][20]; string s;

// dp[i][j]：i集合中的人已经在前popcount(i)次面试里出现过了，目前j人通过了面试，方案数计数

int main(){
freopen("employ.in", "r", stdin);
freopen("employ.out", "w", stdout);
    cin>>n>>m>>s; s=" "+s;
    for(int i=1;i<=n;i++)cin>>ci[i];
    int cnt=0; for(int i=1;i<=n;i++)if(s[i]=='1')cnt++;
    /*if(cnt==n){
        for(int i=1;i<=n;i++)if(ci[i]==0)cnt--;
        if(cnt<m){
            cout<<0<<endl;
            return 0;
        }
        int ans=1;
        for(int i=1;i<=n;i++)ans=(ll)ans*i%mod;
        cout<<ans<<endl;
        return 0;
    }*/
    if(m==n){
        for(int i=1;i<=n;i++)if(ci[i]==0)cnt--;
        if(cnt!=n){
            cout<<0<<endl;
            return 0;
        }
        int ans=1;
        for(int i=1;i<=n;i++)ans=(ll)ans*i%mod;
        cout<<ans<<endl;
        return 0;
    }
    dp[0][0]=1;
    for(int mask=0;mask<(1<<n)-1;mask++)for(int j=0;j<=n;j++){
        int popcount=__builtin_popcount(mask);
        if(!dp[mask][j])continue;
        for(int i=0;i<n;i++)if(((mask>>i)&1)^1){
            if(s[popcount+1]=='1'&&popcount-j<ci[i+1])dp[mask^(1<<i)][j+1]=(dp[mask^(1<<i)][j+1]+dp[mask][j])%mod;
            else dp[mask^(1<<i)][j]=(dp[mask^(1<<i)][j]+dp[mask][j])%mod;
        }
    }
    int ans=0;
   for(int i=m;i<=n;i++)ans=(ans+dp[(1<<n)-1][i])%mod;
   cout<<ans<<endl;
}