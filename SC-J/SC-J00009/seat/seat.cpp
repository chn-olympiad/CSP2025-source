#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >>n >>m;
    int score = 0;
    for (int i = 1; i <= n * m; i++)
    {
        cin >>a[i];
        if (i == 1) score = a[i];
    }
    sort(a + 1,a + n * m + 1,greater<int>());
    int x = 1,y = 1;
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == score)
        {
            cout <<x <<" " <<y;
            break;
        }
        if (x % 2 == 0)
        {
            if (y != 1) y--;
            else x++;
        }
        else
        {
            if (y != n) y++;
            else x++;
        }
    }
    return 0;
}
