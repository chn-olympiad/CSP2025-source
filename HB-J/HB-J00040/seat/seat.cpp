#include <bits/stdc++.h>
using namespace std;
int n, m, s[101], R, nu, h;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> R;
    s[0] = R;
    for (int i = 1; i < n * m; i++)
    {

        cin >> s[i];
        if (s[i] > R)
        {
            nu += 1;
        }
    }
    sort(s, s + n * m);
    h = nu % n;

    if ((nu / n) % 2 == 0)
    {
        cout << (nu / n + 1) << " " << h + 1;
    }
    else
    {
        cout << (nu / n + 1) << " " << n - h;
    }

    return 0;
}