#include <bits/stdc++.h>

#define get_xor(l, r) (ps[l - 1] ^ ps[r])

int n, k, p = 1, s = 0, a[500010], ps[500010];

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], ps[i] = ps[i - 1] ^ a[i];

    for (int r = 1; r <= n; ++r)
        for (int l = r; l >= p; --l)
            if (get_xor(l, r) == k)
            {
                p = r + 1;
                s++;
                break;
            }

    std::cout << s;

    return 0;
}
