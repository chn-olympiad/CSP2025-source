#include<bits/stdc++.h>
using namespace std;
int n, m, a[105][105], b[105], s, cnt, k;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n * m; i++)
    {
        cin >> b[i];
    }
    s = b[0];
    sort(b, b + n * m, cmp);
    for(int i = 0 ;i < n; i++)
    {
        if(i % 2 != 0)
        {
            for(int j = m - 1; j > 0; j--)
            {
                a[i][j] = b[cnt];
                cout << a[i][j] << " ";
                cnt++;
            }
        }
        else
        {
            for(int j = 0; j < m; j++)
            {
                a[i][j] = b[cnt];
                cout << a[i][j] << " ";
                cnt++;
            }
        }
        cout << endl;
    }
    for(int i = 0 ;i < n; i++)
    {
        if(i % 2 != 0)
        {
            for(int j = m - 1; j > 0; j--)
            {
                if(a[i][j] == s) cout << i + 1 << " " << j + 1;
            }
        }
        else
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == s) cout << i + 1 << " " << j + 1;
            }
        }
    }
    return 0;
}
