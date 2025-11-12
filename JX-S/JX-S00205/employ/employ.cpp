#include <bits/stdc++.h>

#define rep(i,l,r) for(auto i(l);i<=r;++i)
#define per(i,l,r) for(auto i(r);i>=l;--i)

typedef long long LL;
typedef std::pair<int,int> PII;

const int N = 510;
const int M = 2000010;
const auto INF = 0x3f3f3f3f3f3f3f3f;
const auto mod = 998244353;

inline LL read(){
    LL x=0;char ch=getchar();bool f=0;
    while(ch<'0' || ch>'9'){f=(ch=='-');ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f?-x:x;
}

int n,m;
char s[N];
int c[N];
LL dp[1<<20][20];

auto MOD = [](LL &x){if(x>=mod){x-=mod;}};

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    n=read(),m=read();
    scanf("%s",s+1);
    rep(i,1,n){c[i]=read();}

    dp[0][0]=1;
    rep(i,0,(1<<n)-1){
        int num=0;
        rep(j,1,n){if(i&(1<<j-1)){++num;}}
        rep(j,1,n){
            if(i&(1<<j-1)){continue;}
            int x=(i|(1<<j-1));
            rep(k,0,num){
                if(s[num+1]=='0'){
                    dp[x][k]+=dp[i][k];
                    MOD(dp[x][k]);
                }
                else{
                    if(num-k>=c[j]){
                        dp[x][k]+=dp[i][k];
                        MOD(dp[x][k]);
                    }
                    else{
                        dp[x][k+1]+=dp[i][k];
                        MOD(dp[x][k+1]);
                    }
                }
            }
        }
    }

    LL ans=0;
    rep(i,m,n){
        ans+=dp[(1<<n)-1][i];
        MOD(ans);
    }

    printf("%lld\n",ans);

    return 0;
}
/*
-O2 -Wall -static -o
-fsantize=address,undefined -Wall -O2 -o
*/
