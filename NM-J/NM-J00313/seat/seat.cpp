#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int a[N], A;

bool cmp(int x, int y) { return x > y; }

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    A = a[1];
    sort(a + 1, a + n * m + 1, cmp);

    int num;
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == A) {
           num = i; 
        }
    }

    int c, r;
    c = ceil(1.0 * num / n);
    if (c % 2 == 1) {
        r = num - n * (c - 1);
    } else {
        r = n - num + n * (c - 1) + 1;
    }
    // cout << num;
    cout << c << ' ' << r;
    return 0;
}