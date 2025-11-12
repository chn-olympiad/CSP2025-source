#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
pair<int, int> a[N];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n * m; i++)
        scanf("%d", &a[i].first), a[i].second = i;
    sort(a, a + n * m, [&](std::pair<int, int> &A, std::pair<int, int> &B) {
        return A.first > B.first;
    });
    int row = 1, col = 1;
    for (int i = 0; i < n * m; i++) {
        if (a[i].second == 0) {
            printf("%d %d\n", col, row);
            return 0;
        }
        if (col & 1) ++row;
        else --row;
        if (row == n + 1) {
            row = n, col++;
        } else if (row == 0) {
            row = 1, ++col;
        }
    }
}
/*
1 % 4 == 1
1 + 1 = 2;

6 % 4 == 2
if (row & 1) column = id % n + 1;
else column = n - (id % n) + 1;
9 % 4 == 1 + 1 = 2
*/