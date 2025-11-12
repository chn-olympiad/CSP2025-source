# include <bits/stdc++.h>
using namespace std;
int n , a[5005];
int main () {
    freopen ("polygon.in" , "r" , stdin);
    freopen ("polygon.out" , "w" , stdout);
    cin >> n;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    if (a[1] + a[2] + a[3] > 2 * max (a[1] , max (a[2] , a[3]))) {
        cout << 1;
    }
    else cout << 0;
    fclose (stdin);
    fclose (stdout);
    return 0;
}
