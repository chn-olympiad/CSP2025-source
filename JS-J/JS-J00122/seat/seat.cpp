#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N * N];
int b[N][N];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, R;
    int dir = 1;

    cin >> n >> m;

    for (int i = 1; i <= n * m; ++i)
    {
        cin >> a[i];
    }

    R = a[1];

    sort(a + 1, a + n * m + 1, greater<int>());

    int c = 1, r = 1;
    for (int i = 1; i <= n * m; ++i)
    {
        if (a[i] == R)
        {
            cout << c << " " << r << "\n";
            return 0;
        }
        r += dir;
        if (dir == 1 && r == n + 1)
        {
            r = n;
            ++c;
            dir = -1;
        }
        else if (dir == -1 && r == 0)
        {
            r = 1;
            ++c;
            dir = 1;
        }
    }


    return 0;
}