#include <iostream>
#include <cstdio>
#include <algorithm>

#define OUTPUT_LEVEL \
    for (int __level = 0; __level < level; __level++) { \
        std::cout << "    "; \
    }

constexpr int MAXN = 1e5 + 10;

int t, n;
int satisfy[MAXN][3];

int dfs(int now, int cnt0, int cnt1, int cnt2);

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> t;
    for (int test = 0; test < t; test++) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> satisfy[i][0] >> satisfy[i][1] >> satisfy[i][2];
        }
        int ans = dfs(1, 0, 0, 0);
        std::cout << ans << '\n';
    }

    return 0;
}

int dfs(int now, int cnt0, int cnt1, int cnt2) {
    // static int level = 0;
    // level++;
    if (cnt0 > n / 2 || cnt1 > n / 2 || cnt2 > n / 2) {
        // OUTPUT_LEVEL
        // std::cout << "DEBUG [" << now << "]: CNT OVERFLOW RETURN" << '\n';
        // level--;
        return -1;
    }
    if (now > n) {
        // level--;
        return 0;
    }
    // OUTPUT_LEVEL
    // std::cout << "DEBUG [" << now << "]: cnt0 = " << cnt0 << ", cnt1 = " << cnt1 << ", cnt2 = " << cnt2 << '\n';
    int sat0 = satisfy[now][0];
    int sat1 = satisfy[now][1];
    int sat2 = satisfy[now][2];
    int ans = -1;
    // OUTPUT_LEVEL
    // std::cout << "DEBUG [" << now << "]: CHOICING A" << '\n';
    int res0 = dfs(now + 1, cnt0 + 1, cnt1, cnt2);
    // OUTPUT_LEVEL
    // std::cout << "DEBUG [" << now << "]: CHOICING B" << '\n';
    int res1 = dfs(now + 1, cnt0, cnt1 + 1, cnt2);
    // OUTPUT_LEVEL
    // std::cout << "DEBUG [" << now << "]: CHOICING C" << '\n';
    int res2 = dfs(now + 1, cnt0, cnt1, cnt2 + 1);
    // OUTPUT_LEVEL
    // std::cout << "DEBUG [" << now << "]: satisfy = { " << sat0 << ", " << sat1 << ", " << sat2 << " }" << '\n';
    // OUTPUT_LEVEL
    // std::cout << "DEBUG [" << now << "]: result = { " << res0 << ", " << res1 << ", " << res2 << " }" << '\n';
    if (res0 != -1 && res0 + sat0 > ans) {
        // OUTPUT_LEVEL
        // std::cout << "DEBUG [" << now << "]: GOING TO A" << '\n';
        ans = res0 + sat0;
    }
    if (res1 != -1 && res1 + sat1 > ans) {
        // OUTPUT_LEVEL
        // std::cout << "DEBUG [" << now << "]: GOING TO B" << '\n';
        ans = res1 + sat1;
    }
    if (res2 != -1 && res2 + sat2 > ans) {
        // OUTPUT_LEVEL
        // std::cout << "DEBUG [" << now << "]: GOING TO C" << '\n';
        ans = res2 + sat2;
    }
    // level--;
    return ans;
}
