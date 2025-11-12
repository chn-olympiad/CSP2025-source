#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=500+10;
const int maxm=3e5+10;
const int mod=998244353;
int n,m;
int s[maxn],c[maxn],pre[maxn],f[20][maxm];
vector<int>pos[20];
inline void ipt(){
    pre[0]=1;
    for(int i=1;i<=500;i++)pre[i]=pre[i-1]*i%mod;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%1lld",&s[i]);
    }
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
}
inline void solve1(){
    for(int i=1;i<=n;i++){
        if(!s[i]||!c[i]){
            printf("0\n");
            return ;
        }
    }
    printf("%lld\n",pre[n]);
}
inline void solve2(){
    int ct=0;
    for(int i=1;i<=n;i++){
        if(c[i])++ct;
    }
    if(!ct){
        printf("0\n");
        return ;
    }
    int p=pre[n-1]*ct%mod;
    printf("%lld\n",p);
}

inline void solve3(){
    f[0][0]=1;
    for(int i=0;i<(1ll<<n);i++){
        int ct=0;
        for(int j=1;j<=n;j++){
            if(i&(1ll<<(j-1)))++ct;
        }
        pos[ct].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int r=0;r<pos[i].size();r++){
            int k=pos[i][r];
            for(int j=i-1;j>=0;j--){
                f[j][k]=0;
                int ct=0;
                for(int l=1;l<=n;l++){
                    if(k&(1ll<<(l-1)))++ct;
                }
                if(ct!=i)continue;
                for(int l=1;l<=n;l++){
                    if(k&(1ll<<(l-1))){
                        if(!s[i]||j>=c[l]){
                            f[j+1][k]+=f[j][k^(1ll<<(l-1))];
                            if(f[j+1][k]>=mod)f[j+1][k]-=mod;
                        }
                        else {
                            f[j][k]+=f[j][k^(1ll<<(l-1))];
                            if(f[j][k]>=mod)f[j][k]-=mod;
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n-m;i++){
        ans+=f[i][(1ll<<n)-1];
        if(ans>=mod)ans-=mod;
    }
    printf("%lld\n",ans);
}
inline void solve(){
    if(m==n){
        solve1();
        return ;
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(!s[i]){
            flag=false;
            break;
        }
    }
    if(flag){
        solve2();
        return ;
    }
    if(n<=18){
        solve3();
        return ;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ipt();
    solve();
    return 0;
}