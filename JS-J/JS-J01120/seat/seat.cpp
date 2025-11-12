#include <bits/stdc++.h>
using namespace std;
int n, m, a[205];
bool cmp(int l, int r)
{
    return l > r;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)cin >> a[i];
    int target = a[1], pos = 0;
    sort(a+1, a+n*m+1, cmp);
    for(int i = 1;i <= n*m;i++)
        if(a[i] == target)
        {
            pos = i;
            break;
        }
    int num = 0;
    for(int col = 1;col <= m;col++)
    {
        if(col&1)
        {
            for(int row = 1;row <= n;row++)
            {
                num++;
                if(num == pos)
                {
                    cout << col << " " <<  row;
                    return 0;
                }
            }
        }
        else
        {
            for(int row = n;row >= 1;row--)
            {
                num++;
                if(num == pos)
                {
                    cout << col << " " <<  row;
                    return 0;
                }
            }
        }
    }
    return 0;
}
