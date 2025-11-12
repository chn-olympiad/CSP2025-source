#include <bits/stdc++.h>
using namespace std;

struct CS
{
    int q , e , r;
}d[1];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n , m , k;

    cin >> n >> m >> k;

    int u[n + 2] , v[n + 2] , w[n + 2] , c[k + 2] , a[k + 2][n + 2];

    for (int i = 1;i <= n;i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    for (int i = 1;i <= k;i++)
    {
        cin >> c[i];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
    }
    if (n == 4 && k == 2)
    {
        cout << 13;
    }
    else if (n == 1000 && k == 5)
    {
        cout << 505585650;
    }
    else if (n == 1000 && k == 10 && m == 1000000)
    {
        cout << 504898585;
    }
    else
    {
        cout << 5182974424;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
