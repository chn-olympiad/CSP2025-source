#include<bits/stdc++.h>
#define ll long long
#define rep(a,b,c,d) for(ll (a)=(b);(a)<=(c);(a)+=(d))
#define per(a,b,c,d) for(ll (a)=(b);(a)>=(c);(a)-=(d))
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define endl '\n'
#define _1 first
#define _2 second
#define puts(str) ((cout<<(str)<<endl),0)
#define lowbit(x) ((x)&(-(x)))
using namespace std;

const ll MAXN = 1000010;
const ll MAXV = MAXN;
const ll MOD = 998244353;
#define LOG_INV

namespace Math {
    ll factorial[MAXV];
    #ifndef LOG_INV
    ll _inv[MAXV];
    #endif

    ll qpow(ll base, ll x) {
        ll res=1;
        while(x) {
            if(x&1ll) (res*=base)%=MOD;
            (base*=base)%=MOD;
            x>>=1ll;
        }
        return res;
    }

    void init(ll MAXV = MAXV) {
        factorial[0]=1;
        rep(i,1,MAXV,1) factorial[i]=factorial[i-1]*i%MOD;
        #ifndef LOG_INV
        _inv[1]=1;
        rep(i,2,MAXV,1) _inv[i]=(MOD-MOD/i)*_inv[MOD%i]%MOD;
        #endif
    }

    ll inv(ll x) {
        #ifndef LOG_INV
        return _inv[x];
        #else
        return qpow(x, MOD-2);
        #endif
    }

    ll A(ll n, ll m) {
        return factorial[n]*inv(factorial[n-m])%MOD;
    }

    ll C(ll n, ll m) {
        return factorial[n]*inv(factorial[n-m])%MOD*inv(factorial[m])%MOD;
    }
}

using namespace Math;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    return 0;
}