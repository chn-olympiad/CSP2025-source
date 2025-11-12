/*
正难则反。

对被拒绝或自愿退出的人容斥即可，写出来即为二项式反演。

错了。

注意到删去一个死人可能会复活他后面一个死人。

没绷住，计算容斥系数时会回跳，完全做不了了。
*/
#include<bits/stdc++.h>
using namespace std;
namespace AfterTheRainStops{//雨停酱可爱捏，最喜欢雨停姐姐啦～
constexpr int mod=998244353;
int inv[501],fac[501],ifac[501];
char s[502];
int c[501];
long long f[1<<18][19];
int cnt[501];
void main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    scanf(" %s",s+1);
    for(int i=0;i<n;++i)scanf("%d",c+i),++cnt[c[i]];
    for(int i=1;i<=n;++i)cnt[i]+=cnt[i-1];
    if(n<=18){
        f[0][0]=1;
        for(int i=1;i<(1<<n);++i){
            int j=__builtin_popcount(i);
            if(s[j]=='0'){
                for(int p=0;p<n;++p)
                    if(i&(1<<p))
                        for(int k=0;k<j;++k)
                            f[i][k]+=f[i^(1<<p)][k];
            }else{
                for(int p=0;p<n;++p)
                    if(i&(1<<p))
                        for(int k=0;k<j;++k)
                            f[i][k+(j-1-k<c[p])]+=f[i^(1<<p)][k];
            }
            for(int k=0;k<=j;++k)f[i][k]%=mod;
        }
        long long res=0;
        for(int k=m;k<=n;++k)res+=f[(1<<n)-1][k];
        printf("%lld",res%mod);
    }else if(m==1){
        long long res=1;
        int cnt0=0;
        for(int i=1;i<=n;++i)
            if(s[i]=='0'){
                ++cnt0;
                continue;
            }else res=res*(cnt[i-1]-(i-cnt0)+1)%mod;
        for(int i=1;i<=cnt0;++i)res=res*i%mod;
        long long tot=1;
        for(int i=1;i<=n;++i)tot=tot*i%mod;
        res=tot-res;
        if(res<0)res+=mod;
        printf("%lld",res);
    }else if(m==n){
        for(int i=1;i<=n;++i)if(s[i]=='0'){puts("0");return;}
        if(cnt[0]){puts("0");return;}
        long long res=1;
        for(int i=1;i<=n;++i)res=res*i%mod;
        printf("%lld",res);
    }
}
}
int main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
    AfterTheRainStops::main();
    return 0;
}