#include <bits/stdc++.h>

typedef long long ll;

const ll maxn=505;
const ll maxm=1e6+5;
const ll maxk=15;

using std::cin;
using std::cout;

ll a[maxn], w[maxm];
ll n,m, cnt, ans=0;

ll f(ll x) {
    ll res=1;
    for(ll i=x;i>=1;i--) {
        res*=i;
        res%=998244353;
    }
    return res;
}

ll fpow(ll a, ll b, ll mod) {
    ll base=a, res=1;
    while(b) {
        if(b&1) {
            res*=base;
            res%=mod;
        }
        base*=base;
        base%=mod;
        b>>=1;
    }
    return res;
}

bool check(std::vector<ll> v) {
    ll cnt=0, wait=0, tot=0;
    for(ll i=0;i<n;++i) {
        if(w[v[i]] > wait) {
           if(a[tot+1]) {
                --wait;
                ++cnt;

            }
            ++tot;
            ++wait;
        }
    }
    return cnt>=m;
}

bool tag[100];

void dfs(ll cnt, std::vector<ll> v) {
    if(cnt==n) {
        ans += check(v);
        return;
    }
    for(ll i=1;i<=n;i++) {
        if(!tag[i]) {
            v.push_back(i);
            tag[i]=1;
            dfs(cnt+1,v);
            v.pop_back();
            tag[i]=0;
        }
    }
    return;
}

int main() {
//freopen("input", "r", stdin);
freopen("employ.in", "r", stdin);
freopen("employ.out", "w", stdout);
    cin>>n>>m;

    bool flag=false;
    for(ll i=1;i<=n;i++) {
        char ch;
        cin>>ch;
        a[i]=ch-'0';
        cnt+=a[i];
        flag |= !(a[i]==1);
    }

    for(ll i=1;i<=n;++i) {
        cin>>w[i];
    }

    if(cnt < m) {
        puts("0");
        return 0;
    }

    if(m==n) {
        ll res=1;
        for(ll i=1;i<=n;++i) {
            res*=i;
            res%=998244353;
        }
        printf("%lld\n", res);
        return 0;
    }

    if(m==1) {
        ll num=0;
        for(ll i=1;i<=n;++i) {
            if(w[i]>0) {
                ++num;
            }
        }
        printf("%lld\n", num*f(n-1));
        return 0;
    }

    dfs(0, {});
    printf("%lld\n", ans);
	return 0;
}
