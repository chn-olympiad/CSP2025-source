#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, ans, a[5005];
int read() {
    int f = 1, x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void solve1() {
    int maxx = max(max(a[1], a[2]), a[3]), sum = a[1] + a[2] + a[3];
    if(sum > maxx * 2) printf("1\n");
    else printf("0\n");
}
void solve2() {
    int ans = 0;
    for(int i = 3; i <= n; i++) 
        ans = (ans % mod + (n / i) % mod) % mod;
    printf("%d\n", ans);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    if(n <= 3) {
        solve1();
        return 0;
    }
    else {
        solve2();
        return 0;
    }
    return 0;
}