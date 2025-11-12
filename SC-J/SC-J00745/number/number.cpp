#include <cstdio>
#include <iostream>
#include <algorithm>

const int N = 1e6 + 10;
int a[N], tot;

bool cmp(int a, int b) {
    return a > b;
}

int main() {

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    std :: string s;
    std :: cin >> s;
    for (auto c : s) if (c >= '0' && c <= '9') a[++ tot] = c - '0';
    std :: sort(a + 1, a + tot + 1, cmp);
    for (int i = 1; i <= tot; i ++) printf("%d", a[i]);
    printf("\n");

    return 0;
}