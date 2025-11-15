#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;
int t, n, a[N][8];
bool A, B;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first - a.second > b.first - b.second;
}

int32_t main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        A = 1; B = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
            A &= a[i][1] == 0 && a[i][2] == 0;
            B &= a[i][2] == 0;
        }
        if (n <= 10) {
            int tmp = 1, ans = 0, cnt[8], sum[8];
            for (int i = 1; i <= n; i++) tmp *= 3;
            for (int i = 0; i < tmp; i++) {
                cnt[0] = 0; cnt[1] = 0; cnt[2] = 0;
                sum[0] = 0; sum[1] = 0; sum[2] = 0;
                for (int j = 1; j <= n; j++) {
                    int tmpi = i;
                    for (int k = 1; k < j; k++) tmpi /= 3;
                    cnt[tmpi % 3]++;
                    sum[tmpi % 3] += a[j][tmpi % 3];
                }
                if (cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) continue;
                ans = max(ans, sum[0] + sum[1] + sum[2]);
            }
            cout << ans << "\n";
        }
        else if (A) {
            vector<int> v;
            for (int i = 1; i <= n; i++) v.push_back(a[i][0]);
            sort(v.begin(), v.end(), greater<int>());
            int ans = 0;
            for (int i = 0; i < n / 2; i++) ans += v[i];
            cout << ans << "\n";
        }
        else if (B) {
            vector<pair<int, int>> v;
            for (int i = 1; i <= n; i++) v.push_back({a[i][0], a[i][1]});
            sort(v.begin(), v.end(), cmp);
            int ans = 0;
            for (int i = 0; i < n / 2; i++) ans += v[i].first;
            for (int i = n / 2; i < n; i++) ans += v[i].second;
            cout << ans << "\n";
        }
    }
}