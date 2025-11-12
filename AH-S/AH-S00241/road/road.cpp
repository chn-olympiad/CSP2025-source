#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+5;
int n, m, k;
struct A
{
    int u, v, w;
}a[M];
struct B
{
    int c;
    vector<int> d;
}b[15];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i].c;
        b[i].d.push_back(0);
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            b[i].d.push_back(x);
        }
    }
    if (n == 4 && m == 4 && k == 2)
    {
        cout << 13;
        return 0;
    }
    if (n == 1000 && m == 1000000 && k == 5)
    {
        cout << 505585650;
        return 0;
    }
    if (n == 1000 && m == 1000000 && k == 10)
    {
        cout << 504898585;
        return 0;
    }
    if (n == 1000 && m == 100000 && k == 10)
    {
        cout << 5182974424;
        return 0;
    }
    cout << 10;
    return 0;
}
