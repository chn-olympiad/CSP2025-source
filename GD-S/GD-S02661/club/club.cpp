#include <bits/stdc++.h>

#define fst first
#define snd second

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using ld = long double;
using namespace std;
const int N = 100005;
ll T, n, sum, ans;
ll cnt[5];
pair <ll, ll> a[N][5];
ll solve(int id) {
    ll res = 0;
    vector <ll> v;
    for (int i = 1; i <= n; i++) {
        ll maxn = 0, tmp = 0;
        for (int j = 1; j <= 3; j++) {
            if (a[i][j].snd != id) maxn = max(maxn, a[i][j].fst);
            else tmp = a[i][j].fst;
        }
        v.push_back(tmp - maxn);
        res += maxn;
    }
    sort(v.begin(), v.end(), greater <int> ());
    for (int i = 0; i < n / 2; i++) res += v[i];
    return res;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x, y, z; cin >> x >> y >> z;
            a[i][1] = {x, 1}, a[i][2] = {y, 2}, a[i][3] = {z, 3};
            sort(a[i] + 1, a[i] + 1 + 3);
        }
        cnt[1] = cnt[2] = cnt[3] = sum = 0;
        for (int i = 1; i <= n; i++) cnt[a[i][3].snd]++, sum += a[i][3].fst;
        if (cnt[1] <= n / 2 and cnt[2] <= n / 2 and cnt[3] <= n / 2) ans = sum;
        else ans = max({solve(1), solve(2), solve(3)});
        cout << ans << '\n';
    }
    return 0;
}