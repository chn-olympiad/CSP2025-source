#include <bits/stdc++.h>
using namespace std;

int n, m, s, idx;
int scores[111];

bool compare(int a, int b) {
    return (a > b);
}

int main () {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> scores[i];
    }
    s = scores[1];
    sort(scores + 1, scores + 1 + n * m, compare);
    for (int i = 1; i <= n * m; i++) {
        if (scores[i] == s) {
            idx = i;
            break;
        }
    }

    int temp = ((idx - 1) / n % 2 == 1? n - (idx % n == 0? n: idx % n) + 1: idx);
    cout << ((idx - 1) / m + 1) << ' ' << (temp % n == 0? n: temp % n) << endl;

    return 0;
}
