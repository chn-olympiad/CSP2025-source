#include <bits/stdc++.h>
using namespace std;

long long n, k, a[500005], ans, l = 0, sum[500005];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    sum[0] = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = l; j <= i - 1; j++) {
            if ((k ^ sum[j]) == sum[i]) {
                ans++;
                l = i;
                break;
            }
        }
    }
    cout << ans;
	return 0;
}
