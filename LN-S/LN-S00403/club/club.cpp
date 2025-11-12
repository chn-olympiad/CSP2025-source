// I love CCF
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>

int n;
std::array<int, 3> a[100010];
int ans = -1;
void dfs(int i, int n1, int n2, int n3, int sum)
{
    if (i > n)
        return ans = std::max(ans, sum), void();
    if (n1 < n / 2)
        dfs(i + 1, n1 + 1, n2, n3, sum + a[i][0]);
    if (n2 < n / 2)
        dfs(i + 1, n1, n2 + 1, n3, sum + a[i][1]);
    if (n3 < n / 2)
        dfs(i + 1, n1, n2, n3 + 1, sum + a[i][2]);
}
int main()
{
    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);
    int T;
    std::cin >> T;
    while (T--)
    {
        ans = -1;
        std::cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 3; j++)
                std::cin >> a[i][j];
        dfs(1, 0, 0, 0, 0);
        std::cout << ans << '\n';
    }
    return 0;
}
