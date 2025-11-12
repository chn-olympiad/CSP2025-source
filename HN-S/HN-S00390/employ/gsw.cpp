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
    LL f[N][N],g[N][N];
    int S[N];
    void sol(){
        f[0][0]=1; S[0]=b[0];
        for(int i=1;i<=n;i++) S[i]=S[i-1]+b[i];
        for(int i=0;i<n;i++){
            swap(f,g);
            for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) f[j][k]=0;
            for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) {
                if(ch[i+1]){
                    (f[j][k]+=g[j][k])%=mod;
                    for(int l=0;l<=b[j+1];l++){
                        (f[j+1][k+1+l] += g[j][k] * (S[j]-k)%mod * 
                        C(b[j+1],l)%mod * C(i-k,l)%mod * jc[l])%=mod;
                    }
                }else{
                    for(int l=0;l<=b[j+1];l++){
                        (f[j+1][k+l] += g[j][k] * 
                        C(b[j+1],l)%mod * C(i+1-k,l)%mod * jc[l])%=mod;
                    }
                    for(int l=0;l<=b[j+1];l++){
                        (f[j+1][k+1+l] += g[j][k] * (S[j]-k)%mod * 
                        C(b[j+1],l)%mod * C(i-k,l)%mod * jc[l])%=mod;
                    }
                }
            }
            // cout<<"dp::"<<i<<'\n';
            // for(int j=0;j<=n;j++){
            //     for(int k=0;k<=n;k++){
            //         cout<<f[j][k]<<' ';
            //     }
            //     cout<<'\n';
            // }
        }
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