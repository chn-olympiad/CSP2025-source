# include <algorithm>
# include <iostream>
# include <vector>

using std::cin;
using std::cout;
using std::vector;

struct member {
    int val[3];
    int fav;

    int cost() const {
        return std::min(val[0] - val[1], val[0] - val[2]);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<member> students(n);

        for (auto &a: students) {
            cin >> a.val[0] >> a.val[1] >> a.val[2];
            a.fav = int(std::max_element(a.val, a.val + 3) - a.val);
        }

        int cnt[3] = {0, 0, 0};
        int ans = 0;

        for (const auto &a: students) {
            cnt[a.fav] += 1;
            ans += a.val[a.fav];
        }

        if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
            cout << ans << "\n";
            continue;
        }

        if (cnt[0] > n / 2) {
            for (auto &a: students) {
                if (a.fav == 0) {
                    a.fav = 42;
                }
            }
        }
        if (cnt[1] > n / 2) {
            std::swap(cnt[0], cnt[1]);
            for (auto &a: students) {
                std::swap(a.val[0], a.val[1]);
                if (a.fav == 1) {
                    a.fav = 42;
                }
            }
        }
        if (cnt[2] > n / 2) {
            std::swap(cnt[0], cnt[2]);
            for (auto &a: students) {
                std::swap(a.val[0], a.val[2]);
                if (a.fav == 2) {
                    a.fav = 42;
                }
            }
        }

        vector<int> costs;
        costs.reserve(cnt[0]);

        for (const auto &a: students) {
            if (a.fav != 42) {
                continue;
            }

            costs.push_back(a.cost());
        }

        std::sort(costs.begin(), costs.end());

        for (int i = 0; i < cnt[0] - n / 2; ++i) {
            ans -= costs[i];
        }

        cout << ans << "\n";
    }

    return 0;
}
