#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[500005], vis[500005], ans = 1;
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[i] = vis[i - 1] ^ a[i];
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (n == 2) {
        cout << 1;
        return 0;
    }
    vector<pair<int, int>> vec;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            if ((vis[r] ^ vis[l - 1]) == k) {
                vec.push_back(make_pair(l, r));
            }
        }
    }
    sort(vec.begin(), vec.end(), [](pair<int, int> l, pair<int, int> r) {
       return l.second < r.second;
    });
    if (vec.size() == 0) {
        cout << 0;
        return 0;
    }
    pair<int, int> last = vec[0];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vec[j].first > last.second) {
                last = vec[j];
                ans++;
                continue;
            }
        }
    }
    cout << ans;
    cout << '\n';
    return 0;
}
