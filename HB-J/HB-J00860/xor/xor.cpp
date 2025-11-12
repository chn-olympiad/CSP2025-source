#include <bits/stdc++.h>
#define lx long long
using namespace std;
lx n , k , a[500005] , ans = 0 , cnt = 0 , sum = 0;
bool flag = 0;
int main () {
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    if (n <= 2) cout << "1";
    else {
        for (lx i = 1 ; i <= n ; i ++) {
            cin >> a[i];
            if (a[i] > 1) flag = 1;
        }
        if (!flag) {
            for (lx i = 1 ; i <= n ; i ++) {
                if (a[i] == k) ans ++;
                else {
                    if (k == 0 && a[i] == 1 && a[i + 1] == 0 || k == 0 && a[i] == 1 && a[i + 1] == 1) {
                        ans ++;
                        i ++;
                    }
                    else i ++;
                }
            }
            cout << ans;
        }
        else {
            for (lx i = 1 ; i <= n ; i ++) {
                sum = a[i] ^ a[i + 1];
                for (lx j = i ; j <= n ; j ++) {
                    if (a[j] == k) {
                        ans ++;
                        break;
                    }
                    else if (sum == k) {
                        i ++;
                        ans ++;
                        break;
                    }
                    else {
                        if (j + 1 <= n) {
                            sum ^= a[j + 1];
                            if (sum == k) {
                                i += j + 1;
                                if (i > n) {
                                    cout << ans;
                                    return 0;
                                }
                                ans ++;
                                break;
                            }
                            else continue;
                        }
                    }
                }
            }
            cout << ans;
        }
    }
    return 0;
}
