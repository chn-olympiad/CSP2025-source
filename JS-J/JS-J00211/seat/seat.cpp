#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n = 0;
int m = 0;
int a[105] = {};
int id = 0;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
//    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
        cin >> a[i];
    id = a[1];
    sort(a + 1, a + 1 + n * m, cmp);
    for (int i = 1; i <= n * m; ++i) {
        if (a[i] == id) {
            id = i;
            break;
        }
    }
    int c = id % n;
    int r = (id - c) / n + 1;
    if (c == 0)
        c = n;
    if (r % 2 == 0)
        c = n + 1 - c;
    cout << r << " " << c;
    return 0;
}
