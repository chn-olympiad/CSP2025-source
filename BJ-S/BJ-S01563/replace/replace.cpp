#include <bits/stdc++.h>

typedef long long int ll;

const ll base=131;
const ll maxn=2e5+5;

using std::cin;

struct data{
    std::string s, t;
};

data arr[maxn];
ll n,m;

ll get_h(char *s) {
    ll h=0, len=strlen(s+1);
    for(ll i=1;i<=len;++i) {
        h=h*base+s[i]-'a'+1;
    }
    return h;
}

ll fpow(ll n, ll m) {
    ll base=n, res=1;
    while(m) {
        if(m&1) {
            res*=base;
        }
        base*=base;
        m>>=1;
    }
    return base;
}

ll h1[1000005], h2[10000005];

ll get_h(ll *h, ll l, ll r)  {
    return h[r] - h[l-1]*fpow(base, r-l+1);
}

void solve() {
    std::string s, t;
    ll ans=0;
    cin>>s>>t;
    ll lens, lent;
    for(ll i=1;i<=n;++i) {
        ll end=s.size()-arr[i].s.size();
        for(ll j=0;j<=end;++j) {
            std::string temp;
            temp=s.substr(0, j)+arr[i].t+s.substr(j+arr[i].s.size(), s.size()-j-arr[i].t.size());
            if(temp==t) {
                ++ans;
            }
        }
    }
    printf("%lld\n", ans);
    return;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) {
        std::string s, t;
        cin>>arr[i].s>>arr[i].t;
    }

    while(m--) {
        solve();
    }
    return 0;
}
