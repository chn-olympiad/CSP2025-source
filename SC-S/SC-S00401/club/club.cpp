#include <bits/stdc++.h>
#define int long long
const int MAXN = 1e5 + 20;

int _;

int n;
int val[MAXN][3];
std::vector<int> stf[3];

void init() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) scanf("%lld", &val[i][j]);
    stf[0].clear(), stf[1].clear(), stf[2].clear();
}

void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int bst = std::max(val[i][0], std::max(val[i][1], val[i][2]));
        ans += bst;
        if (bst == val[i][0]) stf[0].push_back(val[i][0] - std::max(val[i][1], val[i][2]));
        else if (bst == val[i][1]) stf[1].push_back(val[i][1] - std::max(val[i][0], val[i][2]));
        else stf[2].push_back(val[i][2] - std::max(val[i][0], val[i][1]));
    }
    
    for (int p = 0; p < 3; p++) {
        if (stf[p].size() <= n / 2) continue;
        std::sort(stf[p].begin(), stf[p].end());
        for (int i = 0; i < stf[p].size() - n / 2; i++) ans -= stf[p][i];
    }
    
    printf("%lld\n", ans);
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &_);
    while (_--) {
        init();
        solve();
    }
    
    return 0;
}