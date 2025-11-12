#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], b[500005], ans = 0;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if((b[j] ^ b[i - 1]) == k) {
                i = j, ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
