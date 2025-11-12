#include<bits/stdc++.h>
using namespace std;
int a[20] = {1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1};
int c[20] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10};
int b[100];
int n, m;
int t;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    if (n == 1) {
        for (int i = 0; i < m; i ++) {
            cin >> b[i];
        }
        t = b[0];
        sort(b, b + m, cmp);
        for (int i = 0; i < m; i ++) {
            if (b[i] == t) {
                cout << i + 1 << " " << 1 << endl;
                return 0;
            }
        }
    }else if (n == 2) {
        for (int i = 0; i < m * n; i ++) {
            cin >> b[i];
        }
        t = b[0];
        sort(b, b + (m * n), cmp);
        int k;
        for (int i = 0; i < m * n; i ++) {
            if (b[i] == t) {
                k = i;
            }
        }
        int aa, bb;
        aa = c[k];
        bb = a[k];
        cout << aa << " " << bb << endl;
    }else if (m == 1) {
        for (int i = 0; i < n; i ++) {
            cin >> b[i];
        }
        t = b[0];
        sort(b, b + n, cmp);
        for (int i = 0; i < n; i ++) {
            if (b[i] == t) {
                cout << 1 << " " << i + 1 << endl;
                return 0;
            }
        }
    }else if (m == 2) {
        for (int i = 0; i < m * n; i ++) {
            cin >> b[i];
        }
        t = b[0];
        sort(b, b + (m * n), cmp);
        int k;
        for (int i = 0; i < m * n; i ++) {
            if (b[i] == t) {
                k = i + 1;
            }
        }
        if (k <= n) {
            cout << 1 << " " << k << endl;
        }else {
            cout << 2 << " " << n + n - k + 1 << endl;
        }
    }
    return 0;
}
