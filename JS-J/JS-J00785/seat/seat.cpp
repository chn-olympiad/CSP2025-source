#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
        cin >> a[i];
    int score = a[1], seat;
    sort(a + 1, a + n * m + 1);
    for(int i = 1; i <= n * m; i++)
        if(a[i] == score) {
            seat = n * m - i + 1;
            break;
        }
    cout << seat << endl;
    int c, r;
    c = seat / n;
    r = seat % n;
    if(r == 0) r = n;
    if(c * n != seat) c += 1;
    if(c % 2 == 0) r = n - r + 1;
    cout << c << ' ' << r << endl;
    return 0;
}
