#include <iostream>
using namespace std;

const int MAXN = 20;
int n, m; // n row m col
// output col first row second
int me, idx = 1, col, row;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> me;
    for (int i = 1; i < n * m; i ++) {
        int ai; cin >> ai;
        if (ai > me) idx ++;
    } col = (idx + n - 1) / n;
    row = (idx - 1) % n + 1;
    if ((~col) & 1) row = n - row + 1;
    cout << col << ' ' << row; return 0;
}
