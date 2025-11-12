#include <bits/stdc++.h>
using namespace std;

int a[100005];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int s = a[1];
    int cur;
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++)
    {
        if (s == a[i]) cur = i;
    }
    if ((cur - 1) / m % 2 == 0)
    {
        cout << (cur - 1) / m + 1 << " ";
        if (cur % m) cout << cur % m;
        else cout << m;
    }
    else
    {
        cout <<  (cur - 1) / m + 1 << " ";
        cout << m - cur % m + 1;
    }
    return 0;
}
