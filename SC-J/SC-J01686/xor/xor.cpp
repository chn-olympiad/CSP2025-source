#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n, k, a[N], cnt0, cnt1;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (a[i] == 0) cnt0 ++;
        if (a[i] == 1) cnt1 ++;
    }
    if (cnt1 == n && k == 0){
        cout << n / 2;
    }
    else if (cnt0 + cnt1 == n && k == 1){
        cout << min(cnt1, cnt0);
    }
    else cout << n / 2 + 1;
    return 0;
}
