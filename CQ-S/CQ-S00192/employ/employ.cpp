#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define mid ((l+r)>>1)
#define ls k<<1
#define rs k<<1|1
#define lowbit(x) (x&(-x))
#define popcount __builtin_popcountll
using namespace std;
int rd(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f*=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch-'0');
    return x*f;
}
const int N=20,INF=0x3f3f3f3f,mod=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
int jc[N+2],inv[N+2];
int ksm(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;b>>=1;
    }return res;
}
int C(int n,int m){
    if(n<0||m<0||n<m) return 0;
    return jc[n]*inv[m]%mod*inv[n-m]%mod;
}
void init(int lim=N){
    jc[0]=1;for(int i=1;i<=lim;i++) jc[i]=jc[i-1]*i%mod;
    inv[lim]=ksm(jc[lim],mod-2);for(int i=lim;i;i--) inv[i-1]=inv[i]*i%mod;
}
int f[(1<<18)][N];
int n,m,op[N],c[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=rd(),m=rd();
    if(n>18) return 0;
    for(int i=1;i<=n;i++){
        char ch=getchar();if(ch!='0'&&ch!='1') ch=getchar();
        op[i]=ch-'0';
    }
    for(int i=1;i<=n;i++) c[i]=rd();
    f[0][0]=1;
    for(int s=0;s<(1<<n);s++){
        int lim=popcount(s);
        for(int i=0;i<=lim;i++){
            for(int j=1;j<=n;j++) if(!((s>>(j-1))&1ll)){
                if(lim-i<c[j]&&op[lim+1])add(f[s|(1<<(j-1))][i+1],f[s][i]);
                else add(f[s|(1<<(j-1))][i],f[s][i]);
            }
        }
    }
    int ans=0,all=(1<<n)-1;
    for(int i=m;i<=n;i++) add(ans,f[all][i]);
    printf("%lld\n",ans);
    return 0;
}
//g++ tmp.cpp -o tmp -std=c++14 -O2 -Wall -fsanitize=address,undefined