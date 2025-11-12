#include<bits/stdc++.h>
using namespace std;
int n, a[5005], sum[5005];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;++ i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    if (n == 3){
        int maxn = max(max(a[1], a[2]), a[3]);
        if (sum[n] > maxn * 2) cout << 1 << '\n';
        else cout << 0;
        return 0;
    }
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    return 0;
}
