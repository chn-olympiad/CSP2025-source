#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[100005][4];
pair<int, int>* b[100005];

int main() {
    ios::sync_with_stdio(false);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int datacase;
    cin >> datacase;
    while (datacase --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i][1].first >> a[i][2].first >> a[i][3].first;
            a[i][1].second = 0;
            a[i][2].second = 1;
            a[i][3].second = 2;
            sort(a[i] + 1, a[i] + 3 + 1, greater<pair<int, int>>());
            a[i][0].first = a[i][1].first - a[i][2].first;
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1, [&](pair<int, int>* x, pair<int, int>* y) {
            return *x > *y;
        });
        long long ans = 0;
        int c[3] = {0, 0, 0};
        for (int i = 1; i <= n; i ++) {
            // cout << b[i][1].first << " " << b[i][1].second << " | " << b[i][2].first << " " << b[i][2].second << endl;
            if (c[b[i][1].second] >= n / 2) {
                ans += b[i][2].first;
                c[b[i][2].second] ++;
            }
            else {
                ans += b[i][1].first;
                c[b[i][1].second] ++;
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}