#include <bits/stdc++.h>
#define lx long long
using namespace std;
lx n , m , a[105] , ans = 0 , b[15][15] , sum = 0 , cnt = 0 , k = 0 , ansn , ansm;
int main () {
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for (lx i = 1 ; i <= n * m ; i ++) {
        cin >> a[i];
    }
    sort (a + 1 , a + n * m + 1);
    for (lx i = 1 ; i <= n * m ; i ++) {
        if (sum == a[i]) {
            cnt = i;
            break;
        }
    }
    if (n == 1) {
        for (lx i = 1 ; i <= n * m; i ++) {
            if (a[i] == sum) {
                cout << i << " " << "1";
                return 0;
            }
        }
    }
    else {
           if (cnt % m == 0) {
        if (cnt / m % 2 == 1) {
        ansm = m / cnt - 1;
        ansn = m % cnt;
        }
        else {
        ansm = m / cnt;
        for (lx i = 1 ; i <= m ; i ++) {
            if (i == m % cnt) ansn = m - i;
        }
        }
    }
    else {
        if (m / cnt % 2 == 1) {
        ansm = m / cnt;
        ansn = m % cnt;
        }
        else {
        ansm = m / cnt + 1;
        for (lx i = 1 ; i <= m ; i ++) {
            if (i == m % cnt) ansn = m - i;
        }
        }
    }
    cout << ansm << " " << ansn;
    }

    return 0;
}
