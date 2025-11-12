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
    const ll N=505;
    ll n,m,ans;
    char ch[N];
    ll c[N],p[N];
    bool check() {
        ll cnt=0,pp=0;
        For(i,1,n) {
            if(cnt>=c[p[i]] || ch[i]=='0') cnt++;
            else pp++;
        }
        return pp>=m;
    }
    bool book[N];
    void dfs(ll dep) {
        if(dep>n) {
            ans+=check();
        }
        For(i,1,n) if(!book[i]) {
            book[i]=1;
            p[dep]=i;
            dfs(dep+1);
            book[i]=0;
        }
    }
    void main() {
        n=read(),m=read();
        scanf("%s",ch+1);
        For(i,1,n) {
            c[i]=read();
        }
        dfs(1);
        cout<<ans;
    }
}

signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll _=1;
    while(_--) Mine::main();

    return 0;
}