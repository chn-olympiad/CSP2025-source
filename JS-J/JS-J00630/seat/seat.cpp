#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}
int st[12][12];
int a[144];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int x = n * m;
    for(int i = 1; i <= x; i++)
    {
        cin >> a[i];
    }
    int tmp = a[1];
    sort(a + 1, a + x + 1, cmp);
    int t = 1, cnt = 1;
    for(int j = 1; j <= m; j++)
    {
        if(j % 2 == 1)
        {
            for(int i = t; i <= t + n - 1; i++)
            {
                st[cnt][j] = a[i];
                cnt++;
            }
            t = t + n;
        }

        else
        {
            for(int i = t + n - 1; i >= t; i--)
            {
                st[cnt][j] = a[i];
                cnt++;
            }
            t = t + n;
        }
        cnt = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            //cout << seat[i][j] << " ";
            if(st[i][j] == tmp) cout << j << " " << i;
        }
        //cout <<endl;
    }
    return 0;
}
