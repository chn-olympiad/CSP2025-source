#include <bits/stdc++.h>
using namespace std;
int a[500005];
struct x_ {
    int o;
    int p;
};
int x(int l, int r) {
    int res = a[l];
    for (int i = l + 1; i <= r; ++ i) {
        res ^= a[i];
    }
    return res;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    vector<pair<int, int>> xo;
    for (int i = 1; i <= n; ++ i) {
        for (int j = i; j <= n; ++ j) {
            if (x(i, j) == k) {
                xo.push_back({i, j});
            }
        }
    }
    int l = 0, maxn = 0;
    bool flag[xo.size()];
    while (l < xo.size() - 1) {
            flag[0] = 1;
        int tmp = l + 1;
        int cnt = 1;
        while (tmp < xo.size()) {
            if (flag[tmp - 1]) {
                if (xo[tmp].first > xo[tmp - 1].second && xo[tmp].first > xo[l].first) {
                    cnt ++;
                    flag[tmp] = 1;
                }
            }
            else if (flag[tmp - 1] == 0) {
                int tmp1 = tmp;
                while (!flag[tmp1]) {
                    -- tmp1;
                }
                if (xo[tmp].first > xo[tmp1].second && xo[tmp].first > xo[l].second) {
                    cnt ++;
                    flag[tmp] = 1;
                }
            }
            ++ tmp;
        }
        maxn = max(maxn, cnt);
        ++ l;
        for (int i = 0; i < xo.size(); ++ i) {
            flag[i] = 0;
        }
    }
    cout << maxn;
    return 0;
}
