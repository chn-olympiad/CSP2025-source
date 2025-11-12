#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Node {
    int a, b, c, d, cho;
} w[N];
vector<long long> alls;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int A = 0, B = 0, C = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &w[i].a, &w[i].b, &w[i].c);
            int mn = min(w[i].a, min(w[i].b, w[i].c));
            if (mn == w[i].a) {
                w[i].a = -1;
                w[i].d = max(w[i].b, w[i].c) - min(w[i].b, w[i].c);
            } else if (mn == w[i].b) {
                w[i].b = -1;
                w[i].d = max(w[i].a, w[i].c) - min(w[i].a, w[i].c);
            } else {
                w[i].c = -1;
                w[i].d = max(w[i].a, w[i].b) - min(w[i].a, w[i].b);
            }
            int mx = max(w[i].a, max(w[i].b, w[i].c));
            if (mx == w[i].a) {
                A++;
                ans += w[i].a;
                w[i].cho = 1;
            } else if (mx == w[i].b) {
                B++;
                ans += w[i].b;
                w[i].cho = 2;
            } else {
                C++;
                ans += w[i].c;
                w[i].cho = 3;
            }
         }
         alls.clear();
         if (A >= n / 2) {
             int diff = A - n / 2;
             long long mn = 0x3f3f3f3f3f3f3f3f;
             for (int i = 1; i <= n; i++) {
                 if (w[i].cho == 1) alls.push_back(w[i].d);
             }
             sort(alls.begin(), alls.end());
             for (int i = 0; i < diff; i++) ans -= alls[i];
         } else if (B >= n / 2) {
            int diff = B - n / 2;
             long long mn = 0x3f3f3f3f3f3f3f3f;
             for (int i = 1; i <= n; i++) {
                 if (w[i].cho == 2) alls.push_back(w[i].d);
             }
             sort(alls.begin(), alls.end());
             for (int i = 0; i < diff; i++) ans -= alls[i];
         } else if (C >= n / 2) {
            int diff = C - n / 2;
             long long mn = 0x3f3f3f3f3f3f3f3f;
             for (int i = 1; i <= n; i++) {
                 if (w[i].cho == 3) alls.push_back(w[i].d);
             }
             sort(alls.begin(), alls.end());
             for (int i = 0; i < diff; i++) ans -= alls[i];
         }
         printf("%lld\n", ans);
    }
    return 0;
}
