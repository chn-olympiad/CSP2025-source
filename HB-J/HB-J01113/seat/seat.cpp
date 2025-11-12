#include <bits/stdc++.h>
using namespace std;
int n, m;
int pos, a, r; //pos is over R's grade
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> r;
    for (int i = 1; i <= n * m - 1; ++i)
    {
        cin >> a;
        if (a > r)
            pos++;
    }
    int c = pos / n;
    pos %= n;
    cout << c + 1 << " " << ((c + 1) % 2 == 0 ? n - pos : pos + 1);
    return 0;
}