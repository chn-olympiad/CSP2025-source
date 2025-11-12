#include<bits/stdc++.h>

#define int long long

const int N=505;
const int mod=998244353;

int m,n;
int c[N];
char s[N];
int sum=0;

namespace small{
    int f[262144][19];
    int sz[262144];

    void main(){
        for(int j=0;j<(1<<n);j++) sz[j]=__builtin_popcount(j);
        f[0][0]=1;
        for(int i=0;i<(1<<n);i++){
            for(int x=0;x<=sz[i];x++){
                f[i][x]%=mod;
                for(int j=0;j<n;j++){
                    if((i>>j)&1) continue;
                    if(c[j]<=x||s[sz[i]+1]=='0') f[i|(1<<j)][x+1]+=f[i][x];
                    else f[i|(1<<j)][x]+=f[i][x];
                }
            }
        }
        int res=0;
        for(int i=0;i<=n;i++){
            if(n-i>=m) res+=f[(1<<n)-1][i];
        }
        std::cout<<res%mod<<'\n';
    }
}
namespace mn{
    void main(){
        for(int i=1;i<=n;i++) if(s[i]=='0') return (void)(std::cout<<0<<'\n');
        for(int i=0;i<n;i++) if(c[i]==0) return (void)(std::cout<<0<<'\n');
        int res=1; for(int i=1;i<=n;i++) res*=i,res%=mod;
        std::cout<<res<<'\n';

        return;
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    std::cin>>n>>m;
    std::cin>>(s+1);
    for(int i=1;i<=n;i++) sum+=(s[i]-'0');
    for(int i=0;i<n;i++) std::cin>>c[i];

    if(n<=18) small::main();
    else if(n==m) mn::main();

    return 0;
}
