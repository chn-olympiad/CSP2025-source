//GZ-S00201 赫章县西城区高级中学 晋宇轩
#include<bits/stdc++.h>
using namespace std;
long long n , m , k , ans;
int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);


    cin >> n >> m >> k;
    int u[m] , v[m] , w[m];
    int c[k] , a[k][n];
    for(int i = 0 ; i <= m ; i++) cin >> u[i] >> v[i] >> w[i];
    for(int i = 0 ; i <= k ; i++)
    {
        cin >> c[i] ;
        for(int j = 0 ; j <= n ; j++) cin >> a[i][j];
    }


     for(int i = 0 ; i <= n ; i++)
    {
        ans += w[i];
    }

    cout << ans;

    return 0;
}
