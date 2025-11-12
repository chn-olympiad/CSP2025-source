#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int s[105];
bool cmp (int a, int b)
{
    return a > b;
}
int main()
{
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
    {
        cin >> s[i];
    }
    r = s[0];
    sort (s, s + n * m, cmp);
    int i = 1, j = 1, w = 0;
    while (true)
    {
        //cout << i << " " << j << '\n';
        if (i > n || i < 1)
        {
            j++;
            if (j % 2 != 0)
            {
                i = 1;
            }
            else
            {
                i = n;
            }
        }
        //cout << i << " " << j << endl;
        if (s[w] == r)
        {
            //cout << s[w] << '\n';
            cout << j << " " << i << '\n';
            return 0;

        }
        w++;
        if (j % 2 != 0)
        {
            i++;
        }
        else
        {
            i--;
        }
    }
    //SHENG NI BU XU DI ER JIAN
}
