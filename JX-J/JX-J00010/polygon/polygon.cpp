#include <bits/stdc++.h>
using namespace std;


int n, cnt, sum, maxa, ans;
int a[30];
void dfs(int x) {
    if(cnt > 2 * maxa) {
        ans ++;
        cnt = sum = maxa = 0;
    }
    cnt += a[x];
    maxa = max(maxa, a[x]);
    sum ++;
    if(x == n) dfs(1);
    else dfs(n + 1);
}
int main() {
     freopen("polygon.in", "r", stdin);
     freopen("polygon.out", "w", stdout);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    dfs(1);
    cout << ans;
    return 0;
}
