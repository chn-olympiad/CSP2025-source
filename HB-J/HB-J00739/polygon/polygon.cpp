#include <bits/stdc++.h>
using namespace std;

int n, a[5010];
long long ans;

int main() {

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    if(n==3) {
        if(a[0]+a[1]+a[2] > max(a[0],a[1],a[2])*2) {
            ans = 1;
        }
    }
    cout << ans % 998244353;

    return 0;
}
