#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int T, n;
int a[maxn][3], p[maxn];
vector<int> b;
int c[3];
int ans;
void work() {
    cin >> n; ans = 0;
    for (int i = 0; i <= 2; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) cin >> a[i][j];
        p[i] = 0;
        for (int j = 1; j <= 2; j++)
            if (a[i][j] > a[i][p[i]]) p[i] = j;
        c[p[i]]++; ans += a[i][p[i]];
    }
    int x = 0;
    for (int i = 1; i <= 2; i++)
        if (c[i] > c[x]) x = i;
    if (c[x] * 2 <= n) {cout << ans << '\n'; return;}
    b.clear();
    for (int i = 1; i <= n; i++) {
        if (p[i] != x) continue;
        int s = 0;
        for (int j = 0; j <= 2; j++)
            if (j != x) s = max(s, a[i][j]);
        b.push_back(a[i][x] - s);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < c[x] - n / 2; i++) ans -= b[i];
    cout << ans << '\n';
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) work();
    return 0;
}