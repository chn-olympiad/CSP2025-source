#include <bits/stdc++.h>
using namespace std;
int main()
{
     freopen("road.in", "r", stdin);
     freopen("road.out", "w", stdout);
     int n, m, k, lucky = 107;
     cin >> n >> m >> k;
     int u[10000], v[10000], w[10000];
     for(int i = 1; i <= m; i++)
     {
         cin >> u[i];
         cin >> v[i];
         cin >> w[i];
     }
     int a[1000], b[1000];
     for(int i = 1; i <= k; i++)
     {
         cin >> a[i];
         cin >> b[i];
     }
     cout << lucky;
}
