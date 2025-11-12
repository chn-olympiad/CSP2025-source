#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MAXN 200005
#define MAXM 5000005
const int BASE(711);

int n, q; pair<string, string> a[MAXN];

namespace sol1{  // n,q <= 1e3 + q = 1
    ull p[MAXM], hax[MAXM], hay[MAXM], hatx[MAXM], haty[MAXM];
    ull geth(int l, int r, ull *ha){return ha[r]-ha[l-1]*p[r-l+1];} bool vis[MAXM];
    void sol(){
        p[0] = 1; for (int i(1); i<MAXM; ++i) p[i] = p[i-1]*BASE;
        for (string tx, ty; q; --q){
            cin >> tx >> ty;
            if (tx.size() ^ ty.size()){cout << "0\n"; continue;} int m(tx.size()); tx = ' ' + tx; ty = ' ' + ty;
            int l(1), r(m); for (; l<=m; ++l) if (tx[l] ^ ty[l]) break; for (; r; --r) if (tx[r] ^ ty[r]) break;
            hax[0] = 0; for (int i(1); i<=m; ++i) hax[i] = hax[i-1]*BASE+tx[i]; ull px(geth(l, r, hax));
            hay[0] = 0; for (int i(1); i<=m; ++i) hay[i] = hay[i-1]*BASE+ty[i]; ull py(geth(l, r, hay)); int ans(0);
            for (int i(1); i<=n; ++i){
                int k(a[i].first.size()-1); hatx[0] = 0; for (int j(1); j<=k; ++j) hatx[j] = hatx[j-1]*BASE+a[i].first[j];
                for (int j(r-l+1); j<=k; ++j) vis[j] = geth(j-(r-l+1)+1, j, hatx) == px;
                haty[0] = 0; for (int j(1); j<=k; ++j) haty[j] = haty[j-1]*BASE+a[i].second[j];
                for (int j(r-l+1); j<=k; ++j) vis[j] &= geth(j-(r-l+1)+1, j, haty) == py;
                for (int j(r-l+1); j<=k; ++j) if (vis[j] && j-(r-l+1)+1 <= l && k-j <= m-r){
                    int L(j-(r-l+1)+1);
                    ans += geth(1, k, hatx) == geth(l-(L-1), l-(L-1)+k-1, hax) && geth(1, k, haty) == geth(l-(L-1), l-(L-1)+k-1, hay);
                }
            }
            cout << ans << '\n';
        }
    }
}
namespace sol2{  // B
    map<pair<int, int>, int> mp;
    void sol(){
        for (int i(1); i<=n; ++i){
            int x(find(a[i].first.begin(), a[i].first.end(), 'b')-a[i].first.begin()), y(find(a[i].second.begin(), a[i].second.end(), 'b')-a[i].second.begin());
            ++mp[{x, y}];
        }
        // cerr << mp[{2, 1}] << '\n';
        int tid(0);
        for (string tx, ty; q; --q){
            cin >> tx >> ty;
            if (tx.size() ^ ty.size()){cout << "0\n"; continue;} int m(tx.size()); tx = ' ' + tx; ty = ' ' + ty;
            int l(1), r(m); for (; l<=m; ++l) if (tx[l] ^ ty[l]) break; for (; r; --r) if (tx[r] ^ ty[r]) break; int ans(0);
            for (int i(1); i<=l; ++i) ans += mp[tx[l] == 'b' ? pair<int, int>{l-i+1, r-i+1} : pair<int, int>{r-i+1, l-i+1}]; cout << ans << '\n';
        }
    }
}

signed main(){
    freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q; int sz(0);
    for (int i(1); i<=n; ++i) cin >> a[i].first >> a[i].second, sz += 2*a[i].first.size(), a[i].first = ' '+a[i].first, a[i].second = ' '+a[i].second;
    if ((max(n, q) <= 1000 && sz <= 2000) || q == 1) sol1::sol(); else sol2::sol();
    // sol2::sol();

    return 0;
}