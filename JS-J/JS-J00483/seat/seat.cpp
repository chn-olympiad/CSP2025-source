#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, k, a[105];
    cin >> n >> m;
    for(int i = 0; i < n * m; i++)
    {
        cin >> a[i];
    }
    k = a[0];
    int d = 1;
    for(int i = 0; i < n * m; i++)
    {
        if(a[i] > k)
        {
            d++;
        }
    }
    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < n; j++)
            {
                cnt++;
                if(cnt == d)
                {
                    cout << (i + 1) << " " << (j + 1) << endl;
                    return 0;
                }
            }
        }
        else
        {
            for(int j = m - 1; j >= 0; j--)
            {
                cnt++;
                if(cnt == d)
                {
                    cout << (i + 1) << " " << (j + 1) << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
