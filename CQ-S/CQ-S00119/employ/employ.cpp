#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
typedef unsigned int uint;
typedef unsigned long long ull;
constexpr uint mod{998244353};
constexpr uint plus(const uint &x,const uint &y) {
    if(x+y>=mod) {
        return x+y-mod;
    }
    return x+y;
}
constexpr uint minus(const uint &x,const uint &y) {
    if(x<y) {
        return x-y+mod;
    }
    return x-y;
}
constexpr uint &add(uint &x,const uint &y) {
    return x=plus(x,y);
}
constexpr uint &sub(uint &x,const uint &y) {
    return x=minus(x,y);
}
constexpr int N{500};
char str[N+5];
int cnt[N+5],pre[N+5];
uint dp[2][N+5][N+5];
uint tmp[N+5][N+5];
uint fac[N+5];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        ++cnt[x];
    }
    pre[0]=cnt[0];
    for(int i=1;i<=n;i++) {
        pre[i]=pre[i-1]+cnt[i];
    }
    int idx{0};
    std::memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++) {
        // std::cerr<<"i = "<<i<<'\n';
        std::memset(dp[idx^1],0,sizeof(dp[0]));
        std::memset(tmp,0,sizeof(tmp));
        for(int j=0;j<=i-1;j++) {
            for(int k=0;k<=pre[j];k++) {
                tmp[j+1][k+1]=(tmp[j+1][k+1]+ull(pre[j]-k)*dp[idx][j][k])%mod;
            }
        }
        if(str[i]=='0') {
            for(int j=0;j<=i-1;j++) {
                for(int k=0;k<=pre[j];k++) {
                    add(tmp[j+1][k],dp[idx][j][k]);
                }
            }
        }
        else {
            for(int j=0;j<=i-1;j++) {
                for(int k=0;k<=pre[j];k++) {
                    add(dp[idx^1][j][k],dp[idx][j][k]);
                }
            }
        }
        // std::cerr<<" tmp =\n";
        // for(int j=0;j<=i;j++) {
        //     for(int k=0;k<=pre[j];k++) {
        //         std::cerr<<' '<<j<<' '<<k<<": "<<tmp[j][k]<<'\n';
        //     }
        // }
        idx^=1;
        for(int j=1;j<=i;j++) {
            for(int _=1;_<=cnt[j];_++) {
                for(int k=pre[j-1]+_-1;k>=0;k--) {
                    tmp[j][k+1]=(tmp[j][k+1]+ull(i-k)*tmp[j][k])%mod;
                }
            }
        }
        for(int j=0;j<=i;j++) {
            for(int k=0;k<=pre[j];k++) {
                add(dp[idx][j][k],tmp[j][k]);
            }
        }
        // std::cerr<<" dp =\n";
        // for(int j=0;j<=i;j++) {
        //     for(int k=0;k<=pre[j];k++) {
        //         std::cerr<<' '<<j<<' '<<k<<": "<<dp[idx][j][k]<<'\n';
        //     }
        // }
    }
    uint ans{0};
    fac[0]=1;
    for(int i=1;i<=n;i++) {
        fac[i]=ull(fac[i-1])*i%mod;
    }
    for(int i=0;i<=n-m;i++) {
        ans=(ans+ull(fac[n-pre[i]])*dp[idx][i][pre[i]])%mod;
    }
    printf("%u\n",ans);
    return 0;
}