#include<iostream>
#include<cstdlib>
#include<algorithm>

constexpr int N = 10 + 5;

int n, m, a[N * N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen("seat.in", "r", stdin);
    std::freopen("seat.out", "w", stdout);

    std::cin >> n >> m;
    for(int i = 1; i <= n * m; ++i) std::cin >> a[i];
    int a1 = a[1], rk;
    std::sort(a + 1, a + n * m + 1, std::greater<int>());
    for(int i = 1; i <= n * m; ++i) if(a[i] == a1) { rk = i; break; }
    int c = (rk + n - 1) / n;
    int r = rk % n; r ? 0 : r = n;
    if(!(c & 1)) r = n - r + 1;
    std::cout << c << " " << r << '\n';

    return 0;
}
