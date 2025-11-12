#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> PII;
#define pb push_back
#define vi vector <int>
#define R(i, l, r) for (int i = (l); i <= (r); ++i)
#define debug cout << "-------------------------------\n"

const int N = 3e5 + 5, P = 998244353;
int n;
int a[N][3], num[4], cnt[4];
void solve() {
    cin >> n;
    priority_queue <int, vi, greater<int> > q[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    int ans = 0;
    int sum = 0;
    R(i, 1, n) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        num[0] = a[i][0], num[1] = a[i][1], num[2] = a[i][2];
        sort(a[i], a[i] + 3, greater<int>());
        int pos = 0;
        R(j, 0, 2) {
            if (num[j] == a[i][0]) {
                pos = j;
                break;
            }
        }
        ans += a[i][0];
        sum += a[i][0];
//        cout << i << ' ' << pos << ' ' << a[i][0] - a[i][1] << endl;
        ++cnt[pos];
        if (cnt[pos] <= n / 2) {
            q[pos].push(a[i][0] - a[i][1]);
        } else {
            --cnt[pos];
            int x = q[pos].top();
            int tmp = a[i][0] - a[i][1];
            if (x > tmp) {
                ans -= tmp;
            } else {
                q[pos].pop();
                ans -= x;
                q[pos].push(tmp);
            }
        }
    }
//    cout << sum << '\n';
    cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
