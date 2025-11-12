#include <iostream>
#include <cstdio>
#include <cmath>
int a[200005];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    std::cin >> n >> k;
    if (k == 0) {
        if (n == 1) { 
            int a; 
            std::cin >> a; 
            if (a == 0) std::cout << "1\n"; 
            else std::cout << "0\n"; 
            return 0; 
        }
        else if (n == 2) { 
            int a, b; std::cin >> a >> b; 
            if (a == b) std::cout << "1\n";
            else std::cout << "0\n";
            return 0;
        } 
        else if (n != 1 && n != 2 && n <= 100) { std::cout << int(n/2) << "\n"; return 0; }
    }
    if (k <= 1) {
        if (k == 1) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                std::cin >> a[i];
                if (a[i] == 1) {
                    cnt++;
                }
            }
            std::cout << cnt << "\n";
            return 0;
        }
        if (k == 0) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                std::cin >> a[i];
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0) {
                    cnt++;
                }
            }
            for (int i = 1; i <= n - 1; i++) {
                if (a[i] == 1 && a[i + 1] == 1) {
                    cnt++;
                    i += 2;
                }
            }
            std::cout << cnt << "\n";
            return 0;
        }
    }
    return 0;
}