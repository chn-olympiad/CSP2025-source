#include <bits/stdc++.h>
using namespace std;

int go(int sum, int inx, int maxn, vector<int> p, vector<vector<long long>> a) {
    if (p[0] > maxn / 2 || p[1] > maxn / 2 || p[2] > maxn) return 0;
    if (inx == maxn) {
        return sum;
    }
    return max({
        go(sum + a[inx][0], inx + 1, maxn, {p[0] + 1, p[1], p[2]}, a), 
        go(sum + a[inx][1], inx + 1, maxn, {p[0], p[1] + 1, p[2]}, a), 
        go(sum + a[inx][2], inx + 1, maxn, {p[0], p[1], p[2] + 1}, a)
    });
}

int main() {
    #define int long long
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n <= 10) {
            vector <vector <int>> a(n, vector <int>(3));
            for (int i = 0; i < n; i++) {
                cin >> a[i][0] >> a[i][1] >> a[i][2];
            }
            cout << go(0, 0, n, {0, 0, 0}, a) << "\n";
            continue;
        }
        vector <vector <int>> a(n, vector <int>(3));
        vector <pair<int, int>> b;
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if (a[i][0] >= a[i][1] && a[i][0] > a[i][2]) {
                if (a[i][1] >= a[i][2]) b.push_back({a[i][0] - a[i][1], i});
                else b.push_back({a[i][0] - a[i][2], i});
            }
            else if (a[i][1] >= a[i][0] && a[i][1] > a[i][2]) {
                if (a[i][0] >= a[i][2]) b.push_back({a[i][1] - a[i][0], i});
                else b.push_back({a[i][1] - a[i][2], i});
            }
            else {
                if (a[i][1] >= a[i][2]) b.push_back({a[i][2] - a[i][0], i});
                else b.push_back({a[i][2] - a[i][1], i});
            }
        }
        sort(b.begin(), b.end(), greater<pair<int, int>>());
        //for (int i = 0 ; i < n; i++) cout << b[i].first << " " << b[i].second << "\n";
        int ans = 0, p[3] = {0, 0, 0};
        for (int k = 0; k < n; k++) {
            int i = b[k].second;
            int aa = 0, bb = 0;
            for (int j = 0; j < 3; j++) {
                if (a[i][j] > a[i][aa]) aa = j;
                if (a[i][j] < a[i][bb]) bb = j;
            }
            if (p[aa] < n / 2) {
                //cout << i << " " << aa << "\n";
                ans += a[i][aa];
                p[aa]++;
            }
            else {
                ans += a[i][3 - aa - bb];
                p[3 - aa - bb]++;
            }
        }
        cout << ans << "\n";
    }
}