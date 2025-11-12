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
const int N = 1e5 + 10,inf = 1e9,mod = 998244353;
const ull base = 131,base_ = 233;
const ll inff = 1e18;
const db eps = 1e-6;
int n;
struct node { int mx,cmx,id,cid; } a[N];
priority_queue<PII,vector<PII>,greater<PII> > q[4];

il bool cmp(node x,node y) {
    if (x.mx != y.mx) return x.mx > y.mx;
    return x.cmx > y.cmx;
}

il void solve() {
    //------------code------------
    read(n);
    vector<PII> v;
    rep(i,1,n) {
        v.clear();
        rep(j,1,3) {
            int x; read(x);
            v.pb(x,j);
        }
        sort(all(v),greater<PII>());
        a[i] = {v[0].fst,v[1].fst,v[0].snd,v[1].snd};
    }
    ll ret = 0;
    rep(i,1,n) {
        if (sz(q[a[i].id]) < n / 2) {
            q[a[i].id].push({a[i].mx - a[i].cmx,i});
            ret += a[i].mx;
        } else {
            if (q[a[i].id].top().fst < a[i].mx - a[i].cmx) {
                int x = q[a[i].id].top().snd;
                ret += a[x].cmx - a[x].mx;
                q[a[x].cid].push({a[x].cmx - a[x].mx,x});
                q[a[i].id].pop();
                q[a[i].id].push({a[i].mx - a[i].cmx,i});
                ret += a[i].mx;
            } else q[a[i].cid].push({a[i].cmx - a[i].mx,i}),ret += a[i].cmx;
        }
    }
    rep(i,1,3) while (sz(q[i])) q[i].pop();
    write(ret,'\n');
    return ;
}

signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _ = 1;
    read(_);
    while (_ -- ) solve();
    return 0;
}
