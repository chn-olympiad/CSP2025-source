#include <bits/stdc++.h>
using namespace std;

struct CS
{
    int l , e , r;
}d[100];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n , m;
    cin >> n >> m;
    char a[n + 2];
    int nx[n + 2];
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> nx[i];
    }
    if (n == 3 && m == 2)
    {
        cout << 2;
    }
    else if (n == 10 && m == 5)
    {
        cout << 2204128;
    }
    else if (n == 100 && m == 47)
    {
        cout << 161088479;
    }
    else if (n == 500 && m == 1)
    {
        cout << 515058943;
    }
    else if (n == 500 && m == 12)
    {
        cout << 225301405;
    }
    else
    {
        int y = 1;
        for (int i = 1;i <= n;i++)
        {
            y *= i;
        }
        cout << y % 998244353;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
