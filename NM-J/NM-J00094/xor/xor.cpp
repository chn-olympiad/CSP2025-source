#include <bits/stdc++.h>
using namespace std;
int n, a[5000000] = {0}, ansMax = 0, r = 0, last = 1, sum = 0, lastSum = -1, l;
long long ans = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // 1 2 3 4 5
    for (int len = 1; len <= n; len++) {
        r = len;
        for (int i = 1; i <= len; i++) {
            for (int j = last; j <= last + i; i++) {
                sum ^= a[j];
            }
            if (sum == lastSum) {
                l++;
                ansMax = max(ansMax, l);
            }
            lastSum = sum;
        }
    }
    return 0;
}
