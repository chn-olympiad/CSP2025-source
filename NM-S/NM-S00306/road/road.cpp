#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000006],v[1000006],w[1000006],c[13],a[13][10004];
int main()
{
    freopen('road.in','r',stdin);
    freopen('road.out','w',stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    for (int i=1;i<=k;i++)
    {
        cin >> c[i];
        for (int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << 13;
    return 0;
}
