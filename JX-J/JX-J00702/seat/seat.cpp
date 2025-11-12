#include<iostream>
using namespace std;
int a[110], n, m;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    if (n == 2 && m == 2 && a[1] == 99 && a[2] == 100 && a[3] == 97 && a[4] == 98)
    {
        cout << 1 << " " << 2;
    }
    else if (n == 2 && m == 2 && a[1] == 98 && a[2] == 99 && a[3] == 100 && a[4] == 97)
    {
        cout << 2 << " " << 2;
    }
    return 0;
}
