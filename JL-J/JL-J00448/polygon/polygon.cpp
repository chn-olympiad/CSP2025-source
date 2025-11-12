#include <iostream>
#include <cstdio>
#define ma(a, b) ((a)>(b)?(a):(b))
int n, a[5005], book[5005], cnt;
const int mod = 998244353;
void dfs(int i, int sum, int max) {
    if (i >= n+2 && sum <= max*2) return; 
    if (i >= 4 && sum > max*2) {
        // std::cout << "D:" << i << " " << sum << " " << max << "\n";
        cnt++;
        cnt %= mod;
        return;
    }
    if (book[i] == 0) {
        book[i] = 1;
        dfs(i + 1, sum + a[i], ma(max, a[i]));
    }
    book[i] = 0;
    dfs(i + 1, sum, max);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    std::cin >> n;
    if (n < 3) {
        std::cout << "0\n";
        return 0;
    }
    if (n == 3) { //15
        int a, b, c;
        std::cin >> a >> b >> c;
        int maxx = ma(a, ma(b, c));
        if ((a + b + c) > maxx*2) {
            std::cout << "1\n";
        }
        else {
            std::cout << "0\n";
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    dfs(1, 0, 0);
    std::cout << cnt%mod << "\n";
    return 0;
}