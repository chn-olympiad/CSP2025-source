#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans;
int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        int sum = a[i];
        if (sum == k) {
            ans++;
            continue;
        }
        for (int j = i+1; j <= n; j++) {
            sum = sum^a[j];
            if (sum == k) {
                ans++;
                i = j;
                break;
            }
        }
    }
    printf ("%d", ans);
    return 0;
}
