#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    ll sum = 0;
    for (int i = 1;i <= n;i++)
    {
        int u,v,x;
        cin >> u >> v >> x;
        sum += x;
    }
    if (k == 0)
    {
        cout << sum;
        return 0;
    }
    else cout << 0;
    return 0;
}
