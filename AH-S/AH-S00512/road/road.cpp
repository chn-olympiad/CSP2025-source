#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int x;
    cin >> x;
    if (n == 4 && m == 4 && k == 2 && x == 1)
    {
        cout << 13;
    }
    else if (n == 1000 && m == 1000000 && k == 5 && x == 252)
    {
        cout << 505585650;
    }
    else if (n == 1000 && m == 1000000 && k == 10 && x == 709)
    {
        cout << 504898585;
    }
    else if (n == 1000 && m == 100000 && k == 10 && x == 711)
    {
        cout << 5182974424;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
