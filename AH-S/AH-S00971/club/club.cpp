#include <bits/stdc++.h>

using ll = long long;

using namespace std;

const int N = 1e5 + 10;

struct node {
    ll a[3], id;
    ll A, B;
} a[N];

int n, testcasdess;
bool used[N];

ll getans (int X, int Y, int Z) {
    for (int i = 1; i <= n; i ++) used[i] = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        a[i].A = a[i].a[X] - a[i].a[Z];
        a[i].B = a[i].a[Y] - a[i].a[Z];
        ans += a[i].a[Z];
    }
    int cnt1 = 0, cnt2 = 0, limit = n / 2;
    sort (a + 1, a + n + 1, [&](auto x, auto y) { return x.A > y.A; });
    for (int i = 1; i <= n; i ++) {
        if (a[i].A < 0) break ;
        if (a[i].A > a[i].B && cnt1 < limit) {
            ans += a[i].A, cnt1 ++, used[a[i].id] = true; 
        }
    }

    sort (a + 1, a + n + 1, [&](auto x, auto y) { return x.B > y.B; });
    for (int i = 1; i <= n; i ++) {
        if (a[i].B < 0) break ;
        if (!used[a[i].id] && cnt2 < limit) {
            ans += a[i].B, cnt2 ++, used[a[i].id] = true; 
        }
    }
    sort (a + 1, a + n + 1, [&](auto x, auto y) { return x.A > y.A; });
    for (int i = 1; i <= n; i ++) {
        if (a[i].A < 0) break;
        if (!used[a[i].id] && cnt1 < limit) {
            ++ cnt1;
            ans += a[i].A; 
            used[a[i].id] = true;
        } 
    }

    int cnt = cnt1 + cnt2;
    if (cnt >= limit) return ans;
    else return -1;
}

void work () {testcasdess ++;
    fprintf (stderr, "");

    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++) scanf ("%lld%lld%lld", &a[ a[i].id = i ].a[0], &a[i].a[1], &a[i].a[2]);
    printf ("%lld\n", max ({getans (0, 1, 2), getans (1, 2, 0), getans (2, 0, 1)}));
}

int main (void) {

    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);

    int t; scanf ("%d", &t);
    while (t --) work ();

    return 0;
}