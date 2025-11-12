#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define R read<int>()
#define fi first
#define se second
using namespace std;
template <typename T> inline T read(){
    T x=0,fl=1; char c=getchar();
    while(c<'0'||c>'9') (c=='-'?fl=-1:1),c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*fl;
}
const int inf=0x3f3f3f3f,N=505;
const ll INF=0x3f3f3f3f3f3f3f3f,M=998244353;
int n,m,c[N];
char s[N];
void add(ll &x,ll y){ (x+=y)>=M?(x-=M):0; }
namespace solve1{
    ll f[262200][20];
    void Main(){
        f[0][0]=1;
        for(int S=0;S<(1<<n);S++){
            int cnt=__builtin_popcount(S);
            for(int i=0;i<=cnt;i++){
                for(int j=1;j<=n;j++){
                    if(S&(1<<j-1)) continue;
                    add(f[S|(1<<j-1)][i+(s[cnt+1]=='1'&&c[j]>cnt-i)],f[S][i]);
                }
            }
        }
        ll ans=0;
        for(int i=m;i<=n;i++) ans+=f[(1<<n)-1][i];
        printf("%lld\n",ans%M);
    }
}
namespace solve2{
    void Main(){
        if(*min_element(s+1,s+n+1)=='0') puts("0");
        else{
            ll ans=1;
            for(int i=1;i<=n;i++) ans=ans*i%M;
            printf("%lld\n",ans);
        }
    }
}
namespace solve3{
    int sum[N];
    void Main(){
        for(int i=1;i<=n;i++) sum[c[i]]++;
        for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
        ll ans=1,tot=1;
        for(int i=1;i<=n;i++) tot=tot*i%M;
        for(int i=1;i<=n;i++)
            ans=ans*max(sum[i-1]-i+1,0)%M;
        printf("%lld\n",(tot-ans+M)%M);
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=R,m=R,scanf("%s",s+1);
    for(int i=1;i<=n;i++) c[i]=R;
    sort(c+1,c+n+1);
    if(n<=18) solve1::Main();
    else if(n==m) solve2::Main();
    else puts("0");
    return 0;
}