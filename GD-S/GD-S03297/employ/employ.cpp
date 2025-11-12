#include<bits/stdc++.h>
using namespace std;
const int N=500,mod=998244353;
int n,m,cnt,c[N+5],b[N+5];
char s[N+5];
int fac[N+5],ifac[N+5],p[N+5];
int fpow(int a,int b=mod-2){
    int r=1;
    while(b){
        if(b&1)r=1ll*r*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return r;
}
int binom(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int ans;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=fac[0]=1;i<=N;i++)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[N]=fpow(fac[N]);
    for(int i=N-1;i>=0;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
    cin>>n>>m>>(s+1);
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)p[i]=i;
    do{
        int acc=0;
        for(int i=1;i<=n;i++){
            int ws=i-1-acc;
            if(c[p[i]]>ws&&s[i]=='1')acc++;
        }
        if(acc>=m)(ans+=1)%=mod;
    }while(next_permutation(p+1,p+1+n));
    cout<<ans;
    
}