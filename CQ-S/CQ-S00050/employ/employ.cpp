#include<bits/stdc++.h>
using namespace std;
constexpr int mod=998244353;
int n,m,C[505][505],dp[2][505][505],c[505],cnt[505],sum[505],suf[505],ans;
long long fac[505];
string s;
inline int mo(int x){
    return x>=mod?x-mod:x;
}
inline void update(int&x,int y){
    x=mo(x+y);
}
inline int val(int x,int y){
    return x<y||y<0?0:C[x][y];
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    fac[0]=1;
    for(int i=0;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++) C[i][j]=mo(C[i-1][j]+C[i-1][j-1]);
    }
    for(int i=1;i<=n;i++) scanf("%d",&c[i]),cnt[c[i]]++,fac[i]=fac[i-1]*i%mod;
    if(m==n){
        ans=fac[n];
        for(int i=1;i<=n;i++){
            if(s[i-1]!='1'||c[i]==0){
                ans=0;
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    sum[0]=cnt[0];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+cnt[i]%mod;
    for(int i=n;~i;i--) suf[i]=suf[i+1]+cnt[i]%mod;
    dp[0][0][0]=1;
    for(int i=0,t=0;i<n;i++,t^=1){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=suf[j+1];k++){
                if(!dp[t][j][k]) continue;
                if(s[i]=='0'){
                    for(int l=0;l<=min(k,cnt[j+1]);l++){
                        int tmp=(long long)dp[t][j][k]*C[cnt[j+1]][l]%mod*C[k][l]%mod*fac[l]%mod;
                        update(dp[t^1][j+1][k-l],(long long)tmp*(sum[j+1]-l-(i-k))%mod),update(dp[t^1][j+1][k-l+1],tmp);
                    }
                }
                else{
                    update(dp[t^1][j][k+1],dp[t][j][k]);
                    for(int l=0;l<=min(k,cnt[j+1]);l++){
                        update(dp[t^1][j+1][k-l],(long long)dp[t][j][k]*C[cnt[j+1]][l]%mod*C[k][l]%mod*fac[l]%mod*(sum[j]-(i-k))%mod);
                    }
                }
                dp[t][j][k]=0;
            }
        }
    }
    for(int i=0;i<=n-m;i++) for(int j=0;j<=suf[i+1];j++) ans=mo(ans+dp[n&1][i][j]);
    cout<<ans<<endl;
    return 0;
}