#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+5;
const ll mod=998244353;
int a[N],n,m,all,c[N],t[N];
char aa[N];ll f[(1<<18)][18],g[N];
void solve(){
    f[0][0]=1;
    for(int S=0;S<(1<<n);S++){
        int cc=__builtin_popcount(S);
        for(int j=0;j<=cc;j++){
            if(!f[S][j])continue;
            for(int z=0;z<n;z++){
                if((S>>z)&1)continue;
                int to=(S|(1<<z));
                if(!a[cc+1])f[to][j]=(f[to][j]+f[S][j])%mod;
                else{
                    if(cc-j>=t[z+1])f[to][j]=(f[to][j]+f[S][j])%mod;
                    else f[to][j+1]=(f[to][j+1]+f[S][j])%mod;
                }
            }
        }
    }
    ll ss=0;
    for(int i=m;i<=n;i++)
    ss=(ss+f[(1<<n)-1][i])%mod;
    printf("%lld\n",ss);
}
int main(){
    //freopen("employ4.in","r",stdin);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);scanf("%s",aa+1);all=0;
    for(int i=1;i<=n;i++)a[i]=int(aa[i]-'0'),all+=a[i];
    for(int i=1,x;i<=n;i++)scanf("%d",&t[i]),c[t[i]]++;
    if(m==n){
        if(c[0]||all!=n)puts("0");
        else{
            ll ss=1;
            for(int i=1;i<=n;i++)ss=ss*i%mod;
            printf("%lld\n",ss);
        }
    }
    else if(n<=18)solve();
    else{
        for(int i=1;i<=n;i++)c[i]+=c[i-1];
        int cc=0;g[0]=1;
        for(int i=1;i<=n;i++){
            g[i]=g[i-1];if(!a[i])continue;
            g[i]=g[i-1]*(c[i-1]-cc)%mod;
            cc++;
        }
        ll ss=1;
        for(int i=1;i<=n;i++)ss=ss*i%mod;
        for(int i=1;i<=n-cc;i++)g[n]=g[n]*i%mod;
        ss=(ss-g[n]+mod)%mod;
        printf("%lld\n",ss);
    }
    return 0;
}