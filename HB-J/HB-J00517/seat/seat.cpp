#include <bits/stdc++.h>
using namespace std;
int n , m;
int a[11][11];
int b[101];
bool cmp(int c , int b)
{
    return c > b;
}
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)cin >> b[i];
    int c = b[1];
    sort(b+1 , b + n * m +1, cmp);
    int j = 0;
    for (int i = 1;i <= n * m;i++)
    {
        if(b[i] == c)
        {
            j = i;
            break;
        }

    }
    if(j <= n) cout << "1" << " " << j;
    else
    {
        if(j / n % 2 == 1)
        {
            cout << 1 + j / n << " " << n + 1 - j % n;
        }
        else
        {
            cout << 1 + j / n << " " << j % n;
        }
    }
    return 0;
}
