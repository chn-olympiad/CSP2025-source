// 100 pts

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int INF = 0x7f7f7f7f;

struct Solution {
    void main()
    {
        int n;
        scanf("%d", &n);

        if (n <= 200) {
            int half_n = n >> 1;
            vector<array<int, 3>> a(n);

            for (int i = 0; i < n; ++i)
                scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

            vector<vector<vector<int>>> f(2, vector<vector<int>>(half_n + 1, vector<int>(half_n + 1, -INF)));
            f[1][0][0] = 0;

            for (int i = 0; i < n; ++i) {
                f[i & 1].assign(half_n + 1, vector<int>(half_n + 1));

                for (int j = 0; j <= min(i + 1, half_n); ++j) {
                    for (int k = 0; k <= min(i + 1, half_n); ++k) {
                        if (j > 0)
                            f[i & 1][j][k] = max(f[i & 1][j][k], f[~i & 1][j - 1][k] + a[i][0]);

                        if (k > 0)
                            f[i & 1][j][k] = max(f[i & 1][j][k], f[~i & 1][j][k - 1] + a[i][1]);

                        f[i & 1][j][k] = max(f[i & 1][j][k], f[~i & 1][j][k] + a[i][2]);
                    }
                }
            }

            int ans = 0;

            for (int i = 0; i <= half_n; ++i) {
                for (int j = half_n - i; j <= half_n; ++j)
                    ans = max(ans, f[~n & 1][i][j]);
            }

            printf("%d\n", ans);
        } else {
            vector<array<int, 4>> a(n);
            vector<array<int, 3>> order(n);

            for (int i = 0; i < n; ++i) {
                scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
                a[i][3] = i;
                order[i] = { 0, 1, 2 };
                sort(order[i].begin(), order[i].end(), [&](int lhs, int rhs) { 
                    return a[i][lhs] > a[i][rhs]; 
                });
            }

            int cnt[3] = { 0, 0, 0 };
            vector<int> chosen(n);
            sort(a.begin(), a.end(), [&](const auto& lhs, const auto& rhs) {
                return lhs[order[lhs[3]][0]] - lhs[order[lhs[3]][1]] > rhs[order[rhs[3]][0]] - rhs[order[rhs[3]][1]];
            });

            for (int i = 0; i < n; ++i) {
                int idx = a[i][3];
                ++cnt[order[idx][0]];
                chosen[idx] = order[idx][0];
            }

            for (int i = n - 1; i >= 0; --i) {
                int idx = a[i][3];

                if (cnt[chosen[idx]] > n >> 1) {
                    --cnt[chosen[idx]];
                    ++cnt[order[idx][1]];
                    chosen[idx] = order[idx][1];
                }
            }

            sort(a.begin(), a.end(), [&](const auto& lhs, const auto& rhs) {
                return lhs[order[lhs[3]][1]] - lhs[order[lhs[3]][2]] > rhs[order[rhs[3]][1]] - rhs[order[rhs[3]][2]];
            });

            for (int i = n - 1; i >= 0; --i) {
                int idx = a[i][3];

                if (chosen[idx] == order[idx][1] && cnt[chosen[idx]] > n >> 1) {
                    --cnt[chosen[idx]];
                    ++cnt[order[idx][2]];
                    chosen[idx] = order[idx][2];
                }
            }

            int sum = 0;

            for (int i = 0; i < n; ++i)
                sum += a[i][chosen[a[i][3]]];

            printf("%d\n", sum);
        }
    }
};

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t-- > 0)
        Solution().main();
    
    return 0;
}