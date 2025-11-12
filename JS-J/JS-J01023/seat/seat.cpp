#include <bits/stdc++.h>
using namespace std;
int score[150];
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int row, col;
    int n, m, me, place; cin >> n >> m;

    cin >> me; score[0] = me;
    for (int i = 1; i < n * m; i++) cin >> score[i];
    sort(score, score + n * m);
    for (int i = 0; i < n * m; i++) {
        if (score[i] == me) {
            place = n * m - i;
            break;
        }
    }

    (place % n) ? (col = place / n + 1) : (col = place / n);
    (col % 2) ? (row = place - n * col + n) : (row = n * col - place + 1);
    cout << col << " " << row << endl;
    return 0;
}
