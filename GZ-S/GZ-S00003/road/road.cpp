// GZ-S00003 丁思源   贵阳市华师一学校

#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define ll int

#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define vi vector<ll>
#define pb push_back
#define SZ(x)  ((int)x.size())
#define BG(x) (x.begin())
#define ED(x) (x.end())
#define pii pair<ll,ll>
#define x first
#define y seconde
#define mkp make_pair
#define gmin(x,y) (x=min(x,y))
#define gmax(x,y) (x=max(x,y))
#define MD(x) ((x)%=mod)
#define ppct __builtin_popcountll

 
namespace Mine {
    #define gc getchar
    ll read() {
        ll x=0,t=1;
        char ch=gc();
        while(ch<'0' || ch>'9') t=(ch=='-'?-1:t),ch=gc();
        while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=gc();
        return t*x;
    }
    #undef gc
    const ll N=1e4+100,M=1e6+1e5+100;
    ll n,m,K;
    struct E {
        ll a,b,d;
    } e1[M],e2[11][N],e[M];
    ll fa[N],C[N];
    ll find(ll x) {return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
    void init() {
        For(i,1,n+100) fa[i]=i;
    }
    bool merge(ll x,ll y) {
        x=find(x),y=find(y);
        if(x==y) return 0;
        fa[x]=y;
        return 1;
    }
    ll ans;
    bool cmp(E x,E y){
        return x.d<y.d;
    }
    ll tot=0;
    void main() {
        n=read(),m=read(),K=read();
        For(i,1,m) {
            e1[i].a=read(),e1[i].b=read(),e1[i].d=read();
        }
        sort(e1+1,e1+1+m,cmp);
        For(i,1,K) {
            C[i]=read();
            For(j,1,n) {
                e2[i][j].d=read();
                e2[i][j].a=j;
                e2[i][j].b=n+i;
            }
            sort(e2[i]+1,e2[i]+1+n,cmp);
        }
        init();
        For(i,1,m) {
            ll x=e1[i].a,y=e1[i].b;
            if(merge(x,y)) ans+=e1[i].d,e1[++tot]=e1[i];
        }
        m=tot;
        For(st,1,(1<<K)-1) {
            ll tt=tot;
            ll res=0;
            For(i,1,tot) e[i]=e1[i];
            For(j,0,K-1) if(st>>j & 1) {
                res+=C[j+1];
                For(i,1,n) {
                    e[++tt]=e2[j+1][i];
                }
            }
            sort(e+1,e+1+tt,cmp);
            init();
            For(i,1,tt) {
                ll x=e[i].a,y=e[i].b;
                if(merge(x,y)) res+=e[i].d;
            }
            gmin(ans,res);
        }
        cout<<ans;
    }
}

signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll _=1;
    while(_--) Mine::main();

    return 0;
}