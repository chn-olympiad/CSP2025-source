#include <bits/stdc++.h>
using namespace std;

int a[500001], n, k, ans, cnt, sum;
bool ok;

void dfs(int u) {
    printf("Now u is %d    ", u);
    if (u > n) {
        ans = max(ans, cnt);
        return;
    }
    int i = u;
    while (sum != k && i <= n) {
        sum ^= a[i];
        if (sum == k) {
            cnt++;
            sum = 0;
            break;
        }
        if (sum != k && i == n) {
            ans = max(ans, cnt);
            return;
        }
        i++;
    }
    printf("Now i is %d\n", i);
    for (int j = i + 1; j <= n; j++) {
        dfs(j);
        cnt--;
    }
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ok &= (a[i] == 1)
    }
    if (k == 0 && ok) {
        printf("%d", n / 2);
        return 0;
    }
    if (k == 1 && ok) {
        printf("%d", n);
        return 0;
    }
    for (int i = 1; i <= n; i++)
        dfs(i);
    printf("%d", ans + 1);
}
