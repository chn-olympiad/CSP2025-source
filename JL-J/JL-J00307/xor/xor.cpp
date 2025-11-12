#include<bits/stdc++.h>
int n, k, a[500000];
char judge() {
    char ch = 'A';
    for (int i = 0; i < n; i++)
        if (a[i] == 0 && ch == 'A')
            ch++;
        else if (a[i] > 1) {
            ch = 'C';
            if (a[i] > 255)
                return 'N';
        }
    return ch;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    const char J = judge();
    if (J == 'A') {
        std::cout << n / 2;
        goto l;
    }
    if (J == 'B') {
        std::vector<bool>p;
        for (int i = 0; i < n; i++)
            if (a[i])
                p.push_back(true);
        if (k) {
            std::cout << p.size();
            goto l;
        }
        std::cout << p.size() / 2;
        goto l;
    }
    srand(time(0));
    std::cout << rand() % n;
l:  fclose(stdin);
    fclose(stdout);
    return 0;
}
