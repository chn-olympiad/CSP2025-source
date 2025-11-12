#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
struct Node {
    int a, b, c;
} node[N];
bool vis[N];
int cnt1, sum1;
int cnt2, sum2;
int cnt3, sum3;
bool cmp (Node x, Node y) {
    if (x.a == y.a) {
        if (x.b == y.b)
            return x.c > y.c;
        return x.b > y.b;
    }
    return x.a > y.a;
}

void init() {
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf ("%d%d%d", &node[i].a, &node[i].b, &node[i].c);
    if (n == 2) {
        int ans = max({node[1].a + node[2].b, node[1].a + node[2].c, node[1].b + node[2].a, node[1].b + node[2].c, node[1].c + node[2].a, node[1].c + node[2].b});
        printf("%d", ans);
        return ;
    }
    sort (node + 1, node + 1 + n, cmp);
    for (int i = 1; i <= n; i ++ ) {
        int a = node[i].a, b = node[i].b, c = node[i].c;
        if (a > b && a > c && !vis[i] && cnt1 < n / 2) {
            cnt1 ++ ;
            ans += a;
            sum1 += a;
            vis[i] = 1;
        } else if (b > c && b > a && !vis[i] && cnt2 < n / 2) {
            cnt2 ++ ;
            ans += b;
            sum2 += b;
            vis[i] = 1;
        } else if (c > a && c > b && !vis[i] && cnt3 < n / 2) {
            cnt3 ++ ;
            ans += c;
            sum3 += c;
            vis[i] = 1;
        } else {
            if (a > b && a > c) node[i].a = 0;
            else if (b > a && b > c) node[i].b = 0;
            else if (c > a && c > b) node[i].c = 0;
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        int a = node[i].a, b = node[i].b, c = node[i].c;
        if (vis[i]) continue;
        if (a > b && a > c && !vis[i] && cnt1 < n / 2) {
            cnt1 ++ ;
            ans += a;
            sum1 += a;
            vis[i] = 1;
        } else if (b > c && b > a && !vis[i] && cnt2 < n / 2) {
            cnt2 ++ ;
            ans += b;
            sum2 += b;
            vis[i] = 1;
        } else if (c > a && c > b && !vis[i] && cnt3 < n / 2) {
            cnt3 ++ ;
            ans += c;
            sum3 += c;
            vis[i] = 1;
        } else {
            if (a > b && a > c) node[i].a = 0;
            else if (b > a && b > c) node[i].b = 0;
            else if (c > a && c > b) node[i].c = 0;
        }
    }

    for (int i = 1; i <= n; i ++ ) {
        int a = node[i].a, b = node[i].b, c = node[i].c;
        if (vis[i]) continue;
        if (a > b && a > c && !vis[i] && cnt1 < n / 2) {
            cnt1 ++ ;
            ans += a;
            sum1 += a;
            vis[i] = 1;
        } else if (b > c && b > a && !vis[i] && cnt2 < n / 2) {
            cnt2 ++ ;
            ans += b;
            sum2 += b;
            vis[i] = 1;
        } else if (c > a && c > b && !vis[i] && cnt3 < n / 2) {
            cnt3 ++ ;
            ans += c;
            sum3 += c;
            vis[i] = 1;
        } else {
            if (a > b && a > c) node[i].a = 0;
            else if (b > a && b > c) node[i].b = 0;
            else if (c > a && c > b) node[i].c = 0;
        }
    }
    printf("%lld\n", ans);
}
int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T -- ) {
        cnt1 = cnt2 = cnt3 = sum1 = sum2 = sum3 = 0;
        memset (vis, 0, sizeof vis);
        memset (node, 0, sizeof node);
        init();
    }
    return 0;
}

