#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100010;
int T, n;
struct node {
    int a, b, c;
    int d;
} a[N];
vector<int> A, B, C;
void solve() {
    scanf("%d", &n);
    A.clear();
    B.clear();
    C.clear();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].c);
        if (a[i].a >= a[i].b && a[i].a >= a[i].c) {
            A.push_back(i);
            ans += a[i].a;
        } else if (a[i].b >= a[i].a && a[i].b >= a[i].c) {
            B.push_back(i);
            ans += a[i].b;
        } else {
            C.push_back(i);
            ans += a[i].c;
        }
    }
    if (A.size() > n / 2) {
        for (int i : A) {
            a[i].d = a[i].a - max(a[i].b, a[i].c);
        }
        sort(A.begin(), A.end(), [&](const auto &x, const auto &y) {
            return a[x].d > a[y].d;
        });
        while (A.size() > n / 2) {
            int x = A.back();
            A.pop_back();
            ans -= a[x].d;
        }
    }
    if (B.size() > n / 2) {
        for (int i : B) {
            a[i].d = a[i].b - max(a[i].a, a[i].c);
        }
        sort(B.begin(), B.end(), [&](const auto &x, const auto &y) {
            return a[x].d > a[y].d;
        });
        while (B.size() > n / 2) {
            int x = B.back();
            B.pop_back();
            ans -= a[x].d;
        }
    }
    if (C.size() > n / 2) {
        for (int i : C) {
            a[i].d = a[i].c - max(a[i].a, a[i].b);
        }
        sort(C.begin(), C.end(), [&](const auto &x, const auto &y) {
            return a[x].d > a[y].d;
        });
        while (C.size() > n / 2) {
            int x = C.back();
            C.pop_back();
            ans -= a[x].d;
        }
    }
    printf("%d\n", ans);
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) solve();
}