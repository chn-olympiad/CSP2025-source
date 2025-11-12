#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second 
#define pb push_back 
#define mk make_pair 
#define db double 
using namespace std;
const int MAXN = 1e6 + 5, INF = 1e18;

int n, m, ans;
int s[4];
pii b[4];

struct node {
    int d[4], x, x2, id, id2;
    bool operator < (const node &A) const {
        return (x - x2) < (A.x - A.x2);
    }
} a[MAXN];

void Solve() {
    ans = 0;
    cin >> n;
    s[1] = s[2] = s[3] = 0; 
    for (int i = 1; i <= n; i ++) cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
    for (int i = 1; i <= n; i ++){
        b[1].fi = a[i].d[1], b[1].se = 1;
        b[2].fi = a[i].d[2], b[2].se = 2;
        b[3].fi = a[i].d[3], b[3].se = 3;
        sort(b + 1, b + 4);
        a[i].x = b[3].fi, a[i].x2 = b[2].fi;
        a[i].id = b[3].se, a[i].id2 = b[2].se;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++){
        int id = a[i].id, id2 = a[i].id2;
        if (s[id] == n / 2){
            ans += a[i].x2;
            s[id2] ++;
        }
        else {
            ans += a[i].x;
            s[id] ++;
        }
    }
    printf("%lld\n", ans);
}

signed main() {
    // if (!system("fc club.out club5.ans")) puts("Yes");
    // else puts("No");
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T --) Solve();
    return 0;
}