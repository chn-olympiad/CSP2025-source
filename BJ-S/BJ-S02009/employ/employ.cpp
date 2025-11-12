#include <iostream>
#include <algorithm>
#include <string>
#define maxn 505

const long long mod = 998244353;
int s[maxn], c[maxn], n, m;
long long cnt;
std::string inp;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(false); std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> inp;
    for (int i = 1; i <= n; i++) s[i] = inp[i - 1] - '0';
    // for (int i = 1; i <= n; i++) std::cout << s[i] << "\n";
    for (int i = 1; i <= n; i++) std::cin >> c[i];
    bool b = 1;
    std::sort(c + 1, c + n + 1);
    while (b) {
        int cntl = 0, cntlu = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 1 && c[i] > cntl) cntlu++;
            else cntl++;
        }
        if (cntlu >= m) ++cnt;
        b = std::next_permutation(c + 1, c + n + 1);
    }
    std::cout << cnt;
    return 0;
}