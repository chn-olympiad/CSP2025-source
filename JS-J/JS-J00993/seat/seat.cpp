#include <bits/stdc++.h>
using namespace std;

int a[10001];

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int k = n * m;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    int l = a[1];
    int li;
    sort(a + 1, a + k + 1, cmp);
    for (int i = 1; i <= k; i++)
    {
        if (a[i] == l)
        {
            li = i;
        }
    }
    int y = li / n;
    if (li % n != 0)
    {
        y++;
    }
    int x = li % n;
    if (x == 0)
    {
        x = n;
    }
    if (y % 2 == 0)
    {
        x = n - x + 1;
    }
    cout << y << " " << x << endl;
    return 0;
}
