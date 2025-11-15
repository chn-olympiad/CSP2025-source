#include <bits/stdc++.h>
using namespace std;

ifstream fin("club.in");
ofstream fout("club.out");

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    fin >> t;

    while (t--) {
        int n;
        fin >> n; // n is even

        vector<vector<int>> a(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                fin >> a[i][j];
            }
        }

        int ans = 0;

        // cnt[i] = no. of members club i has
        vector<int> cnt(3, 0);

        // penalty[i] = penalty for a person to leave club i to club pair.second
        vector<vector<int>> penalty(3);

        // assume each person gets in the club which he is most satisfied with
        for (int i = 0; i < n; ++i) {
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) { // pick first
                ++cnt[0];
                penalty[0].push_back(min(a[i][0] - a[i][1], a[i][0] - a[i][2]));
                ans += a[i][0];
            } else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) { // pick second
                ++cnt[1];
                penalty[1].push_back(min(a[i][1] - a[i][0], a[i][1] - a[i][2]));
                ans += a[i][1];
            } else { // pick third
                ++cnt[2];
                penalty[2].push_back(min(a[i][2] - a[i][0], a[i][2] - a[i][1]));
                ans += a[i][2];
            }
        }

        // DEBUG
        // for (int club = 0; club < 3; ++club) {
        //     cout << "club: " << club << ' ' << "cnt: " << cnt[club] << endl;
        // }

        for (int club = 0; club < 3; ++club) {
            sort(penalty[club].begin(), penalty[club].end());
            for (int i = 0; i < cnt[club] - n / 2; ++i) {
                ans -= penalty[club][i];
            }
        }

        fout << ans << '\n';
    }
}