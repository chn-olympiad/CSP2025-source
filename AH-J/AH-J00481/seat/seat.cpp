#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int cnt = 1;
int a[105];
int b[15][15];
bool cmd(int x, int y) {
    return x > y;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    x = a[1];

    sort(a + 1, a + n * m + 1, cmd);
    
    for(int j = 1; j <= m; j++) {
        if (j % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                b[i][j] = a[cnt];
                cnt++;
                if (b[i][j] == x) {
                    cout << j << ' ' << i;
                    return 0;
                }
            }
        } else {
            for (int i = n; i >= 1; i--) {
                b[i][j] =  a[cnt];
                cnt++;
                if (b[i][j] == x) {
                    cout << j << ' ' << i;
                    return 0;
                }
            }
        }
    }
    
    for (int i = 1; i <= n * m; i++) {
        cout << a[i];
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//g++ seat.cpp -o seat.exe;./seat.exe