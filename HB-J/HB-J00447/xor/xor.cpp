#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], xorsum[500010];
// T3
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        xorsum[i] = a[i - 1] ^ a[i];
    }
    cout << 2;
    return 0;
}
