#include <bits/stdc++.h>
#define lx long long
using namespace std;
lx n , a[5005] , ans = 0;
int main () {
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for (lx i = 1 ; i <= n ; i ++) {
        cin >> a[i];
    }
    sort (a + 1 , a + n + 1);
    for (lx i = n ; i >= 1 ; i --) {
        for (lx j = i - 1 ; j >= 1 ; j --) {
            for (lx k = j - 1 ; k >= 1 ; k --) {
                if (a[i] + a[j] + a[k] > a[i] * 2) {
                    ans += (k * k - k) / 2 + 1;
                }
                else if (a[i] + a[j] + a[k] == a[i] * 2) {
                    ans += k - 1;
                }
                else break;
            }
        }
    }
    cout << ans;
    return 0;
}
