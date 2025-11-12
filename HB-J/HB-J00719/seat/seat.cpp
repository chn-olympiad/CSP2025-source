// seat.cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[1005];

bool cmp(int x, int y) { return x > y; }

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> a[1];
    int tot = n * m;
    int num = a[1];
    for (int i = 2; i <= tot; i++)
        cin >> a[i];

    sort(a + 1, a + tot + 1, cmp);

    for (int i = 1; i <= tot; i++) {
        if (a[i] == num) {
            // cout << i << '\n';
            int b = (i + n - 1) / n - 1;
            cout << (i + n - 1) / n << ' ';
            if (b & 1) cout << n - (i - b * n) + 1;
            else cout << i - b * n;
            break;
        }
    }

    return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

2 4
4 1 2 3 5 6 7 8

2 4
5 1 2 3 4 6 7 8

2 4
2 1 3 4 5 6 7 8
*/
