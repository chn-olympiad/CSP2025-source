#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x, t, score, c, r, R;
vector<int> seat, calc;

bool cmp(int a, int b) {
    return a >= b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    x = n * 2;
    t = n * m;
    for (int i = 1; i <= n; i++) calc.push_back(i);
    for (int i = n; i >= 1; i--) calc.push_back(i);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &score);
        if (i == 1) R = score;
        seat.push_back({score});
    }
    sort(seat.begin(), seat.end(), cmp);
    for (int i = 0; i < seat.size(); i++)
        if (seat[i] == R) {
            c = i / n + 1;
            r = calc[i % x];
            break;
        }
    printf("%d %d", c, r);
    return 0;
}
