#include <bits/stdc++.h>

int n, m, x, l, r, mid, a[110];

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    std::cin >> n >> m;

    l = 1, r = n * m;

    for (int i = 1; i <= r; ++i)
        std::cin >> a[i];
    x = a[1];

//    std::cout << "test" << std::endl;

    std::sort(a + 1, a + 1 + r);

    while (l < r)
    {
        mid = l + r >> 1;
        if (a[mid] == x)
            l = r = mid;
        else if (a[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
//        std::cout << l << ' ' << r << std::endl;
    }

    l = n * m - l + 1;

//    std::cout << l << ' ';

    std::cout << (l - 1) / n + 1 << ' ' << (((l - 1) / n + 1) & 1? (l - 1) % n + 1: n - (l - 1) % n);

    return 0;
}
