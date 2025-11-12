#include<bits/stdc++.h>
using namespace std;
const int N = 5000, MOD = 998244353;
int n, num[N];
bool chose[N];
long long dfs(int k, int l, int to, int mx, int sum) {
    if (k == l) {
//        for (int i = 0; i < n; i++)
//            if (chose[i])
//                printf("%d ", num[i]);
//        printf("\t%d\t%d\n", mx, sum);
        if (sum > 2 * mx) return 1;
        else return 0;
    }
    long long cnt = 0;
    for (int i = to; i < n; i++)
        if (!chose[i]) {
            chose[i] = true;
            cnt = (cnt + dfs(k + 1, l, i, max(mx, num[i]), sum + num[i])) % MOD;
            chose[i] = false;
        }
    return cnt;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    long long cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = 3; i <= n; i++)
        cnt = (cnt + dfs(0, i, 0, 0, 0)) % MOD;
    printf("%lld", cnt);
    return 0;
}