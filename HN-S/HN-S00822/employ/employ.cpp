#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 514;
const int mod = 998244353;
const int maxv = 1<<18;
int dp[maxv][20];
int popc[maxv];
int n,m;
char S[maxn];
int c[maxn];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>S[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(S[i]=='0') flag=false;
    }
    if(n<=18){
        for(int i=0;i<maxv;i++) popc[i]=popc[i>>1]+(i&1);
        dp[0][0]=1;
        for(int st=0;st<(1<<n);st++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<n;j++){
                    if(!((1<<j)&st)){
                        int res=i+(i>=c[j+1]||S[popc[st]+1]=='0');
                        dp[st|(1<<j)][res]=(dp[st|(1<<j)][res]+dp[st][i])%mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n-m;i++) ans=(ans+dp[(1<<n)-1][i])%mod;
        cout<<ans<<"\n";        
    }else{
        int res=1;
        for(int i=1;i<=n;i++) res=res*i%mod;
        cout<<res<<"\n";
        return 0;
    }
    return 0;
}