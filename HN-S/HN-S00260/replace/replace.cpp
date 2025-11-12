#include <queue>
#include <iostream>
#include <algorithm>

constexpr int MAX_N = 200000 + 2;

int n, m, q;

std::string s[MAX_N][2], t[2];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        std::cin >> s[i][0] >> s[i][1];
    }

    for (int i = 1; i <= q; i++) {
        std::cin >> t[0] >> t[1];

        int ans = 0, l, r;

        for (int j = 0; j < t[0].size(); j++) {
            if (t[0][j] != t[1][j]) {
                l = j;
                break;
            }
        }

        for (int j = t[0].size() - 1; j >= 0; j--) {
            if (t[0][j] != t[1][j]) {
                r = j;
                break;
            }
        }

        for (int j = 0; j <= l; j++) {
            for (int k = 1; k <= n; k++) {
                if (j + s[k][0].size() > t[0].size()) {
                    continue;
                }

                if (t[0].substr(j, s[k][0].size()) == s[k][0]
                  && t[1].substr(j, s[k][0].size()) == s[k][1]
                  && j + s[k][0].size() > r) {
                    ans++;
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
