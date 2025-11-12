#include<bits/stdc++.h>
using namespace std;
struct dlxj
{
    int u , v , w ;
}dl[1000002];
bool cmp( dlxj a , dlxj b )
{
    return a.w < b.w ;
}
long long c[12] , a[12][1000002] , ans , b[10001][10001] ;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n , m , k ;
    cin >> n >> m >> k ;
    for ( int i = 1 ; i <= m ; i ++)
    {
        cin >> dl[i].u >> dl[i].v >> dl[i].w ;
    }
    sort(dl+1,dl+1+m,cmp);
    for( int i = 1 ; i <= m ; i ++)
    {
        if ( b[dl[i].u][dl[i].v] == 0 )
        {
            ans +=dl[i].w;
            b[dl[i].u][dl[i].v] = dl[i].w ;
            b[dl[i].v][dl[i].u] = dl[i].w ;
            for ( int j = 1 ; j <= n ; j ++)
            {
                if ( b[dl[i].u][j] != 0 )
                {
                    b[j][dl[i].v] = 1 ;
                    b[dl[i].v][j] = 1 ;
                }
                if ( b[dl[i].v][j] != 0 )
                {

                    b[j][dl[i].u] = 1 ;
                    b[dl[i].u][j] = 1 ;
                }
            }
        }
    }
    for( int i = 1 ; i <= k ; i ++)
    {
        cin >> c[i];
        for( int j = 1 ; j <= n ; j ++)
        {
            cin >> a[i][j] ;
        }
        for ( int j = 1 ; j < n ; j ++)
        {
            for ( int k = j+1 ; k <= n ; k ++)
            {
                if ( b[j][k] > c[i] + a[i][j] + a[i][k] )
                {
                    b[j][k] = c[i] + a[i][j] + a[i][k] ;
                    ans - b[j][k] + c[i] + a[i][j] + a[i][k] ;
                }
            }
        }
    }
    cout << ans ;
    return 0;
}
