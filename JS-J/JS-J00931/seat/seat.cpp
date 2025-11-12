#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
bool cmp(int x , int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    int n , m;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    int op = a[1];
    sort(a+1,a+n*m+1,cmp);
    int k = 1 , x = 1 , y = 1;
    while (a[k] != op)
    {
        k++;
        if (y % 2 == 1 and x == n or y % 2 == 0 and x == 1)
        {
            y++;
            continue;
        }
        if (y % 2 == 1) x++;
        else x--;
    }
    cout << y << " " << x;
    return 0;
}
