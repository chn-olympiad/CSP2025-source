#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
template<typename T>
inline void in (T &x) {
    char c; int f=1;
    do {c=getchar(); (c=='-')&&(f=-1);} while(c>'9'||c<'0');
    for (x=0;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    x*=f;
}

const int N=505,mod=998244353;
inline void add(int &x,int y){x+=y; (x>=mod)&&(x-=mod);}
inline int quip(int a,int b){int res=1; for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) res=1ll*res*a%mod; return res;}
int n,m;
char s[N]; int c[N];
int fc[N],ifc[N];
inline int C(int p,int q){return p<q||p<0||q<0?0:1ll*fc[p]*ifc[q]%mod*ifc[p-q]%mod;}

inline void init () {
    in (n),in (m);
    scanf("%s",s+1);
    for (int i=1;i<=n;++i) in (c[i]);
    fc[0]=1; for (int i=1;i<=n;++i) fc[i]=1ll*fc[i-1]*i%mod;
    ifc[n]=quip(fc[n],mod-2); for (int i=n-1;i>=0;--i) ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
}

namespace sub0{
    int f[(1<<18)+5][19],g[(1<<18)+5][19];
    inline void work0() {
        f[0][0]=1;
        for (int i=0;i<n;++i) {
            for (int S=0;S<(1<<n);++S) for (int j=0;j<=n;++j) g[S][j]=0;
            for (int S=0;S<(1<<n);++S)
                for (int j=0;j<=i;++j) if (f[S][j]) {
                    for (int k=0;k<n;++k) if (!((S>>k)&1)) add(g[S|(1<<k)][j+1-(c[k+1]>j && s[i+1]=='1')],f[S][j]);
                }
            for (int S=0;S<(1<<n);++S) for (int j=0;j<=n;++j) f[S][j]=g[S][j];
        }
        int ans=0;
        for (int i=0;i<=n;++i) if (n-i>=m) add(ans,g[(1<<n)-1][i]);
        printf ("%d\n",ans);
    }
}

inline int O(int x){return x<0?0:x;}
namespace sub1 {
    int bu[N],d[N],tt;
    inline void work1 () {
        for (int i=1;i<=n;++i) ++bu[c[i]];
        for (int i=1;i<=n;++i) bu[i]+=bu[i-1];
        for (int i=1;i<=n;++i) if (s[i]=='1') d[++tt]=i-1;
        int ans=1;
        for (int i=1;i<=tt;++i) ans=1ll*ans*O(bu[d[i]]-i+1)%mod;
        for (int i=tt+1;i<=n;++i) ans=1ll*ans*(i-tt)%mod;
        printf ("%d\n",(fc[n]-ans+mod)%mod);
    }
}

namespace sub2 {
    inline void work2() {
        for (int i=1;i<=n;++i) if (c[i]==0 || s[i]=='0') {puts("0"); return ;}
        printf ("%d\n",fc[n]);
    }
}

int main() {
    freopen ("employ.in","r",stdin);
    freopen ("employ.out","w",stdout);
    init();
    if (n<=18) {sub0::work0(); return 0;}
    if (m==1) {sub1::work1(); return 0;}
    if (m==n) {sub2::work2(); return 0;}
    puts("0");
    return 0;
}