#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
const int N = 1e5 + 10;
int n;
struct node {
    int a, b, c;
}a[N];
int op[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i].a >> a[i].b >> a[i].c;
    int ans = 0;
    int cnta = 0, cntb = 0, cntc = 0;
    for (int i = 1; i <= n; i ++) {
        int ma = max(a[i].a, max(a[i].b, a[i].c));
        if (ma == a[i].a) cnta ++, op[i] = 1;
        else if (ma == a[i].b) cntb ++, op[i] = 2;
        else cntc ++, op[i] = 3;
        ans += ma;
    }
    if (cnta > n / 2) {
        priority_queue<int> q;
        for (int i = 1; i <= n; i ++)
            if (op[i] == 1) q.push(max(a[i].b, a[i].c) - a[i].a);
        while (cnta > n / 2) ans += q.top(), q.pop(), cnta --;
    }
    if (cntb > n / 2) {
        priority_queue<int> q;
        for (int i = 1; i <= n; i ++)
            if (op[i] == 2) q.push(max(a[i].a, a[i].c) - a[i].b);
        while (cntb > n / 2) ans += q.top(), q.pop(), cntb --;
    }
    if (cntc > n / 2) {
        priority_queue<int> q;
        for (int i = 1; i <= n; i ++)
            if (op[i] == 3) q.push(max(a[i].a, a[i].b) - a[i].c);
        while (cntc > n / 2) ans += q.top(), q.pop(), cntc --;
    }
    cout << ans << endl;
}

int main() {
    clock_t __c = clock();
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t --) solve();
    cerr << endl << "RUNTIMES: " << clock() - __c;
    return 0;
}
// 放平心态，没事的