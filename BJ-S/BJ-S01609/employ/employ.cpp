#include <cstdio>
using namespace std;

const int N = 110;
const int MOD = 998244353;
int n, m;
char s[N];
int c[N];

int main () {
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", c + i);
    }
    long long ans = 1;
    for (int i = 2; i <= n; i ++) {
        ans *= i;
        ans %= MOD;
    }
    printf("%lld", ans);
    return 0;
}