#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int a[N];
int sum[N];
struct node {
    int l, r;
} L[N];

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    int cnt = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        cnt += (a[i] == 0);
        mx = max(mx, a[i]);
        sum[i] = sum[i - 1] ^ a[i];
    }

    if (mx <= 1) {
        if (k == 0) {
            int ans = cnt;
            for (int i = 1; i <= n; ) {
                if (a[i] == 1 && a[i + 1] == 1) ans++, i += 2;
                else i++;
            }
            return cout << ans, 0;
        } else return cout << n - cnt, 0;
    }

    int tot = 0;
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
            if ((sum[r] ^ sum[l - 1]) == k)
                L[++tot] = {l, r};
    sort(L + 1, L + tot + 1, [&](const node& x, const node& y) {
        if (x.r != y.r) return x.r < y.r;
        return x.l < y.l;
    });

    int R = L[1].r, ans = 1;
    for (int i = 2; i <= tot; i++)
        if (R < L[i].l) {
            R = L[i].r;
            ans++;
        }
    cout << ans;

    return 0;
}
