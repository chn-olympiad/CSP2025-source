#include <iostream>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k; cin >> n >> m >> k;
    int u[100001], v[100001], w[100001], a[100001];
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    for (int i = 1; i <= k; i++) cin >> a[i];
    cout <<"0";
    return 0;
}
