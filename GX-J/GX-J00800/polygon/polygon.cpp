#include <bits/stdc++.h>
using namespace std;
int n, ans, sum, a[5010], i, b[5010];
void dfs(int x) {
    for (int j = b[i - x];j < n - i + 1;j++) {
        if (x == 0) {
            sum = 0;
            for (int l = 0;l < i;l++) sum += a[b[l]];
            if (sum > 2 * a[b[i - 1]]) ans++;
        }else{
            b[i - x + 1] = j;
            dfs(x - 1);
        }
        return;
    }
}
int main () {
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    cin >> n;
    for (i = 0;i < n;i++) cin >> a[i];
    sort (a, a + n);
    for (i = 3;i < n;i++) {
        b[0] = 0;
        dfs(i);
    }
    cout << ans;
    return 0;
}
