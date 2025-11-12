#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int n, k, cnt, a[maxn], s[maxn];
bool check(int l, int r, int l1, int r1) {
    if(abs(s[l - 1] - s[r]) == abs(s[l1 - 1] - s[r1]) && abs(s[l - 1] - s[r]) == k)
        return true;
    return false;
}
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
    for(int i = 1; i <= n; i++) cnt += a[i];
    if(k == 1) printf("%d\n", cnt);
    else printf("%d\n", n - cnt);
}
void solve2() {
    int ans = 0;
    if(n % 2 == 0) {
        for(int i = 2; i <= n; i++) {
            if(i % 2 == 0)
                ans += ceil(n * 1.0 / i);
        }
        printf("%d\n", ans);
    }
}
void solve3() {
    int  ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int m = 1; m <= n; m++) {
                    if(check(i, j, k, m) && i <= j && k > j && k <= m)
                        ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    n = read(); k = read();
    bool fl = true;
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        if(a[i] != 0 && a[i] != 1) fl = false;
    }
    for(int i = 1; i <= n; i++)s[i] = s[i - 1] ^ a[i];
    if(k == 0) {
        solve2();
        return 0;
    }
    else if(fl) {
        solve1();
        return 0;
    }
    else {
        solve3();
        return 0;
    }
    return 0;
}