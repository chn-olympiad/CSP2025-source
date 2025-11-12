#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;++ i) cin >> a[i];
    bool flag = 1, flag1 = 1;
    for (int i = 1;i <= n;++ i){
        if (a[i] != 1) flag = 0;
        if (a[i] != 1&&a[i] != 0) flag1 = 0;
    }
    if (flag){
        if (n % 2 == 0) {
            cout << n / 2;
            return 0;
        }
        else {
            cout << (n - 1) / 2;
            return 0;
        }
    }
    if (flag1){
        int ans = 0;
        if (k == 0){
            for (int i = 1;i <= n;){
                if (a[i] == 1&&a[i + 1] == 1) ans ++, i += 2;
                else if (a[i] == 0) ans ++, ++ i;
                else ++ i;
            }
            cout << ans;
            return 0;
        }
        if (k == 1){
            for (int i = 1;i <= n;++ i){
                if (a[i] == 1) ans ++;
            }
            cout << ans;
            return 0;
        }
    }

    return 0;
}
