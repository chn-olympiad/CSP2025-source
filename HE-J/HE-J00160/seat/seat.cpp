#include <bits/stdc++.h>
using namespace std;
int n, m, a[110];
int s, p;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n*m; i ++)
    {
        cin >> a[i];
    }
    s = a[1];
    sort(a+1, a+n*m+1, cmp);
    for (int i = 1; i <= n*m; i ++)
    {
        if (a[i] == s)
        {
            p = i;
            break;
        }
    }
    int l = p / n;
    if (p % n == 0)
    {
        if (l % 2)
        {
            cout << l << ' ' << m << endl;
        }
        else
        {
            cout << l << ' ' << 1 << endl;
        }
    }
    else
    {
        l ++;
        int ys = p % n;
        if (l % 2)
        {
            cout << l << ' ' << ys << endl;
        }
        else
        {
            cout << l << ' ' << n+1-ys << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
