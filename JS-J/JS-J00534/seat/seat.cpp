#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

int a[110], r[15][15], cur = 1;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int score = a[1], num;
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == score)
        {
            num = i;
            break;
        }
    }
    if (num % n != 0)
    {
        cout << num / n + 1 << " ";
        if ((num / n + 1) % 2 == 0) cout << n - ((num - 1) % n + 1) + 1 << endl;
        else cout << (num - 1) % n + 1 << endl;
    }
    else
    {
        cout << num / n << " ";
        if ((num / n) % 2 == 1) cout << n << endl;
        else cout << 1 << endl;
    }
    return 0;
}
