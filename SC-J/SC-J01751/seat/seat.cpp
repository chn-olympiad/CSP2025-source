#include <bits/stdc++.h>
using namespace std;
int n, m;
int p, k;
int x, y;
int a[105];
bool cmp(int l, int r) { return l > r; }
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; ++i) cin >> a[i];
    p = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; ++i) if(a[i] == p) k = i;
    x = (k + n - 1) / n, y = k % m;
    if(y == 0) y = m;
    if(x % 2 == 0) y = m - y + 1;
    cout << x << ' ' << y << '\n';
    return 0;
}
