#include<bits/stdc++.h>
using namespace std;
using i64=long long;
constexpr i64 mod=998244353;
int n,m,cnt[510],pres[510],up[510];
char str[510];
i64 C[510][510],fac[510],f[510][510],g[510][510];
int main(){
   freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
   scanf("%d%d%s",&n,&m,str+1);
   fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
   for(int i=0;i<=n;i++)C[i][0]=1;
   for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
   for(int i=1,x;i<=n;i++){
      scanf("%d",&x),cnt[x]++;
   }
   for(int i=0;i<=n;i++)pres[i]=(i?pres[i-1]:0)+cnt[i];
   for(int i=n;i>=0;i--)up[i]=up[i+1]+cnt[i];
   f[0][0]=1;
   for(int i=1;i<=n;i++){
      for(int j=0;j<=i;j++)for(int k=0;k<=i;k++)g[j][k]=f[j][k],f[j][k]=0;
      if(str[i]=='0'){
         for(int j=0;j<i;j++)for(int k=0;k<i;k++){
            (f[j+1][k]+=g[j][k]*(pres[j]-(i-1-k)))%=mod;
            (f[j+1][k+1]+=g[j][k])%=mod;
         }
      }else{
         for(int j=0;j<i;j++)for(int k=0;k<i;k++){
            (f[j+1][k]+=g[j][k]*(pres[j]-(i-1-k)))%=mod;
         }
      }
      for(int j=0;j<=i;j++){
         for(int k=0;k<=min(i,up[j]);k++){
            for(int l=1;l<=min(k,cnt[j]);l++){
               (f[j][k-l]+=f[j][k]*C[k][l]%mod*C[cnt[j]][l]%mod*fac[l])%=mod;
            }
         }
      }
      if(str[i]=='1'){
         for(int j=0;j<i;j++)for(int k=0;k<i;k++){
            (f[j][k+1]+=g[j][k])%=mod;
         }
      }
   }
   i64 ans=0;
   for(int j=0;j<=n-m;j++)(ans+=f[j][up[j+1]]*fac[up[j+1]])%=mod;
   printf("%lld\n",ans);
   return 0;
}