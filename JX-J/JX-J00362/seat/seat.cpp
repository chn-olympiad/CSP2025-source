#include<bits/stdc++.h>
using namespace std;
int m, n, a[15];
int cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++) {
        cin >> a[i];
    }
    int k = a[1];
    sort(a + 1, a + 1 + n * m, cmp);
    for(int i = 1; i <= n * m; i++) {
        if(a[i] == k) {
            k = i;
            break;
        }
    }
    int c, r;
    if(k % n == 0) c = k / n;
    else c = k / n + 1;
    if(c % 2 == 1) {
        r = k % n;
        if (r == 0) r = n;
    }
    else {
        r = n - k % n + 1;
    }
    cout << c << ' ' << r;
    return 0;
}
