#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int read(){
    int res=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+(c-'0'),c=getchar();
    return res*f;
}
void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int gch(){
    char c=getchar();
    while(c!='0'&&c!='1')c=getchar();
    return c=='1';
}
const int maxn=505;
const int mod=998244353;
int n,m,a[maxn],c[maxn],dp[maxn][maxn][maxn],sum[maxn],fac[maxn],inv[maxn];
int qpow(int x,int y){int res=1;for(;y;y>>=1,x=x*x%mod)if(y&1)res=res*x%mod;return res;}
int C(int x,int y){return fac[x]*inv[x-y]%mod*inv[y]%mod;}
void solve(){
    n=read(),m=read();
    fac[0]=1;
    for(int i=1;i<=n;i++)a[i]=gch(),fac[i]=fac[i-1]*i%mod;
    inv[n]=qpow(fac[n],mod-2);
    for(int i=n;i>=1;i--)inv[i-1]=inv[i]*i%mod;
    for(int i=1;i<=n;i++)c[read()]++;sum[0]=c[0];
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+c[i];
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=i;k++){
                for(int l=0;l<=k&&l<=c[j+1];l++){
                    dp[i][j+1][k-l]+=dp[i-1][j][k]*C(k,l)%mod*(sum[j]-(j-k+i)/2)%mod;
                    if(a[i]==0){
                        if(l<c[j+1])dp[i][j+1][k-l]+=dp[i-1][j][k]*C(k,l)%mod;
                        dp[i][j+1][k-l+1]+=dp[i-1][j][k]*C(k,l);//
                    }
                }
                if(a[i]==1)dp[i][j][k+1]+=dp[i-1][j][k];
            }
        }
    }
    // for(int i=1;i<=n;i++)for(int j=0;j<=i;j++)for(int k=0;k<=i;k++){
    //     printf("dp[%d][%d][%d] = %d\n",i,j,k,dp[i][j][k]);
    // }
    int ans=0;
    for(int i=0;i<=n-m;i++)ans=(ans+dp[n][i][0])%mod;
    for(int i=0;i<=n;i++)ans=ans*fac[c[i]]%mod;
    write(ans);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int T=1;
    while(T--)solve();
    return 0;
}
