#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100;

int a[N + 5];

int n, m;
int lpo;
int cnt, num;

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    num = n * m;
    for (int i = 1; i <= num; i++) {
        cin >> a[i];
    }
    lpo = a[1];

    sort(a + 1, a + 1 + m * n);

    for (int j = 1; j <= m; j++) {
        if (j % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                if (a[num] == lpo) {
                    cout << j << " " << i;
                    return 0;
                }
                else {
                    num--;
                }
            }
        }
        else {
            for (int i = n; i >= 1; i--) {
                if (a[num] == lpo) {
                    cout << j << " " << i;
                    return 0;
                }
                else {
                    num--;
                }
            }
        }
    }
    return 0;
}
