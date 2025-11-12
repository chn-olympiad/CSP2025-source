#include <bits/stdc++.h>
using namespace std;

int n, m, s, c, a[5005];
bool se[5005];

int arrayMax(int* a, int s, int e) {
    int mv = 0;
    for (int i = s; i <= e; i++) {
        mv = max(mv, a[i]);
    }
    return mv;
}

int arraySum(int* a, int s, int e) {
    int sv = 0;
    for (int i = s; i <= e; i++) {
        sv += a[i];
    }
    return sv;
}

int main () {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 2; i++) {
        int t[5005] = {0};
        for (int j = i + 2; j <= n; j++) {
            if (se[i]) {
                continue;
            }
            t[i] = a[i];
            m = arrayMax(t, i, j), s = arraySum(t, i, j);
            if (s > m) {
                //se[i] = true;
                c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}
