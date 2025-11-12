#include<bits/stdc++.h>

using namespace std;
const int MOD = 998244353;
int v[5014];
long long s[5014];
int n;
long long ans = 0;


int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    sort(v, v + n);
    if (n < 3) {
        if (v[0] + v[1] < v[2]) ans = 1;
    }

    cout << ans;
    return 0;
}
