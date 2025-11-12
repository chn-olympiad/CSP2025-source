#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5007];
bool check(int x) {
    int maxa = 0, sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(x >> i & 1) {
            maxa = max(maxa, a[i + 1]);
            sum += a[i + 1];
            ++cnt;
        }
    }
    if(cnt < 3) {
        return false;
    }
    return sum > 2 * maxa;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    int maxa = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        if(check(i)) {
            ++ans;
        }
    }
    printf("%d\n", ans);
}
/*

*/
