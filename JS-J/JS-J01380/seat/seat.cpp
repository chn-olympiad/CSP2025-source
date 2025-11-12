#include<bits/stdc++.h>
using namespace std;

struct T {
    int index, score;
} student[105];
bool cmp(T a, T b) {
    return a.score > b.score;
}
int n, m;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n*m; i++) student[i].index=i, cin >> student[i].score;
    sort(student+1, student+n*m+1, cmp);
    for (int i=1; i<=n*m; i++) {
        if (student[i].index == 1) {
            int row = i % n, col = i / n + 1;
            if (!row) row = n, col--;
            if (col % 2) {    // go down
                cout << col << " " << row;
            } else {          // go up
                cout << col << " " << n - row + 1;
            }
            break;
        }
    }
    return 0;
}
