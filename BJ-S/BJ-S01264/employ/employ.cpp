#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=20,Mod=998244353;
ll f[1<<N][N],ans;
int cnt,n,m,c[N];
char s[N];
inline void add(ll &a,ll b){
    a+=b;
    a%=Mod;
}
int main(){
    #ifndef wzh
        freopen("employ.in","r",stdin);
        freopen("employ.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i) if(s[i]=='1') ++cnt;
    for(int i=0;i<n;++i) scanf("%d",&c[i]);
    if(n>=20){
        puts("0");
        return 0;
    }
    f[0][0]=1;
    for(int a=0;a<(1<<n)-1;++a){
        int cnt=__builtin_popcount(a);
        for(int j=0;j<=cnt;++j){
            for(int i=0;i<n;++i){
                if((a>>i)&1) continue;
                if(j>=c[i] || s[cnt+1]=='0') add(f[a|(1<<i)][j+1],f[a][j]);
                else add(f[a|(1<<i)][j],f[a][j]);   
            }
        }
    }
    for(int i=0;i<=n-m;++i) add(ans,f[(1<<n)-1][i]);
    printf("%lld\n",ans);
    return 0;
}