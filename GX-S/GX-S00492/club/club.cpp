#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

int n;

long long getFullMax(std::vector<std::vector<int>> a1, std::vector<std::vector<int>> a2, std::vector<std::vector<int>> a3) {
    long long sum1 = 0, sum2 = 0, sum3 = 0;
    std::sort(a1.begin()+1, a1.end(), [](std::vector<int> _a, std::vector<int> _b) {
        return _a[1] > _b[1];
    });
    std::sort(a2.begin()+1, a2.end(), [](std::vector<int> _a, std::vector<int> _b) {
        return _a[2] > _b[2];
    });
    std::sort(a3.begin()+1, a3.end(), [](std::vector<int> _a, std::vector<int> _b) {
        return _a[3] > _b[3];
    });
    // for (int i = 1; i <= n; ++i) {
    //     std::cout << a1[i][1] << ' ';
    // }
    // std::cout << '\n';
    // for (int i = 1; i <= n; ++i) {
    //     std::cout << a2[i][2] << ' ';
    // }
    // std::cout << '\n';
    // for (int i = 1; i <= n; ++i) {
    //     std::cout << a3[i][3] << ' ';
    // }
    // std::cout << '\n';

    for (int i = 1; i <= n; ++i) {
        if (i <= n / 2) {
            sum1 += a1[i][1];
            sum2 += a2[i][2];
            sum3 += a3[i][3];
            continue;   
        }
        sum1 += std::max(a1[i][2], a1[i][3]);
        sum2 += std::max(a2[i][1], a2[i][3]);
        sum3 += std::max(a3[i][1], a3[i][2]);
    }
    // std::cout << sum1 << ' ' << sum2 << ' ' << sum3 << '\n';
    return std::max({ sum1, sum2, sum3 });
}

long long getAns2(std::vector<std::vector<int>> a) {
    long long result = 0;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
            result += a[i][1];
            cnt1++;
        } else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
            result += a[i][2];
            cnt2++;
        } else {
            result += a[i][3];
            cnt3++;
        }
        if (cnt1 > n / 2 || cnt2 >n/ 2 || cnt3 > n / 2) {
            return 0;
        }
    }
    //std::cout << result << '\n';
    return result;
}

void sol() {
    std::cin >> n;
    std::vector<std::vector<int>> a(n+1, std::vector<int>(4));
    for (int i = 1; i <= n; ++i) std::cin >> a[i][1] >> a[i][2] >> a[i][3];
    std::cout << std::max(getFullMax(a, a, a), getAns2(a)) << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}