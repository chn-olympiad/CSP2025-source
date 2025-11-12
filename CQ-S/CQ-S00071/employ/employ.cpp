#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct{char buf[1<<20],*l=buf,*r=l;
operator char(){return l==r&&(r=(l=buf)+fread(buf,1,1<<20,stdin),l==r)?-1:*l++;}
template<typename T>operator T(){
    T x=0;char f=0,c;
    do if((c=*this)=='-')f=1;while(c<'0'||c>'9');
    while(c>='0'&&c<='9')x=x*10+(c^48),c=*this;
    return f?-x:x;
}}in;void out(char c){putchar(c);}
template<typename T>void out(T x){
    static signed stk[39],tp;
    if(x<0)out('-'),x=-x;
    do stk[tp++]=x%10;while(x/=10);
    while(tp)putchar(stk[--tp]^48);
}template<typename T,typename...Args>
void out(T x,Args...args){out(x),out(args...);}

const int N = 505,mod = 998244353;
int f[N][N][N];
bool t[N];
int c[N];
int n,m;

int fac[N];

namespace sub1{
    int f[1<<18][19];
    int main(){
        f[0][0] = 1;
        for(int k=1;k<(1<<n);k++)
            for(int j=0;j<n;j++)
                if((k>>j)&1){
                    int p = __builtin_popcount(k)-1;
                    for(int i=0;i<=p;i++){
                        if(t[p+1]&&(c[j+1]>p-i))
                            f[k][i+1] = (f[k][i+1]+f[k^(1<<j)][i])%mod;
                        else
                            f[k][i] = (f[k][i]+f[k^(1<<j)][i])%mod;
                    }
                }
        long long ans = 0;
        for(int k=m;k<=n;k++)
            ans += f[(1<<n)-1][k];
        out(ans%mod);
        return 0;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fac[0] = 1;
    for(int k=1;k<N;k++)
        fac[k] = 1ull*fac[k-1]*k%mod;

    n = in,m = in;
    for(int k=1;k<=n;k++){
        char c;do c=in;while(c!='0'&&c!='1');
        t[k] = c=='1';
    }
    for(int k=1;k<=n;k++)
        c[k] = in;
    sort(c+1,c+1+n);
    if(n<=18)
        return sub1::main();
    int cnt = 0;
    for(int k=1;k<=n;k++)
        cnt += c[k]>0;
    if(cnt<m){
        puts("0");
    }
    int ans = 1;
    for(int k=2;k<=n;k++)
        ans = 1ull*ans*k%mod;
    out(ans);
}