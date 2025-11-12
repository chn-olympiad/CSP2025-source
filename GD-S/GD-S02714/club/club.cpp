#include <bits/stdc++.h>
using namespace std;

namespace IMC {
    constexpr int N = 1e5 + 3;
    int n;
    int a[N][4];
    int siz[4], cost[4][N];
    void main() {
        cin >> n;
        int ans = 0;
        siz[1] = siz[2] = siz[3] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j)
                cin >> a[i][j];
            int maxn = max({a[i][1],a[i][2],a[i][3]});
            ans += maxn;
            if (maxn == a[i][1]) {
                ++siz[1];
                cost[1][siz[1]] = maxn - max(a[i][2], a[i][3]);
            } else if (maxn == a[i][2]) {
                ++siz[2];
                cost[2][siz[2]] = maxn - max(a[i][1], a[i][3]);
            } else {
                ++siz[3];
                cost[3][siz[3]] = maxn - max(a[i][2], a[i][1]);
            }
        }
        for (int i = 1; i <= 3; ++i)
            if (siz[i] > n/2) {
                sort(cost[i]+1,cost[i]+1+siz[i]);
                for (int j = 1; j <= siz[i] - n/2; ++j)
                    ans -= cost[i][j];
            }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; cin >> t;
    while (t--)
        IMC::main();
    return 0;
}