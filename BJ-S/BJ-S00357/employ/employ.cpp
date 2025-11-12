#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
template<typename T>
inline void read(T &x){
    bool f=0;
    x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    x=f?-x:x;
}
template<typename T>
void write(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=505,mod=998244353;
int n,m;
bool a[N];
int c[N],fac[N],ifac[N],p[N];
inline int qpow(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        ans=ans*a%mod;
    }
    return ans;
}
inline void init(){
    rep(i,1,N-5) fac[i]=fac[i-1]*i%mod;
    ifac[N-5]=qpow(fac[N-5],mod-2);
    per(i,N-6,0) ifac[i]=ifac[i+1]*(i+1)%mod;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    init();
    read(n),read(m);
    rep(i,1,n){
        char c=getchar();
        if(c=='1') a[i]=1;
        else a[i]=0;
    }
    getchar();
    rep(i,1,n) read(c[i]),p[i]=i;
    int ans=0;
    do{
        int cnt=0;
        rep(i,1,n){
            if(cnt>=c[p[i]]) cnt++;
            else if(!a[i]) cnt++;
        }
        if(n-cnt>=m){
            ans++;
            // rep(i,1,n) cerr<<p[i]<<' ';cerr<<'\n';
        }
    }while(next_permutation(p+1,p+n+1));
    write(ans);
    return 0;
}
/*
g++ T1.cpp -o T1 -std=c++14 -O2 
ctrl+` to open
*/