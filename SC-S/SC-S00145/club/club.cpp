#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n;
struct node {
    int a, b, c;
    int id;
} a[N];
int cnt[4];
int mx;

void dfs(int x, int sum) {
    if (x > n) {
        mx = max(mx, sum);
        return;
    }

    dfs(x + 1, sum);
    if (cnt[1] < n / 2) {
        cnt[1]++;
        dfs(x + 1, sum + a[x].a);
        cnt[1]--;
    }
    if (cnt[2] < n / 2) {
        cnt[2]++;
        dfs(x + 1, sum + a[x].b);
        cnt[2]--;
    }
    if (cnt[3] < n / 2) {
        cnt[3]++;
        dfs(x + 1, sum + a[x].c);
        cnt[3]--;
    }
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        bool f = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            if (a[i].b != 0 || a[i].c != 0) f = false;
        }

        if (f) {
            sort(a + 1, a + n + 1, [ & ](const node& x, const node& y) {
                return x.a > y.a;
            });

            int ans = 0;
            for (int i = 1; i <= n / 2; i++) ans += a[i].a;
            cout << ans << '\n';

            continue;
        }
        
        if (n <= 15) {
            mx = 0;
            dfs(1, 0);
            cout << mx << '\n';

            continue;
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += max({a[i].a, a[i].b, a[i].c});
        cout << ans << '\n';
    }

    return 0;
}
