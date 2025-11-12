#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int mod = 998244353;
int c[maxn];
long long fact(int n) {
    long long res = 1;
    while (n > 0) {
        res *= n;
        res %= mod;
        n--;
    }
    return res;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    string hardness;
    cin >> hardness;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        if (c[i] > 0) cnt++;
    }
    printf("%lld", fact(cnt));
    return 0;
}
