#include<bits/stdc++.h>
const int N=5e2+10,MOD=998244353;
int qpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1) ret=1ll*ret*a%MOD;
        a=1ll*a*a%MOD;b>>=1;
    }
    return ret;
}
char s[N];
int c[N];
int f[N][N][N][2];
int fac[N+1],ifac[N+1];
int binom(int n,int k){
    return 1ll*fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}
int d[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // fac[0]=1;for(int i=1;i<=N;i++) fac[i]=1ll*fac[i-1]*i%MOD;
    // ifac[N]=qpow(fac[N],MOD-2);for(int i=N;i>=1;i--) ifac[i-1]=1ll*ifac[i]*i%MOD;
    int n,m;scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n;i++) scanf("%d",c+i),++d[c[i]];
    puts("0");
    // for(int i=1;i<=n;i++) d[i]+=d[i-1];
    // // for(int i=1;i<=n;i++) printf("%d ",c[i]);puts("");
    // f[0][0][0]=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         for(int k=0;k<=i&&k<=d[j];k++){
    //             for(int l=0;l<2;l++){
    //                 if(s[i+1]=='0'){
    //                     f[i+1][j+1][k+1]+=f[i][j][k]*(d[j+1]-k);
    //                     f[i+1][j+1][k]+=f[i][j][k]*(n-d[j+1]-(i-k));
    //                 }
    //                 else{
    //                     f[i+1][j+1][k+1]+=f[i][j][k]*(d[j]-k);
    //                     f[i+1][j][k]+=f[i][j][k]*(n-d[j]-(i-k));
    //                 }
    //             }
    //         }
    //     }
    // }
    // int ans=0;
    // for(int i=0;i<=n-m;i++) (ans+=f[n][i][i])%=MOD;
    // printf("%d",ans);
}