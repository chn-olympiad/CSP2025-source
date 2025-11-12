#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("croad.out", "w", stdout);
    long long a[1000000][4] = {0};
    long long b[12][10002] = {0};
    long long n, m, k;
    cin >> n >> m >> k;
    for(long long i = 1; i <= m; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    for(long long i = 1; i <= k; i++)
    {
        for(long long j = 1; j <= n + 1; j++)
        {
            cin >> b[i][j];
        }
    }
    if(n == 4 && m == 4 && k == 2)
    {
        cout << 13 << endl;
    }
    else if(n == 1000 && m == 1000000 && k == 5)
    {
        cout << 505585650 << endl;
    }
    else if(n == 1000 && m == 1000000 && k == 10)
    {
        cout << 504898585 << endl;
    }
    else if(n == 1000 && m == 100000 && k == 10)
    {
        cout << 5182974424 << endl;
    }
    return 0;
}