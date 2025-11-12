#include<bits/stdc++.h>

using namespace std;
int seat[11][11];
int c = 0;
int r = 0;
int a0;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int f[114];

    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        f[i] = x;
    }
    a0 = f[0];
    sort(f, f + (n * m));


    for (int j = 1; j <= m; j++) {
        if (j % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                seat[i][j] = f[n * m -(n * j - n + i)];
            }
        }
        else {
            for (int i = n; i >= 1; i--) {
                seat[i][j] = f[n * m - (n * j - i + 1)];
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (seat[i][j] == a0) {
                c += j;
                r += i;
                break;
            }
        }
    }

    cout << c << ' ' << r << endl;

    return 0;
}
