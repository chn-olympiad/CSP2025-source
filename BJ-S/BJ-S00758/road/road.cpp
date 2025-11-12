#include <bits/stdc++.h>
using namespace std ;
int main()
{
    freopen("road.in" , "r" , stdin) ;
    freopen("road.out" , "w" , stdout) ;
    int n , m , k , sum = 0 , p;
    cin >> n >> m >> k ;
    for(int i = 1 ; i <= m ; i ++)
    {
        int u , v , w ;
        cin >> u >> v >> w;
        sum += w;
        // edge[u].push_back({v , w}) ;
        // edge[v].push_back({u , w}) ;
    }
    for(int i = 1 ; i <= k ; i ++)
    {
        for(int j = 1 ; j <= n + 1; j ++)
            cin >> p ;
    }
    cout << sum << endl;
    return 0 ;
}