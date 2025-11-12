#include <iostream>
#include <string>

std::string str;
long long arr[10];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    std::cin >> str;
    for (const char& ch : str) {
        if (ch >= '0' and ch <= '9') {
            arr[ch - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--) {
        while(arr[i]--) {
            std::cout << i;
        }
    }
    std::cout << '\n';
    return 0;
}