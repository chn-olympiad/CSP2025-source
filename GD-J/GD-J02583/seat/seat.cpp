#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
        cin >> a[i];
    int tmp = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= n * m; ++i)
        if (a[i] == tmp)
        {
            tmp = i;
            break;
        }
    int i = 1, j = 1, cnt = 1;
    while (cnt != tmp)
    {
        if (j & 1)
        {
            if (i == n)
                ++j;
            else
                ++i;
        }
        else
        {
            if (i == 1)
                ++j;
            else
                --i;
        }
        ++cnt;
    }
    cout << j << ' ' << i << '\n';
    return 0;
}