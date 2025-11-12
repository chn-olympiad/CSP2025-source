#include<bits/stdc++.h>
using namespace std;
int u[10000000], v[10000000], w[10000000];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    if(k == 0)
    {
        long long sw = 0;
        for(int i = 1; i <= m; i++)
        {
            sw += w[i];
        }
        cout << sw;
        return 0;
    }
    return 0;
}
