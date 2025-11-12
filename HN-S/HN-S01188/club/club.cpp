#include <bits/stdc++.h>
using std::cin;

namespace solution {
    using i64 = long long;
    const int N = 1e5 + 5;
    int n, a[N][3], cnt[3], bkt[N][3];
    void solve(){
        cin >> n; i64 ans = 0;
        cnt[0] = cnt[1] = cnt[2] = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            bkt[i][0] = 0, bkt[i][1] = 1, bkt[i][2] = 2;
            std::sort(bkt[i], bkt[i] + 3, [=](int x, int y){
                return a[i][x] > a[i][y];
            });
            cnt[bkt[i][0]]++, ans += a[i][bkt[i][0]];
        }
        for(int o=0;o<=2;o++){
            if(cnt[o] <= (n / 2)) continue;
            std::vector<i64> vct;
            for(int i=1;i<=n;i++){
                if(bkt[i][0] == o) vct.push_back(a[i][bkt[i][0]] - a[i][bkt[i][1]]);
            }
            std::sort(vct.begin(), vct.end());
            for(int i=0;i<(cnt[o]-(n/2));i++) ans -= vct[i];
            break;
        }
        std::cout << ans << '\n';
    }
}

signed main(){
    #ifndef LOCAL
    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T; while(T--) solution::solve();
    return 0;
}

// think twice, code once
// Writting by xiezheyuan
