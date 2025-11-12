# include <bits/stdc++.h>
using namespace std;
int n , k , a[500005] , sum , ans;
int main () {
    freopen ("xor.in" , "r" , stdin);
    freopen ("xor.out" , "w" , stdout);
    ios :: sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    cin >> n >> k;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        sum = a[i];
        if (sum == k) ans ++;
        else {
            for (int j = i + 1;j <= n;j ++) {
                sum ^= a[j];
                if (sum == k) {
                    ans ++;
                    i = j;
                    break;
                }
            }
        }
    }
    cout << ans;
    fclose (stdin);
    fclose (stdout);
    return 0;
}
