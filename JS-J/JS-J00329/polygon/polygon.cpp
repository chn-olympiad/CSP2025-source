#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005;
int a[N] ;
int n , ans;


void dfs (int ii , int step , int sum , int max_step , int last_ii) {
    if (step == max_step) {
        if (a[ii] * 2 >= sum) {
            return ;
        }else {
            ans = (ans + 1) % 998244353;
            return ;
        }
    }
    for (int i = ii + 1 ; i <= n; i++ ) {
        if (n - i + 1 >= max_step - step) {
            dfs (i , step + 1 , sum + a[i] , max_step , ii);
        }else return ;
    }
}

signed main () {
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1 , a + n + 1);
    for (int i = 3; i <= n; i++) {
        dfs (0 , 0 , 0 , i , -1);
    }
    cout << ans % 998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
