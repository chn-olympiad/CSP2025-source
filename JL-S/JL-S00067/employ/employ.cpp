#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int n, m, c[510];
long long ans = 1;
char s[510];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 2; i <= n; i++) {
        ans *= (1LL * i);
        ans %= P;
    }
    printf("%lld\n", ans);
    return 0;
}
