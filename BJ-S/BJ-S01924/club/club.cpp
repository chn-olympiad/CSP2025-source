#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr ll MAXN = 1e5 + 5;
struct MYT_BYX {
    ll x, id;
}tmp[5];
ll n;
ll a[MAXN][3];
vector <ll> g[5];
bool cmp(MYT_BYX x, MYT_BYX y) {
    return x.x > y.x;
}
void work() {
    g[0].clear();
    g[1].clear();
    g[2].clear();
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        tmp[0] = {a[i][0], 0};
        tmp[1] = {a[i][1], 1};
        tmp[2] = {a[i][2], 2};
        sort(tmp, tmp + 3, cmp);
        g[tmp[0].id].push_back(tmp[0].x - tmp[1].x);
        ans += tmp[0].x;
    }
    if(g[0].size() >= g[1].size() && g[0].size() >= g[2].size()) {
        ll ndl = g[0].size() - n / 2;
        if(ndl > 0) {
            sort(g[0].begin(), g[0].end());
            for(ll it:g[0]) {
                ans -= it;
                ndl--;
                if(!ndl)
                    break;
            }
        }
    }
    else if(g[1].size() >= g[0].size() && g[1].size() >= g[2].size()) {
        ll ndl = g[1].size() - n / 2;
        if(ndl > 0) {
            sort(g[1].begin(), g[1].end());
            for(ll it:g[1]) {
                ans -= it;
                ndl--;
                if(!ndl)
                    break;
            }
        }
    }
    else {
        ll ndl = g[2].size() - n / 2;
        if(ndl > 0) {
            sort(g[2].begin(), g[2].end());
            for(ll it:g[2]) {
                ans -= it;
                ndl--;
                if(!ndl)
                    break;
            }
        }
    }
    cout << ans << "\n";
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ll t;
    cin >> t;
    while(t--)
        work();
    return 0;
}