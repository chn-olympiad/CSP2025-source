#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[1010] = {0};
    int z, pos_z;
    for (int i = 1; i <= n * m; i ++) {
        cin >> a[i];
    }
    z = a[1];
    sort(a + 1, a + 1 + n * m, cmp);
    for (int i = 1; i <= n * m; i ++) {
        if (a[i] == z) {
            pos_z = i;
            break;
        }
    }
    int sg = 2, h = 0; // h lun dao di ji ge ren
    for (int l = 1; l <= m; l ++) {
        if (!(sg % 2)) {
            for (int i = 1; i <= n; i ++) {
                h ++;
                if (h == pos_z) {
                    cout << l << " " << i << endl;
                    return 0;
                }
            }
        }
        else {
            for (int i = n; i >= 1; i --) {
                h ++;
                if (h == pos_z) {
                    cout << l << " " << i << endl;
                    return 0;
                }
            }
        }
        sg ++;
    }
    return 0;
}
