#include <bits/stdc++.h>
using namespace std;
int a[50][50], b[500], n, m;
int main()
{
    freopen(seat.in, "r", stdin);
    freopen(seat.out, "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= (n * m); i++) cin >> b[i];
    for (int i = 1; i <= (n * m); i++) {
        int w;
        for (int j = 1; j <= (n * m); j++)
            if (b[j] > b[j - 1]) w = j;
        if ((i / n) + 1 % 2 == 0) {
            a[(i / n) + 1][n - (i % n)] = b[w];
            b[w] = 0;
            if (w = 1) {
                cout <<  (i / n) + 1 << " " << n - (i % n);
                break;
            }
        }
        else {
            a[(i / n) + 1][i % n] = b[w];
            b[w] = 0;
            if (w = 1) {
                cout <<  (i / n) + 1 << " " << i % n;
                break;
            }
        }
    }
    return 0;
}
