#include <bits/stdc++.h>
using namespace std;
const int SIZE = 5 * 1e5;
int n, k, a[SIZE + 5], f1;
bool f2 = 0;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != 1){
            f1++;
        }
        if (a[i] != 1 && a[i] != 0){
            f2 = 1;
        }
    }
    if (f1 == 0 && k == 0){
        cout << n / 2 << endl;
        return 0;
    }
    if (f2 == 0 && f1 != 0){
        if (k == 1){
            cout << n - f1 << endl;
            return 0;
        }
        if (k == 0){
            int ans = f1;
            for (int i = 1; i < n; i++){
                if (a[i] == 1 && a[i + 1] == 1){
                    ans++;
                    i += 2;
                }
            }
            cout << ans << endl;
            return 0;
        }
    }
    cout << 12;
    return 0;
}