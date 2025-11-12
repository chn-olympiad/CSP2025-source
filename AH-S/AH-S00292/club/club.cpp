#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

#define fi first
#define se second
#define pb push_back

int n;
ll a[100005],b[100005],c[100005];
vector<ll> op[3];

void wk() {
    cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i] >> b[i] >> c[i];
    ll ans=0;
    for(int i=1;i<=n;++i) ans=ans+max({a[i],b[i],c[i]}); 
    op[0].clear(); op[1].clear(); op[2].clear();
    for(int i=1;i<=n;++i) {
        ll p=max({a[i],b[i],c[i]});
        if(a[i]==p) op[0].pb(a[i]-max(b[i],c[i]));
        else if(b[i]==p) op[1].pb(b[i]-max(a[i],c[i]));
        else op[2].pb(c[i]-max(a[i],b[i]));
    }
    for(int i=0;i<=2;++i) {
        sort(op[i].rbegin(),op[i].rend());
        for(;op[i].size()>n/2;op[i].pop_back()) ans=ans-op[i].back();
    }
    cout << ans << "\n";
}

signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(false);

    int t; cin >> t;
    for(;t--;) wk();

    return 0;
}

// Make asdfz great again!
/*
password:
Ren5Jie4Di4Ling5%
*/