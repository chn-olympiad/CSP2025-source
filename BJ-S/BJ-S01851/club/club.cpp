#include <bits/stdc++.h>
using namespace std;

int n, mx = -2e9;
const int N = 1e5 + 10;
struct Node {
    int a, b, c;
}h[N];
int a[N], b[N], c[N];
int ab[N], ac[N], ba[N], bc[N], ca[N], cb[N];
int sab[N], sac[N], sba[N], sbc[N], sca[N], scb[N];

void dfs(int step, int x, int y, int z, int sum) {
    if (x > n / 2 || y > n / 2 || z > n / 2) return;
    if (step > n) {
        mx = max(mx, sum);
        return;
    }
    dfs(step + 1, x + 1, y, z, sum + h[step].a);
    dfs(step + 1, x, y + 1, z, sum + h[step].b);
    dfs(step + 1, x, y, z + 1, sum + h[step].c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> h[i].a >> h[i].b >> h[i].c;
        if (n <= 17) {
            mx = -2e9;
            dfs(1, 0, 0, 0, 0);
            cout << mx << "\n";
            continue;
        }
        for (int i = 1; i <= n; ++i) a[i] = b[i] = c[i] = ab[i] = ac[i] = ba[i] = bc[i] = ca[i] = cb[i] = sab[i] = sac[i] = sba[i] = sbc[i] = sca[i] = scb[i] = 0;
        int aa = 0, bb = 0, cc = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (h[i].a >= h[i].b && h[i].a >= h[i].c) a[++aa] = i, ans += h[i].a;
            else if (h[i].b >= h[i].a && h[i].b >= h[i].c) b[++bb] = i, ans += h[i].b;
            else c[++cc] = i, ans += h[i].c;
        }
        if (aa > n / 2) {
            for (int i = 1; i <= aa; ++i) ab[i] = h[a[i]].a - h[a[i]].b, ac[i] = h[a[i]].a - h[a[i]].c;
            sort(ab + 1, ab + aa + 1);
            sort(ac + 1, ac + aa + 1);
            for (int i = 1; i <= aa; ++i) sab[i] = sab[i - 1] + ab[i], sac[i] = sac[i - 1] + ac[i];
            int mn = 2e9;
            for (int i = 0; i <= aa; ++i) {
                int j = aa - n / 2 - i;
                if (bb + i > n / 2 || cc + j > n / 2) continue;
                mn = min(mn, sab[i] + sac[j]);
            }
            cout << ans - mn << "\n";
        }
        else if (bb > n / 2) {
            for (int i = 1; i <= bb; ++i) ba[i] = h[b[i]].b - h[b[i]].a, bc[i] = h[b[i]].b - h[b[i]].c;
            sort(ba + 1, ba + bb + 1);
            sort(bc + 1, bc + bb + 1);
            for (int i = 1; i <= bb; ++i) sba[i] = sba[i - 1] + ba[i], sbc[i] = sbc[i - 1] + bc[i];
            int mn = 2e9;
            for (int i = 0; i <= bb; ++i) {
                int j = bb - n / 2 - i;
                if (aa + i > n / 2 || cc + j > n / 2) continue;
                mn = min(mn, sba[i] + sbc[j]);
            }
            cout << ans - mn << "\n";
        }
        else if (cc > n / 2) {
            for (int i = 1; i <= cc; ++i) ca[i] = h[c[i]].c - h[c[i]].a, cb[i] = h[c[i]].c - h[c[i]].b;
            sort(ca + 1, ca + cc + 1);
            sort(cb + 1, cb + cc + 1);
            for (int i = 1; i <= cc; ++i) sca[i] = sca[i - 1] + ca[i], scb[i] = scb[i - 1] + cb[i];
            int mn = 2e9;
            for (int i = 0; i <= cc; ++i) {
                int j = cc - n / 2 - i;
                if (aa + i > n / 2 || bb + j > n / 2) continue;
                mn = min(mn, sca[i] + scb[j]);
            }
            cout << ans - mn << "\n";
        }
        else cout << ans << "\n";
    }
    return 0;
}
