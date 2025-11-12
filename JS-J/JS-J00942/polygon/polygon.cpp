#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using i64 = long long;

int sun(std::set<int> jiangjun)
{
    int s = 0;
    for (int i : jiangjun)
    {
        s += i;
    }
    return s;
}

int main(void)
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    i64 n, ans = 0;
    std::set<std::set<int>> aset;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int m = 3; m <= n; ++m)
    {
        auto v = a;
        //permutation
        while (std::next_permutation(v.begin(), v.end()))
        {
            std::set<int> smile;
            for (int k = 0; k < m; ++k)
                smile.insert(v[k]);
            if (smile.size() < m)
                continue;
            if (!aset.count(smile))
            {
                int sum = sun(smile);
                if (sum > 2 * *std::max_element(smile.begin(), smile.end()))
                {
                    ++ans;
                    aset.insert(smile);
                }
            }
        }
    }
    std::cout << ans % 998244353;
    return 0;
}