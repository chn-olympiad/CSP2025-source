#include <bits/stdc++.h>

using namespace std;

int num[10];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    freopen("number.out", "w", stdout);
    freopen("number.in", "r", stdin);

    memset(num, 0, sizeof num);

    char c = getchar();
    while (c != '\n') {
        if (c >= '0' && c <= '9') {
            int p = c - '0';
            ++num[p];
        }
        c = getchar();
    }

    for (int i = 9; i >= 0; --i) {
        for (int j = 0; j < num[i]; ++j) {
            cout << i;
        }
    }

    return 0;
}
