#include <bits/stdc++.h>
using namespace std;
int n, m, R_score, counter, score[100], rnk[10][10];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) cin >> score[i];
    R_score = score[0];
    sort(score, score + (n * m), greater<int>());
    for (int i = 0; i < m; i++) {
        if (i % 2) {
            for (int j = n - 1; j >= 0; j--) {
                rnk[i][j] = score[counter];
                counter++;
                if (rnk[i][j] == R_score) {
                    cout << i + 1 << " " << j + 1;
                    return 0;
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                rnk[i][j] = score[counter];
                counter++;
                if (rnk[i][j] == R_score) {
                    cout << i + 1 << " " << j + 1;
                    return 0;
                }
            }
        }
    }
}
