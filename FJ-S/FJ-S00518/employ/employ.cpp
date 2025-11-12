#include <bits/stdc++.h>
using namespace std;
using tp=long long;
#define For(i,l,r) for(tp i(l),i##sc03(r);i<=i##sc03;++i)
#define FoR(i,r,l) for(tp i(r),i##sc03(l);i>=i##sc03;--i)
#define ALL(G) G.begin(),G.end()
#define SIZ(G) tp(G.size())
#define pb emplace_back
#define pf emplace_front
#define ep emplace
#define gp make_pair
#define fr first
#define sd second
// inline tp read(){
//     tp x=0,f=1;char ch=getchar();
//     while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
//     while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();return x*f;
// }inline bool write(tp x,char ch='\n'){return printf("%lld",x),putchar(ch),true;}
template<class T>inline T Max(T a,T b){return a>b?a:b;}
template<class T>inline T Min(T a,T b){return a<b?a:b;}
template<class T,class Q>inline bool Cmax(T&a,Q b){return a<b?a=b,true:false;}
template<class T,class Q>inline bool Cmin(T&a,Q b){return a>b?a=b,true:false;}
constexpr tp N=1000100;
constexpr tp MOD=998244353;
tp n,m;
tp fac[N],c[N];
string s;
inline tp read(){tp x;cin>>x;return x;}
inline bool write(tp x,char ch='\n'){return(cout<<x<<ch),true;}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    n=read();
    m=read();
    cin>>s;s=' '+s;
    For(i,1,n)c[i]=read();
    fac[0]=1;
    For(i,1,10010)fac[i]=fac[i-1]*i%MOD;
    tp ans=0;
    For(P,1,n)if(s[P]=='1'){
        tp cof=1;
        For(i,1,n)if(c[i]>=P){
            cof=cof*fac[n-1]%MOD;
            // cerr<<i<<'\n';
        }ans=(ans+cof)%MOD;
    }write(ans);
    return 0;
}