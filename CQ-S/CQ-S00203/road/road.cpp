#include <bits/stdc++.h>

// #define int long long
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define rep(i,l,r) for (int i = (int)(l); i <= (int)(r); ++ i )
#define rep1(i,l,r) for (int i = (int)(l); i >= (int)(r); -- i )
#define il inline
#define fst first
#define snd second
#define ptc putchar
#define vi vector<int>
#define pb emplace_back
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define me(a,x) memset(a,x,sizeof a)
#define debug() puts("------------")

using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<ll,ll> PLL;
namespace szhqwq {
    template<class T> il void read(T &x) {
        x = 0; T f = 1; char ch = getchar();
        while (ch < '0' || ch > '9') { if (x == '-') f = -1; ch = getchar(); }
        while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
        x *= f;
    }
    template<class T,class... Args> il void read(T &x,Args &...x_) { read(x); read(x_...); }
    template<class T> il void print(T x) {
        if (x < 0) ptc('-'), x = -x;
        if (x > 9) print(x / 10); ptc(x % 10 + '0');
    }
    template<class T,class T_> il void write(T x,T_ ch) { print(x); ptc(ch); }
    template<class T,class T_> il void chmax(T &x,T_ y) { x = x < (T)y ? (T)y : x; }
    template<class T,class T_> il void chmin(T &x,T_ y) { x = x > (T)y ? (T)y : x; }
    template<class T,class T_,class T__> il T qmi(T a,T_ b,T__ p) {
        T res = 1; while (b) {
            if (b & 1) res = res * a % p;
            a = a * a % p; b >>= 1;
        } return res;
    }
    template<class T,class T_> il T getinv(T x,T_ p) { return qmi(x,p - 2,p); }
} using namespace szhqwq;
const int N = 2e5 + 10,inf = 1e9,mod = 998244353;
const ull base = 131,base_ = 233;
const ll inff = 1e18;
const db eps = 1e-6;
int n,m,k,tot,c[20],fa[N],d[20]; ll val[20];
struct node { int u,v; ll w,fl; } g[3000010];

il int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

il void solve() {
    //------------code------------
    read(n,m,k);
    rep(i,1,m) {
        int u,v,w; read(u,v,w);
        g[++ tot] = {u,v,w,-1};
    }
    rep(i,1,k) {
        read(c[i]);
        rep(j,1,n) {
            int x; read(x);
            g[++ tot] = {n + i,j,x,c[i]};
        }
    }
    rep(i,1,n + k) fa[i] = i;
    sort(g + 1,g + tot + 1,[&](node x,node y) {
        return x.w + (x.fl == -1 ? 0 : x.fl) < y.w + (y.fl == -1 ? 0 : y.fl);
    });
    ll ret = 0; int cnt = 0;
    rep(i,1,k) ret += c[i];
    rep(i,1,tot) {
        int u = g[i].u,v = g[i].v,w = g[i].w;
        int x = find(u),y = find(v);
        if (x == y) continue;
        // cerr << u << " " << v << " " << w << '\n';
        fa[y] = x; ret += w;
        if (u > n) ++ d[u - n],val[u - n] += w;
        if (v > n) ++ d[v - n],val[v - n] += w;
        ++ cnt;
        if (cnt == n + k - 1) break;
    }
    rep(i,1,k) if (d[i] <= 1) ret = ret - c[i] - val[i];

    // ll ans = 0; cnt = 0;
    // rep(i,1,k) d[i] = val[i] = 0;
    // sort(g + 1,g + tot + 1,[&](node x,node y) {
    //     return x.w + (x.fl == -1 ? 0 : x.fl - m) < y.w + (y.fl == -1 ? 0 : y.fl - m);
    // });
    // rep(i,1,k) ans += c[i];
    // rep(i,1,n + k) fa[i] = i;
    // rep(i,1,tot) {
    //     int u = g[i].u,v = g[i].v,w = g[i].w;
    //     int x = find(u),y = find(v);
    //     if (x == y) continue;
    //     // cerr << u << " " << v << " " << w << '\n';
    //     fa[y] = x; ans += w;
    //     if (u > n) ++ d[u - n],val[u - n] += w;
    //     if (v > n) ++ d[v - n],val[v - n] += w;
    //     ++ cnt;
    //     if (cnt == n + k - 1) break;
    // }
    // rep(i,1,k) if (d[i] <= 1) ans = ans - c[i] - val[i];
    // cerr << ans << '\n';
    // write(min(ret,ans),'\n');
    write(ret,'\n');
    return ;
}

signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int _ = 1;
    // read(_);
    while (_ -- ) solve();
    return 0;
}