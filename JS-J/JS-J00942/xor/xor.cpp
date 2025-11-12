#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

int n, k;
std::vector<std::pair<int, int>> vp;

bool in_range(int start, int end)
{
    for (auto p : vp)
    {
        if ((p.first <= start && start <= p.second) || (p.first <= end && end <= p.second))
            return true;
        else if ((start <= p.first && p.first <= end) || (start <= p.second && p.second <= end))
            return true;
    }
    return false;
}

int main(void)
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int unknown = 0, un2 = 0;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i], unknown += (a[i] == 1), un2 += !a[i];
    if (unknown == n)
        std::cout << (n >> 1);
    else if (unknown + un2 == n)
    {
        if (k)
            std::cout << unknown;
        else
        {
            int scs = 0;
            for (int i = 0; i + 1 < n; ++i)
            {
                if (a[i] & 1 && a[i + 1] & 1)
                    scs++;
            }
            std::cout << un2 + scs;
        }
    }
    else
    {
        int tans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; i + j < n; ++j)
            {
                int ans = 0;
                for (int m = j; m <= i + j; ++m)
                    ans ^= a[m];
                if (ans == k && !in_range(j, i + j))
                {
                    ++tans;
                    vp.push_back({j, i + j});
                }
            }
        }
        std::cout << tans;
    }
    return 0;
}