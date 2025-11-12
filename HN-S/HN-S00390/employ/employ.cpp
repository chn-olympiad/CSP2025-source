#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1010,mod=998244353;
int n,m,b[N],ch[N];
LL jc[N],ijc[N];
LL qpow(LL a,LL b){
    LL sum=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) sum=sum*a%mod;
    return sum;
}
LL C(int n,int m){
    if(n<m || m<0) return 0;
    return jc[n]*ijc[m]%mod*ijc[n-m]%mod;
}
void read(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        ch[i]=(c=='1');
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b[x]++;
    }
    jc[0]=ijc[0]=1;
    for(int i=1;i<N;i++){
        jc[i]=jc[i-1]*i%mod;
        ijc[i]=qpow(jc[i],mod-2);
    }
}
namespace sub1{
    LL f[N][N],g[N][N],W[N];
    int S[N];
    void dp(){
        for(int i=0;i<n;i++){
            for(int j=0;j<=i+1;j++) for(int k=0;k<=i+1;k++) g[j][k]=f[j][k],f[j][k]=0;
            LL t1; int p,l,lim;
            for(int j=0;j<=i;j++){
                p=b[j+1];
                for(l=0;l<=p;l++) W[l]=C(p,l) * jc[l]%mod;
                for(int k=0;k<=i;k++) if(g[j][k]){
                    t1=g[j][k] * (S[j]-k)%mod;
                    lim=min(p,i+1-k);
                    if(ch[i+1]){
                        (f[j][k]+=g[j][k])%=mod;
                        for(l=0;l<=lim;l++){
                            (f[j+1][k+1+l] += t1 * W[l]%mod * C(i-k,l))%=mod;
                        }
                    }else{
                        for(l=0;l<=lim;l++){
                            (f[j+1][k+l] += g[j][k] * W[l]%mod * C(i+1-k,l))%=mod;
                            (f[j+1][k+1+l] += t1 * W[l]%mod * C(i-k,l))%=mod;
                        }
                    }
                }
            }
        }
    }
    void sol(){
        f[0][0]=1; S[0]=b[0];
        for(int i=1;i<=n;i++) S[i]=S[i-1]+b[i];
        dp();
        LL ans=0;
        for(int j=0;j<=n-m;j++){
            (ans+=f[j][S[j]] * jc[n-S[j]])%=mod;
        }
        ans=(ans+mod)%mod;
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    read();
    sub1::sol();
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
    return 0;
}