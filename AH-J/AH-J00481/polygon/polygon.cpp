#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int cnt1 = 0;

int summ(int x, int c) {
    int sum = 0;
    for (int i = 1; i <= c; i++) {
        sum += a[x];
    }
    return 0;
}
int maxx(int x, int c) {
    int b[1005];
    for (int i = 1; i <= 5005; i++) {
        b[i] = a[i];
    }
    sort(b + 1, b + 5006);
    return b[1005] * 2;
}

int f(int m) {
    while (m--) {
        if (summ(f(m - 1), f(m - 2)) > maxx(f(m - 1), f(m - 2))) {
            cnt1++;
        }
    }

    if (m == 1) {
        return 1;
    }
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 3; i <= n; i++) {
        f(i);
    }
    cout << cnt1;
    return 0;
}
//g++ polygon.cpp -o polygon.exe;./polygon.exe