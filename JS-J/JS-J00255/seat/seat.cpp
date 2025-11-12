#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1010], s[20][20];
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int fal = a[1];
    int k = n * m, cnt = 0;
    sort(a + 1, a + k + 1, cmp);
    //cout << "ok" << endl;
    for (int i = 1; i <= m; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = a[++cnt];
            }
        }
        else {
            for (int j = n; j >= 1; j--) {
                s[i][j] = a[++cnt];
            }
        }
    }
    //cout << "ok" << endl;
    int tx = 0, ty = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == fal) {
                tx = i, ty = j;
                break;
            }
        }
    }
    cout << tx << " " << ty;
    return 0;
}
