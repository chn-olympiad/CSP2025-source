#include <iostream>
#include <cstdio>
using namespace std;

int n, k, a[500005], sum[500005], ans, ppos = 1;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum[i+1] = sum[i] ^ a[i];
        for (int j = i; j >= ppos; j--) {
            if (sum[i+1] ^ sum[j] == k) {
                ans++;
                ppos = i + 1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
