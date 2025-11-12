#include <bits/stdc++.h>
using namespace std;
int n, m, r;
vector<int> score;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        int a;
        cin >> a;
        score.push_back(a);
        if (i == 0) r = a;
    }
    sort(score.begin(), score.end());
    int map_[n][m];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            map_[i][j] = score[(m*n-1)-(m*j+i)];
            if (j % 2 == 1) {
                map_[i][j] = score[(m*n-1)-(m*(j+1)-i-1)];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map_[i][j] == r) cout << j + 1 << " " << i + 1;
        }
    }
    return 0;
}