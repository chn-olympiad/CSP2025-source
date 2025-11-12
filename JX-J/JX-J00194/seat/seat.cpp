#include <bits/stdc++.h>
#define L 110
using namespace std;
typedef long long ll;
int n, m;
int a[L];
int r, rk;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; i++) {
        if(a[i] == r) {
            rk = i;
        }
    }
    if(rk % n == 0) {
        if(rk / n % 2 == 0) {
            cout << rk / n << " " << 1;
        }
        else if(rk / n % 2 == 1) {
            cout << rk / n << " " << n;
        }
    }
    else if(rk % n != 0) {
        cout << rk / n + 1 << " ";
        if((rk / n + 1) % 2 == 0) {
            cout << n - rk % n + 1;
        }
        else if((rk / n + 1) % 2 == 1) {
            cout << rk % n;
        }
    }
}
