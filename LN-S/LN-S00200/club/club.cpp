#include <bits/stdc++.h>
int mainf()
{
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n);
    std::vector<int> chs(n);
    long long ans = 0;
    std::array<int, 3> cnt;
    cnt.fill(0);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        int mx = std::max({a[i][0], a[i][1], a[i][2]});
        ans += mx;
        for (int c = 0; c < 3; ++c)
        {
            if (a[i][c] == mx)
            {
                ++cnt[c];
                chs[i] = c;
                break;
            }
        }
    }
    int exc = -1;
    for (int c = 0; c < 3; ++c)
        if (cnt[c] > n/2)
            exc = c;
    if (exc == -1)
    {
        std::cout << ans << '\n';
        return 0;
    }
    std::vector<std::pair<int, int>> dts;
    dts.reserve(2*n);
    for (int i = 0; i < n; ++i)
    {
        if (chs[i] != exc)
            continue;
        for(int c = 0; c < 3; ++c)
        {
            if (c == exc)
                continue;
            dts.emplace_back(a[i][exc]-a[i][c], i);
        }
    }
    std::sort(dts.begin(), dts.end());
    int times = cnt[exc] - n/2;
    std::vector<bool> vis(n, false);
    int i = 0;
    while (times)
    {
        while (vis[dts[i].second])
            ++i;
        vis[dts[i].second] = true;
        ans -= dts[i].first;
        ++i; --times;
    }
    std::cout << ans << '\n';
    return 0;
}
int main()
{
    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--)
        mainf();
    return 0;
}