#include <bits/stdc++.h>
using namespace std;

int n, m, score_R;
int a[200];

bool cmp (int an, int bn) {
    return an < bn;
}

int lfminci() {
    for (int i = 200; i >= 0; i--) {
        int now = a[i - 1];
        if (now == score_R) return 201 - i;
    }
}

int main() {
    freopen("seat3.in", "r", stdin);
    freopen("seat3.out", "w", stdout);

    cin >> n >> m >> score_R;
    a[1] = score_R;
    for (int i = 2; i <= n * m; i++)
        cin >> a[i];

    sort(a, a + 200, cmp);
    int minci = lfminci();
    int rm = (minci + n - 1) / n, t = (minci - 1) % (2 * n);
    cout << rm << ' ' << ((0 <= t && t < n) ? t + 1 : 2 * n - t);
    return 0;
}
