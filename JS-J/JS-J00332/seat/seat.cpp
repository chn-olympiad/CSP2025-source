#include<bits/stdc++.h>
using namespace std;
int a[101];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, score = 0;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) {
        cin >> a[i];
        if (i == 1) score = a[i];
    }
    sort(a + 1, a + n * m + 1);
    reverse(a + 1, a + n * m + 1);
    int pos = 1, mov = 1, i = 1, j = 1;
    while(i <= m && j <= n) {
        if (a[pos] == score) {
            cout << i << ' ' << j;
            return 0;
        }
        if (j == n && i % 2 == 1) {
            i++;
            pos++;
            mov = -1;
            continue;
        }
        if (j == 1 && i % 2 == 0) {
            i++;
            pos++;
            mov = 1;
            continue;
        }
        j += mov;
        pos++;
    }
    return 0;
}
