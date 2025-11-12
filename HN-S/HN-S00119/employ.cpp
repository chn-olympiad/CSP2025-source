#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define MOD 998244353

int n,m,c[505],full,dp[262144][20];
string s;
inline int add(rint x,rint y){
    x+=y;
    if(x>=MOD)x-=MOD;
    return x;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s,s=" "+s;
    for(rint i=1;i<=n;i++)cin>>c[i];
    if(n<=18){
        full=(1<<n)-1,dp[0][0]=1;
        for(rint i=0;i<full;i++){
            rint cnt=0;
            for(rint j=1;j<=n;j++)if((i>>j-1)&1)cnt++;
            for(rint j=1;j<=n;j++){
                if((i>>j-1)&1)continue;
                for(rint k=0;k<=cnt;k++){
                    if(s[cnt+1]=='0')dp[i+(1<<j-1)][k]=add(dp[i+(1<<j-1)][k],dp[i][k]);
                    else{
                        if(cnt-k>=c[j])dp[i+(1<<j-1)][k]=add(dp[i+(1<<j-1)][k],dp[i][k]);
                        else dp[i+(1<<j-1)][k+1]=add(dp[i+(1<<j-1)][k+1],dp[i][k]);
                    }
                }
            }
        }
        rint res=0;
        for(rint i=m;i<=n;i++)res=add(res,dp[full][i]);
        cout<<res<<"\n";    
        return 0;
    }
    rint res=1;
    for(rint i=1;i<=n;i++){
        res=1ll*res*i%MOD;
        if(s[i]=='0'||!c[i])res=0;
    }
    cout<<res<<"\n";
    return 0;
}