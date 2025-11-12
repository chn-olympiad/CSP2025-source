#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cin >> n >> m;
    std::vector<int> a(n * m);
    for (int i = 0; i < n * m; ++i)
    {
        std::cin >> a[i];
    }
    int target = a[0];
    std::sort(a.begin(), a.end());
    auto nm = std::lower_bound(a.begin(), a.end(), target);
    int ansnm = a.end() - nm; // find where it is
    int i = (ansnm % n ? ansnm / n + 1 : ansnm / n);
    int fakej = ansnm % n;
    if (!fakej)
        fakej = n;
    int j = (i & 1 ? fakej : n - fakej + 1);
    std::cout << i << " " << j;
    return 0;
}