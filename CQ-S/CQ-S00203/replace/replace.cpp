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
const int N = 2e5 + 10,inf = 1e9,mod = 998244353,mod_ = 1e9 + 7;
const ull base = 131,base_ = 233;
const ll inff = 1e18;
const db eps = 1e-6;
int n,q; string s[N],ss[N];
map<pair<pair<ull,ull>,pair<ull,ull>>,ll> vis;
vi nxt[N],nxtt[N]; int len[N],aaa[5000010];

il void solve() {
    //------------code------------
    read(n,q);
    if (n <= 1000 && q <= 1000) {
        rep(i,1,n) cin >> s[i] >> ss[i];
        while (q -- ) {
            string a,b; cin >> a >> b;
            int len = sz(a);
            string t = a;
            ll ret = 0;
            rep(id,1,n) {
                rep(i,0,len - 1) {
                    if (a[i] == s[id][0]) {
                        int pos = 0;
                        while (pos < sz(s[id]) && a[i + pos] == s[id][pos]) ++ pos;
                        if (pos == sz(s[id])) {
                            rep(j,i,i + sz(s[id]) - 1) t[j] = ss[id][j - i];
                            if (t == b) ++ ret;
                            t = a;
                        }
                    }
                }
            }
            write(ret,'\n');
        }
        return ;
    }
    if (q == 1) {
        rep(p,1,n) {
            cin >> s[p] >> ss[p]; len[p] = sz(s[p]);
            nxt[p].resize(sz(s[p]) + 1);
            nxtt[p].resize(sz(s[p]) + 1);
            s[p] = " " + s[p]; ss[p] = " " + ss[p];
            for (int i = 2,j = 0; i <= sz(s[p]); ++ i ) {
                while (j && s[p][i] != s[p][j + 1]) j = nxt[p][j];
                if (s[p][i] == s[p][j + 1]) ++ j;
                nxt[p][i] = j;
            }
            for (int i = 2,j = 0; i <= sz(ss[p]); ++ i ) {
                while (j && ss[p][i] != ss[p][j + 1]) j = nxtt[p][j];
                if (ss[p][i] == ss[p][j + 1]) ++ j;
                nxtt[p][i] = j;
            }
        }
        while (q -- ) {
            string a,b; cin >> a >> b;
            int lenn = sz(a);
            a = " " + a; b = " " + b;
            ll ret = 0;
            rep(id,1,n) {
                for (int i = 1,j = 0; i <= lenn; ++ i ) {
                    while (j && a[i] != s[id][j + 1]) j = nxt[id][j];
                    if (a[i] == s[id][j + 1]) ++ j;
                    if (j == len[id]) aaa[j] = 1,j = nxt[id][j];
                }
                for (int i = 1,j = 0; i <= lenn; ++ i ) {
                    while (j && b[i] != ss[id][j + 1]) j = nxtt[id][j];
                    if (b[i] == ss[id][j + 1]) ++ j;
                    if (j == len[id]) {
                        if (aaa[j]) ++ ret;
                        j = nxtt[id][j];
                    }
                }
            }
            write(ret,'\n');
        }
        return ;
    }
    rep(__,1,n) {
        string a,b; cin >> a >> b;
        int le = 0,ri = sz(a) - 1;
        rep(i,0,sz(a) - 1)
            if (a[i] == b[i]) ++ le;
            else break;
        rep1(i,sz(a) - 1,0)
            if (a[i] == b[i]) -- ri;
            else break;
        string aa = a.substr(le,ri - le + 1),bb = b.substr(le,ri - le + 1);
        // cerr << aa << " " << bb << '\n';
        ull val = 0,vall = 0,val_ = 0,vall_ = 0;
        rep(i,0,sz(aa) - 1) {
            val = (val * base % mod + (ull)(aa[i] - 'a')) % mod;
            val_ = (val_ * base_ % mod + (ull)(aa[i] - 'a')) % mod_;
            vall = (vall * base % mod + (ull)(bb[i] - 'a')) % mod;
            vall_ = (vall_ * base_ % mod + (ull)(bb[i] - 'a')) % mod_;
        }
        ++ vis[make_pair(make_pair(val,vall),make_pair(val_,vall_))];
    }
    while (q -- ) {
        string a,b; cin >> a >> b;
        int le = 0,ri = sz(a) - 1;
        rep(i,0,sz(a) - 1)
            if (a[i] == b[i]) ++ le;
            else break;
        rep1(i,sz(a) - 1,0)
            if (a[i] == b[i]) -- ri;
            else break;
        string aa = a.substr(le,ri - le + 1),bb = b.substr(le,ri - le + 1);
        ull val = 0,vall = 0,val_ = 0,vall_ = 0;
        rep(i,0,sz(aa) - 1) {
            val = (val * base % mod + (ull)(aa[i] - 'a')) % mod;
            val_ = (val_ * base_ % mod + (ull)(aa[i] - 'a')) % mod_;
            vall = (vall * base % mod + (ull)(bb[i] - 'a')) % mod;
            vall_ = (vall_ * base_ % mod + (ull)(bb[i] - 'a')) % mod_;
        }
        // cout << val << " " << vall << " " << val_ << " " << vall_ << '\n';
        write(vis[make_pair(make_pair(val,vall),make_pair(val_,vall_))],'\n');
        // write(vis[make_pair(val,vall)],'\n');
        // cerr << st[make_pair(aa,bb)] << '\n';
    }
    return ;
}

signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int _ = 1;
    // read(_);
    while (_ -- ) solve();
    return 0;
}