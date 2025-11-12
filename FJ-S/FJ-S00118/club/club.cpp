#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct node {
    int a, b, c;
} p[N];
node A[N], B[N], C[N];
int ctA, ctB, ctC;
void init() {
    ctA = ctB = ctC = 0;
}
inline bool cmpA(node x, node y) {
    return min(x.a - x.b, x.a - x.c) > min(y.a - y.b, y.a - y.c);
}
inline bool cmpB(node x, node y) {
    return min(x.b - x.a, x.b - x.c) > min(y.b - y.a, y.b - y.c);
}
inline bool cmpC(node x, node y) {
    return min(x.c - x.a, x.c - x.b) > min(y.c - y.a, y.c - y.b);
}
void solve() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b >> p[i].c;
        if (p[i].a >= p[i].b && p[i].a >= p[i].c) A[++ctA] = p[i];
        else if (p[i].b > p[i].a && p[i].b >= p[i].c) B[++ctB] = p[i];
        else if (p[i].c > p[i].a && p[i].c > p[i].b) C[++ctC] = p[i];
    }
    if (ctA > n / 2 || ctB > n / 2 || ctC > n / 2) {
        if (ctA > n / 2) {
            sort(A + 1, A + ctA + 1, cmpA);
            while (ctA > n / 2) {
                int i = ctA;
                if (A[i].b > A[i].c) B[++ctB] = A[i];
                else C[++ctC] = A[i];
                ctA--;
            }
        } else if (ctB > n / 2) {
            sort(B + 1, B + ctB + 1, cmpB);
            while (ctB > n / 2) {
                int i = ctB;
                if (B[i].a > B[i].c) A[++ctA] = B[i];
                else C[++ctC] = B[i];
                ctB--;
            }
        } else {
            sort(C + 1, C + ctC + 1, cmpC);
            while (ctC > n / 2) {
                int i = ctC;
                if (C[i].a > C[i].b) A[++ctA] = C[i];
                else B[++ctB] = C[i];
                ctC--;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= ctA; i++) ans += A[i].a;
    for (int i = 1; i <= ctB; i++) ans += B[i].b;
    for (int i = 1; i <= ctC; i++) ans += C[i].c;
    return cout << ans << '\n', void();
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T; cin >> T; while (T--) solve();
}