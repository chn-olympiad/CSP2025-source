#include<bits/stdc++.h>
using namespace std;
int n, cnt;
int a[5005], b[3];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (n == 3) {
        if ((a[1] + a[2]) > a[3] && (a[1] + a[3]) > a[2] && (a[3] + a[2]) > a[1]) {
            cout << 1 << endl;
        }else {
            cout << 0 << endl;
        }
    }else if (n == 4) {
        for (int i = 1; i <= 4; i ++) {
            if (i == 1) {
                if ((a[2] + a[3] + a[4]) > 2 * max(a[2], max(a[3], a[4]))) {
                    cnt ++;
                }
            }else if (i == 2) {
                if ((a[1] + a[3] + a[4]) > 2 * max(a[1], max(a[3], a[4]))) {
                    cnt ++;
                }
            }else if (i == 3) {
                if ((a[2] + a[1] + a[4]) > 2 * max(a[2], max(a[1], a[4]))) {
                    cnt ++;
                }
            }else if (i == 4) {
                if ((a[2] + a[3] + a[1]) > 2 * max(a[2], max(a[3], a[1]))) {
                    cnt ++;
                }
            }
        }
        if ((a[1] + a[2] + a[3] + a[4]) > 2 * max(a[1], max(a[2], max(a[3], a[4])))) {
            cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}
