#include <bits/stdc++.h>
using namespace std;

int n, m, X, cnt, c, r;
int a[105];
int comp(int x, int y)
{
    return x > y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    X = a[1];
    sort(a + 1, a + 1 + m * n, comp);
    for(int i = 1; i <= m * n; i++)
    {
        if(a[i] == X)
        {
            cnt = i;
            break;
        }
    }
    c = ceil(cnt * 1.0 / n);
    r = (cnt - 1) % (n * 2) + 1;
    if(r > n)
    {
        r = 2 * n - r + 1;
    }
    cout << c << ' ' << r;
    return 0;
}
