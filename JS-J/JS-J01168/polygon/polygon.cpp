#include <bits/stdc++.h>
using namespace std;
long long x = 998244353;
long long n, a[5005], f[5005], ans, sum;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i];
    }
    if (n < 3){
        cout << 0;
        return 0;
    }
    if (n == 3){
        if (sum > 2 * a[n])  cout << 1;
        else     cout << 0;
        return 0;
    }
    return 0;
}
