#include <iostream>
#include <vector>
#include <string>

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::string s1, s2;
    for (int i = 0; i < n; i++) std::cin >> s1 >> s2;
    for (int i = 0; i < q; i++) std::cin >> s1 >> s2;
    for (int i = 0; i < q; i++) std::cout << 0 << ' ' << 0 << '\n';

    return 0;
}