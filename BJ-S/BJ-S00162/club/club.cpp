#include<bits/stdc++.h>
#define ll long long
#define rep(a,b,c,d) for(ll (a)=(b);(a)<=(c);(a)+=(d))
#define per(a,b,c,d) for(ll (a)=(b);(a)>=(c);(a)-=(d))
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define endl '\n'
#define puts(str) ((cout<<(str)<<endl),0)
#define lowbit(x) ((x)&(-(x)))
using namespace std;

const ll MAXN = 100010;
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
}

using namespace Math;

struct node {
    ll a,b,c;
};

ll n;
vector<node> a,b,c;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    // init();
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        ll ans=0;
        a.clear();b.clear();c.clear();
        rep(i,1,n,1) {
            ll x,y,z;
            cin>>x>>y>>z;
            node t={x,y,z};
            if(x>=y&&x>=z) {a.pb(t);ans+=x;}
            else if(y>=x&&y>=z) {b.pb(t);ans+=y;}
            else {c.pb(t);ans+=z;}
        }
        vector<ll> delta;
        ll need;
        if(a.size()>n/2) {
            for(auto v : a) {
                delta.pb(max(v.b-v.a, v.c-v.a));
            }
            need=a.size()-n/2;
        }
        else if(b.size()>n/2) {
            for(auto v : b) {
                delta.pb(max(v.a-v.b, v.c-v.b));
            }
            need=b.size()-n/2;
        }
        else if(c.size()>n/2) {
            for(auto v : c) {
                delta.pb(max(v.b-v.c, v.a-v.c));
            }
            need=c.size()-n/2;
        }
        else {
            cout<<ans<<endl;
            continue;
        }
        sort(delta.begin(), delta.end(), greater<ll>());
        
        rep(i,0,need-1,1) {
            ans+=delta[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}