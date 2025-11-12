#include <bits/stdc++.h>

using namespace std;

int a[110];

bool px(int x, int y) {
    return x > y;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    int r = m * n;
    for (int i = 1;i <= r;i++) {
        cin >> a[i];
    }

    int p = a[1];
    sort(a + 1, a + r + 1, px);

    int pm = 0;
    for (int i = 1;i <= r;i++) {
        if (a[i] == p) {
            pm = i;
            break;
        }
    }

    int l = (pm - 1) / n + 1;
    int h = 0;
    if (l % 2 != 0) {
        h = pm - ((n * (l - 1)));
    } else {
        h = n - (pm - ((n * (l - 1)))) + 1;
    }
    cout << l << " " << h;
    return 0;
}
