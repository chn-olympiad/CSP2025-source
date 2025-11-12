#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define per(i, r, l) for(int i = (int) r; i >= (int) l; i--)

const int N = 5010, mod = 998244353;
int n, a[N], k[N];
int c[N][N], ans;

void dfs(int i) {
    if(i == n + 1) {
        int sum = 0, ma = 0;
        rep(j, 1, n)
            sum += k[j] * a[j], ma = max(ma, k[j] * a[j]);
        if(sum > 2 * ma) ans = (ans + 1) % mod;
        return;
    }
    k[i] = 0;
    dfs(i + 1);
    k[i] = 1;
    dfs(i + 1);
}


int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    int ma = 0;
    rep(i, 1, n)
        scanf("%d", &a[i]), ma = max(ma, a[i]);
    if(ma > 1) {
        dfs(1);
        printf("%d\n", ans);
        return 0;
    }
    c[1][1] = 1;
    rep(i, 2, n)
        rep(j, 1, i)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    rep(i, 1, n)
        rep(j, i + 1, n) {
            int x = n - j;
            int y = x / 2, z = x % 2;
            rep(k, 1, x)
                ans = (ans + c[x + 1][k + 1]) % mod;
        }
    printf("%d\n", ans);
}
