#include <bits/stdc++.h>
using namespace std;


bool comp(int x, int y)
{
    return x < y;
}
int n, a[5005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, comp);
    for(int i = 3; i <= n; i++)
    {
        for(int j = 2; j <= i; j++)
        {

        }
    }
    cout << 1;
    return 0;
}
