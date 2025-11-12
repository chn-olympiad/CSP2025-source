// 0pt
// 怎么完不成今日 325 大学习了
#include <bits/stdc++.h>
const int mod = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::freopen("employ.in", "r", stdin);
    std::freopen("employ.out", "w", stdout);
    auto stime = std::chrono::steady_clock::now();
    int n, m;
    std::cin >> n >> m;
    std::vector<int> s(n + 1), c(n + 1), cnt(n + 1), sc(n + 1);
    for (int i = 1; i <= n; ++i) {
        char t;
        std::cin >> t, s[i] = t - '0';
    }
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i], ++cnt[c[i]];
    std::partial_sum(cnt.rbegin(), cnt.rend(), sc.rbegin());
    using arr = std::vector<long long>;
    using brr = std::vector<arr>;
    using crr = std::vector<brr>;
    crr f(n + 1, brr(n + 1, arr(n + 1)));
    f[0][0][0] = 1ll;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (j != 0 && s[i] == 1) {
                    int k1 = k + 1 - cnt[j];
                    if (k1 > 0 && k1 <= n)
                        f[i][j][k] += k1 * f[i - 1][j - 1][k1] % mod;
                }
                else if (j != 0) {
                    int k1 = k + 1 - cnt[j];
                    if (k1 >= 0 && k1 <= n)
                        f[i][j][k] += (k1 + cnt[j]) * f[i - 1][j - 1][k1] % mod;
                    k1 = k - cnt[j];
                    if (k1 >= 0 && k1 <= n && j != n && sc[j + 1])
                        f[i][j][k] += f[i - 1][j - 1][k1];
                }
                if (s[i] == 1) {
                    if (cnt[j]) {
                        int k1 = k + 1 - cnt[j];
                        if (k1 >= 0 && k1 <= n)
                            f[i][j][k] += f[i - 1][j][k1] * cnt[j] % mod;
                    }
                    if (j != n && sc[j + 1]) {
                        int k1 = k + cnt[j];
                        if (k1 >= 0 && k1 <= n)
                            f[i][j][k] += f[i - 1][j][k1];
                    }
                }
                f[i][j][k] %= mod;
            }
        }
    }
    arr fac(n + 1);
    fac[0] = 1ll;
    for (int i = 1; i <= n; ++i)
        fac[i] = fac[i - 1] * i % mod;
    auto res = 0ll;
    for (int j = 0; j <= n - m; ++j)
        for (int k = 0; k <= n; ++k)
            res += fac[k] * f[n][j][k] % mod;
    std::cout << res % mod << '\n';
    std::cerr << std::fixed << std::setprecision(6) << std::chrono::duration<double>(std::chrono::steady_clock::now() - stime).count() << "s\n";
    return 0;
}
/*
好像退烧了。
排列题、似乎没什么状压意味，似乎也不能连续段（存疑）
特殊性质？好像没什么用。看看 n^4 是什么东西。
看不出来，先写前三题吧

居然还剩一个多小时，比去年有进步
但还是糖糖的

如果设前 $i$ 个数里的 $0$，感觉挺靠谱的，因为没后效性

若前 $i$ 个数一共填了 $j$ 个 $0$，那么考虑转移：

- 第 $i$ 位为 $0$ 且 $s_i=1$，则从 $(i-1,j-1)$ 转移，且要求第 $i$ 位是一个 $c_k\le j-1$ 的数。
- 第 $i$ 位为 $0$ 且 $s_i=0$，从 $(i-1,j-1)$ 转移，填哪个数都行
- 第 $i$ 位为 $1$ 且 $s_i=1$，从 $(i-1,j)$ 转移，且要求第 $i$ 位是一个 $c_k>j-1$ 的数。

如果记录 $(i,j,k)$ 表示前 $i$ 位有 $j$ 个 $0$，且有 $k$ 个 $c_i\le j$，可行吗？可以求出下一步的 $k$ 吗？

- 第 $i$ 位为 $0$ 且 $s_i=1$

  则从 $(i-1,j-1,k')$ 转移，且要求第 $i$ 位是一个 $c_k\le j-1$ 的数。

  $k=k'-1+cnt_j$，要求 $k'\ne 0$。

- 第 $i$ 位为 $0$ 且 $s_i=0$

  从 $(i-1,j-1,k')$ 转移，填哪个数都行

  $k=k'-1+cnt_j$，要求 $k\ge 0$。

  或，$k=k'+cnt_j$，要求 $cnt_{j+1\cdots n}\ne 0$。

- 第 $i$ 位为 $1$ 且 $s_i=1$

  从 $(i-1,j)$ 转移，且要求第 $i$ 位是一个 $c_k>j-1$ 的数。

  $k=k'+cnt_j-1$，要求 $cnt_j\ne 0$。

  $k=k'+cnt_j$，要求 $cnt_{j+1\cdots n}\ne 0$。

咦我怎么会了。

糟糕考虑漏了一个东西。

0pt
*/