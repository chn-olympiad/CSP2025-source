#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
int a[1000005], p;
bool cmp(int a, int b) { return a > b; }
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    std::string s;
    std::cin >> s;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            a[++p] = c - '0';
        }
    }
    std::sort(a + 1, a + p + 1, cmp);
    for (int i = 1; i <= p; i++) {
        std::cout << a[i];
    }
    std::cout << "\n";
    return 0;
}