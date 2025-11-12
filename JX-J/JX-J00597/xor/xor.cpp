#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5;
int a[N];
int n, k, ret;

int main() {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &a[i]);
    }
    if (k == 0) {
        for (int i = 1; i <= n; i ++) {
            if (a[i] == 0) ret ++;
            if (i != n && a[i] == a[i + 1]) {
                i ++;
                ret ++;
            }
        }
        printf ("%d\n", ret);
        return 0;
    }
    else if (k == 1) {
        for (int i = 1; i <= n; i ++) {
            if (a[i] == 1) ret ++;
            if (i != n && (a[i] + 1 == a[i + 1] || a[i] == a[i + 1] + 1)) {
                i ++;
                ret ++;
            }
        }
        printf ("%d\n", ret);
        return 0;
    }
    return 0;
}