#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10, M = 998244353;

ll n, ans, a[N];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        (ans *= i) %= M;
    }
    cout << ans;
    return 0;
}
