#include <bits/stdc++.h>

using namespace std;

const int N = 550;
const int mod = 998244353;

int n, m;
string s;
int a[N], b[N];

int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    cin >> s;
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    if (m == 1) {
        int sum = 1;
        for (int i = 1; i <= n; i ++ )
            sum = (1ll * sum * i) % mod;
            printf("%d", sum);
        return 0;
    }
    bool all1 = 1;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] != '1') all1 = 0;
    }

    if (all1) {
        int x = 1;
        for (int i = 1; i <= m; i ++ ) {
            x = (1ll * x * (n -- )) % mod;
        }
        printf ("%d", x);
        return 0;
    }
    return 0;
}
