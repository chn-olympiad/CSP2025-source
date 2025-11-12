#include <bits/stdc++.h>
using namespace std;
int n, a[50000] = {0};
long long ans = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    //sum(c(a, len)) > 2 * max(c(a, len))

    return 0;
}
