#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long

struct Node {
    int x, y, z;
} a[100005], f[100005], s[100005], t[100005];

int T, n, cnt[5], cntf, cntt, cnts;

bool cmp1(Node x, Node y) {
    return min(x.x - x.y, x.x - x.z) < min(y.x - y.y, y.x - y.z);
}

bool cmp2(Node x, Node y) {
    return min(x.y - x.x, x.y - x.z) < min(y.y - y.x, y.y - y.z);
}

bool cmp3(Node x, Node y) {
    return min(x.z - x.x, x.z - x.y) < min(y.z - y.x, y.z - y.y);
}

void solve() {
    memset(a, 0, sizeof a);
    memset(f, 0, sizeof f);
    memset(s, 0, sizeof s);
    memset(t, 0, sizeof t);
    memset(cnt, 0, sizeof cnt);
    cntf = 0;
    cnts = 0;
    cntt = 0;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int maxn = 0;
        cin >> a[i].x >> a[i].y >> a[i].z;
        maxn = max(a[i].x, max(a[i].y, a[i].z));
        if (maxn == a[i].x) {
            cnt[1]++;
            f[++cntf] = a[i];
        }
        else if (maxn == a[i].y) {
            cnt[2]++;
            s[++cnts] = a[i];
        }
        else {
            cnt[3]++;
            t[++cntt] = a[i];
        }
        ans += maxn;
    }
    if (cnt[1] > n / 2) {
        sort(f + 1, f + cntf + 1, cmp1);
        for (int i = 1; i <= cnt[1] - n / 2; i++)
            ans -= min(f[i].x - f[i].y, f[i].x - f[i].z);
    }
    if (cnt[2] > n / 2) {
        sort(s + 1, s + cnts + 1, cmp2);
        for (int i = 1; i <= cnt[2] - n / 2; i++)
            ans -= min(s[i].y - s[i].x, s[i].y - s[i].z);
    }
    if (cnt[3] > n / 2) {
        sort(t + 1, t + cntt + 1, cmp3);
        for (int i = 1; i <= cnt[3] - n / 2; i++)
            ans -= min(t[i].z - t[i].x, t[i].z - t[i].y);
    }
    cout << ans << endl;
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
        solve();
    return 0;
}
