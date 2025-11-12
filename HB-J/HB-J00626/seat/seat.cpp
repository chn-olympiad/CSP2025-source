#include <iostream>
using namespace std;
int n, m, a[12][12], b[110], k = 0, wei = 1, pos = 0, zuo = 1, x = 1, y = 1;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            k++;
            b[k] = a[i][j];
        }
    }
    for(int i = 2; i <= k; i++)
    {
        if(b[i] > b[1])
            wei++;
    }
    while(true)
    {
        if(zuo == wei)
        {
            cout << x << " " << y;
            break;
        }
        if(pos == 0)
        {
            if(y + 1 <= m)
            {
                y++;
                zuo++;
            }
            else
            {
                x++;
                zuo++;
                pos = 1;
            }
        }
        else if(pos == 1)
        {
            if(y - 1 >= 1)
            {
                y--;
                zuo++;
            }
            else
            {
                zuo++;
                x++;
                pos = 0;
            }
        }
    }
    return 0;
}
