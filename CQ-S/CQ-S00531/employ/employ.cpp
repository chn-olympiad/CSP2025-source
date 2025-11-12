#include<bits/stdc++.h>
#define mod 998244353
#define int long long
#define N 505
using namespace std;
namespace shan{
    int n,m;
    int s[N],c[N];
    int dp[2][N][N];
    void upd(int &x,int y){x=(x+y)%mod;}
    int C[N][N],all[N],fac[N];
    void __init__(){
        int v=500;
        fac[0]=1;
        for(int i=1;i<=v;i++)fac[i]=fac[i-1]*i%mod;
        for(int i=0;i<=v;i++){
            C[i][0]=1;
            for(int j=1;j<=i;j++)
                C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    signed main(){
        __init__();
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            char ch;cin>>ch;
            s[i]=ch=='1';
        }
        for(int i=1;i<=n;i++){
            int p;cin>>p;
            c[p]++;
        }
        for(int i=n;i>=0;i--)all[i]=all[i+1]+c[i];
        dp[0][0][n-c[0]]=1;
        for(int i=0;i<n;i++){
            int I=i&1,II=I^1;
            memset(dp[II],0,sizeof dp[II]);
            for(int j=0;j<=i;j++){
                for(int k=0;k<=n;k++){
                    int me=dp[I][j][k];
                    if(!me)continue;
                    int low=n-i-k;//<= i-j
                    int pre_k=all[i-j+1]-k;
                    if(s[i+1]&&k)upd(dp[II][j+1][k-1],me);
                    for(int used=max(0ll,c[i-j+1]-k);used<=c[i-j+1];used++)
                        upd(dp[II][j][k-c[i-j+1]+used],me*C[c[i-j+1]][used]%mod*C[pre_k][used]%mod*fac[used]%mod*low);
                    if(!s[i+1]){
                        for(int used=max(0ll,c[i-j+1]-k);used<c[i-j+1];used++)
                            upd(dp[II][j][k-c[i-j+1]+used],me*C[c[i-j+1]-1][used]%mod*C[pre_k][used]%mod*fac[used]%mod*c[i-j+1]);
                        for(int used=max(0ll,c[i-j+1]+1-k);used<=c[i-j+1];used++)
                            upd(dp[II][j][k-c[i-j+1]+used-1],me*C[c[i-j+1]][used]%mod*C[pre_k][used]%mod*fac[used]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++){
            int me=dp[n&1][i][0];
            upd(ans,me*fac[all[n-i+1]]);
        }
        cout<<ans;
        return 0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    shan::main();
    return 0;
}
/*
Lord knows i can't change
oh young man i can't change

much easier than last year
18:15

*2100 ?
*/