#include<bits/stdc++.h>
#define int long long
#define pc __builtin_popcount
using namespace std;
const int MS=19,N=507,mod=998244353;
int n,m;
int s[507],c[507];
int dp[MS][(1<<18)+7];
inline void slv5(){
    dp[0][0]=1;
    for(int S=0;S<(1<<n);S++){
        for(int j=0;j<=pc(S);j++){
            for(int i=1;i<=n;i++){
                if(S&(1<<i-1))continue;
                (dp[j+((c[i]<=j)||(s[pc(S)+1]==0))][S|(1<<i-1)]+=dp[j][S])%=mod;
            }
        }
    }
    int Ans=0;
    for(int i=0;i<=n-m;i++)(Ans+=dp[i][(1<<n)-1])%=mod;
    cout<<Ans<<endl;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char t;cin>>t;
        s[i]=t-'0';
    }for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=18){
        slv5();
        return 0;
    }
}
//KEEP CALM AND CARRY ON