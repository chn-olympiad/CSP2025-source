#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

inline void read(int &x){
    x=0;bool f=false;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=true;c=getchar();}
    while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    x=f?-x:x;return ;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>10) write(x/10);
    putchar('0'+x%10);
    return ;
}

const int N = 5e5 + 10, mod = 998244353;
const int inf = 2e18;

int n, m;
int a[N], sum[N];
int fac[N], inv[N], finv[N];

struct SGT{
    struct T{int tag, sum, w;}tr[N << 2];
    #define ls (x << 1)
    #define rs (x << 1 | 1)
    #define mid (l + r >> 1)
    void pushup(int x){}
    void pushdowm(int x){}
    void build(int x, int l, int r){
        if(l == r){tr[x].w = a[l];return ;}
        build(ls, l, mid);build(rs, mid + 1, r);
        pushup(x);
    }
    void change(int x, int l, int r, int L, int R, int w){
        if(R < l || r < L) return ;
        if(L <= l && r <= R){return ;}
        pushdowm(x);
        change(ls, l, mid, L, R, w);change(rs, mid + 1, r, L, R, w);
        pushup(x);
    }
    int query(int x, int l, int r, int L, int R){
        if(R < l || r < L) return inf;
        if(L <= l && r <= R) return tr[x].w;
        return (query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
    }
    #undef ls
    #undef rs
    #undef mid
}

int qpow(int a, int b){
    int res = 1;
    while(b){if(b & 1) res = res * a % mod;b >>= 1;a = a * a % mod;}
    return res;
}

void init(){
    fac[0] = inv[0] = finv[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod, inv[i] = qpow(inv[i], mod - 2);
    finv[N - 1] = qpow(fac[N - 1], mod - 2);
    for(int i = N - 2; i >= 1; i--) finv[i] = finv[i + 1] * (i + 1) % mod;
}

int C(int n, int m){
    if(n < 0 || m < 0 || n < m) return 0;
    return fac[n] * finv[m] % mod * finv[n - m] % mod;
}

signed main(){
    return 0;
}