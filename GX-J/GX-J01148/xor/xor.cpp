#include <cstdio>
#include <iostream>
using namespace std;
int n, k, ans;
int a[1000010];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ) {
        int sum = a[i];
        if (sum == k) {
            ans++;
            i++;
        }
        else {
            for (int j = (i+1); j < n; j++) {
                sum ^= a[j];
                if (sum == k) {
                    ans++;
                    i = (j+1);
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
