#include <bits/stdc++.h>
// #define int long long
#define loop(i, a, b) for(int i = (a) ; i <= (int)(b) ; i++)
#define rloop(i, a, b) for(int i = (b) ; i >= (int)(a) ; i--)
#define chkmin(a, b) (a = min(a, b))
#define chkmax(a, b) (a = max(a, b))
using namespace std;
const int N = 1e2 + 5;
int n, m;
array<int, 2> a[N];
void solve() {
    cin >> n >> m;
    loop(i, 1, n * m) cin >> a[i][0], a[i][1] = i;
    sort(a + 1, a + n * m + 1, greater<>());
    int id = -1;
    loop(i, 1, n * m) if(a[i][1] == 1) id = i - 1;
    int x = id / n;
    int y = (x % 2 == 0 ? id % n : n - 1 - (id % n));
    cout << x + 1 << ' ' << y + 1 << '\n';
}
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}