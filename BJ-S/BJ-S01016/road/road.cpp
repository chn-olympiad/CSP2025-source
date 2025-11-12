#include <iostream>
#include <algorithm>
using namespace std;
int u[1000005],v[1000005],w[1000005],c[15],a[15][1000005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int sum = 0;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i] >> u[i] >> v[i];
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        for(int j = 1;j <= m;j++)
        {
            cin >> a[i][j];
        }
    }
    sort(w,w + m + 1);
    for(int i = 1;i <= n-1;i++)
    {
        sum += w[i];
    }
    cout << sum << endl;
    return 0;
}
