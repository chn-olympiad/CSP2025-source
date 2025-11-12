//Please give me some scores
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000], b[100][100], c[100][100];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, h = 0, l = 0, cnt = 0;
    bool o = false;
    cin >> n >> m;
    for (int i = 0; i < n * m; ++i)
    {
        cin >> a[i];
    }
    int x = a[0];
    sort(a, a + n * m);
    for (int i = 0; i < m; ++i)
    {
        if (o == false)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                b[i][j] = a[cnt];
                cnt++;
            }
            o = true;
        }
        else
        {
            for (int j = 0; j < n; ++j)
            {
                b[i][j] = a[cnt];
                cnt++;
            }
            o = false;
        }
    }
    if (m % 2 == 0)
    {
        for (int i = n - 1; i >= 0; --i)
        {
            h++;
            l = 1;
            for (int j = m - 1; j >= 0; --j)
            {
                // cout << b[j][i] << " ";
                if (b[j][i] == x)
                {
                    cout << l << " " << h << "\n";
                }
                l++;
            }
            // cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            h++;
            l = 1;
            for (int j = m - 1; j >= 0; --j)
            {
                // cout << b[j][i] << " ";
                if (b[j][i] == x)
                {
                    cout << l << " " << h << "\n";
                }
                l++;
            }
            // cout << endl;
        }
    }
    return 0;
}