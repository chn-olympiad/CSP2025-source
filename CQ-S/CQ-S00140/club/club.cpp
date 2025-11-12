#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5;
int n;
int a[MAXN + 5], b[MAXN + 5], c[MAXN + 5];
int d[MAXN + 5];
int read() {
    int x = 0;char ch = getchar();
    while (ch < '0' || ch > '9') ch  =getchar();
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
int main() {
    #ifndef LOCAL
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    #else
    freopen("./club/club5.in", "r", stdin);
    freopen("code.out", "w", stdout);
    clock_t BEGINT = clock();
    #endif
    int T; cin >> T;
    while (T --) {
        n = read();

        for (int i = 1; i <= n; i ++) a[i] = read(), b[i] = read(), c[i] = read();

        // a[i] 选了 n/2 个
        int ans1 = 0;
        for (int i = 1; i <= n; i ++) {
            // 选 a[i]
            // 选 max(b[i], c[i])
            d[i] = a[i] - max(b[i], c[i]);
        }
        sort(d + 1, d + 1 + n);
        for (int i = n; i > n / 2; i --) ans1 += d[i];
        for (int i = 1; i <= n; i ++) ans1 += max(b[i], c[i]);


        int ans2 = 0;
        for (int i = 1; i <= n; i ++) {
            // 选 b[i]
            // 选 max(a[i], c[i])
            d[i] = b[i] - max(a[i], c[i]);
        }
        sort(d + 1, d + 1 + n);
        for (int i = n; i > n / 2; i --) ans2 += d[i];
        for (int i = 1; i <= n; i ++) ans2 += max(a[i], c[i]);
        



        int ans3 = 0;
        for (int i = 1; i <= n; i ++) {
            // 选 c[i]
            // 选 max(a[i], b[i])
            d[i] = c[i] - max(a[i], b[i]);
        }
        sort(d + 1, d + 1 + n);
        for (int i = n; i > n / 2; i --) ans3 += d[i];
        for (int i = 1; i <= n; i ++) ans3 += max(a[i], b[i]);

        int ans4 = 0;
        int cnta = 0, cntb = 0, cntc = 0;
        for (int i = 1; i <= n; i ++) {
            int mx = max(max(a[i], b[i]), c[i]);
            if (mx == a[i]) {
                cnta ++;
                if (cnta > n / 2) {
                    ans4 = 0;
                    break;
                }
                ans4 += a[i];
            } else if (mx == b[i]) {
                cntb ++;
                if (cntb > n / 2) {
                    ans4 = 0;
                    break;
                }
                ans4 += b[i];
            } else if (mx == c[i]) {
                cntc ++;
                if (cntc > n / 2) {
                    ans4 = 0;
                    break;
                }
                ans4 += c[i];
            }
        }
        printf("%d\n", max(max(ans1, ans2), max(ans3, ans4)));    
    }
    
    #ifdef LOCAL
    clock_t ENDT = clock();
    cerr<<endl<<fixed<<setprecision(3)<<(double)(ENDT - BEGINT) / CLOCKS_PER_SEC;
    #endif
    return 0;
}