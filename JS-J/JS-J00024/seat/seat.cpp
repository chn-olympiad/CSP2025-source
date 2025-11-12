#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];

int cmp(int x, int y) { return x > y; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int s = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int r = find(a + 1, a + n * m + 1, s) - a;
    int y = (r - 1) / m + 1;
    int x = (r - 1) % m + 1;
    if(!(y & 1)) x = n + 1 - x;
    cout << y << ' ' << x;
    return 0;
}
