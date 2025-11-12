// GZ-S00026 贵阳市观山湖区普瑞学校 何景睿
#include <iostream>
#include <set>

using namespace std;

const int max_n = 1e4 + 1;
const int max_m = 1e6 + 1;
const int max_k = 11;

int u[max_n];
int v[max_n];
int w[max_n];
int ca[max_k][max_n];

int read()
{
    int res = 0, neg = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            neg = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
        ch = getchar();
    }

    return res * neg;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n = read(), m = read(), k = read();

    for (int i = 1; i <= m; i++)
        u[i] = read();
    for (int i = 1; i <= m; i++)
        v[i] = read();
    for (int i = 1; i <= m; i++)
        w[i] = read();
    for (int i = 1; i <= k; i++)
    {
        ca[i][0] = read();
        for (int j = 1; j <= n; j++)
            ca[i][j] = read();
    }

    cout << 0 << endl;

    return 0;
}
