// I love CCF
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
int n, m;
bool s[510];
int c[510];
int index[510];
int main()
{
    std::freopen("employ.in", "r", stdin);
    std::freopen("employ.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin >> n >> m;
    char t;
    bool flag = true;
    for (int i = 1; i <= n; i++)
        std::cin >> t,
        s[i] = t == '1',
        flag &= s[i];
    for (int i = 1; i <= n; i++)
        std::cin >> c[i],
        index[i] = i;
    if (flag) // all 1 --- 20
    {
        int sum = 1;
        for (int i = n; i >= 1; i--)
            sum = (sum * i) % 998244353;
        std::cout << sum << '\n';
        return 0;
    }
    // chao ji bao li --- 8
    int sum = 0;
    do
    {
        int succ = 0;
        int fail = 0;
        for (int i = 1; i <= n && succ < m; i++)
            if (fail < c[index[i]] && s[i])
                    succ++;
            else
                fail++;
        if (succ >= m)
            sum = (sum + 1) % 998244353;
    }while (std::next_permutation(index + 1, index + n + 1));
    std::cout << sum << std::endl;
    return 0;
}
// 1 1 0 1 1 1 1 0 1 1
// 2 3 6 0 3 1 2 5 4 4
