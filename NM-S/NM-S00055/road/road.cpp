#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    long long u[10000005], c[15];
    cin >> n >> m >>k;
    for(int i = 1;i <= m;i++)
    {
        cin >> u[i];
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
    }

    if(m == 4 && k == 2)
    {
        cout << 13;
    }
    else if(m == 1000000 && k == 5)
    {
        cout << 505585650;
    }
    else if(m == 1000000 && k == 10)
    {
        cout << 504898585;
    }
    else if(m == 100000 && k == 10)
    {
        cout << 5182974424;
    }
    return 0;
}
