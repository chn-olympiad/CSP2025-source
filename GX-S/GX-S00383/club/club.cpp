#include<bits/stdc++.h>
using namespace std;
struct sfxh
{
    int d1 , d2 , d3 ;
}a[100002];
bool cmp( sfxh a , sfxh b )
{
    if( a.d1 !=b.d1 )
    {
        return a.d1 > b.d1 ;
    }
    return a.d2 > b.d2 ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t ;
    cin >> t ;
    for ( int zs = 1 ; zs <= t ; zs ++)
    {
        int n , z1 = 0 , z2 = 0 , z3 = 0 , ans = 0 , a1[100005] , a2[100005] , a3[100005] ;
        cin >> n ;
        for ( int i = 1 ; i <= n ; i ++)
        {
            cin >> a[i].d1 >> a[i].d2 >> a[i].d3 ;
            if ( a[i].d1 >= a[i].d2 && a[i].d1 >= a[i].d3 )
            {
                z1++;
                a1[z1] = i ;
                ans += a[i].d1 ;
            }
            else if ( a[i].d2 >= a[i].d3 && a[i].d2 >= a[i].d1 )
            {
                z2++;
                a2[z2] = i ;
                ans += a[i].d2;
            }
            else if ( a[i].d3 >= a[i].d2 && a[i].d3 >= a[i].d1 )
            {
                z3++;
                a3[z3] = i ;
                ans += a[i].d3;
            }
        }
        if ( z1 > n/2 )
        {
            for ( int j = 1 ; j <= z1-n/2 ; j ++)
            {
                int z = 0 , d ;
                for ( int i = 1 ; i <= z1 ; i ++)
                {
                    if ( ans - a[a1[i]].d1 + max( a[a1[i]].d2,a[a1[i]].d3 ) > z  && a1[i] != 0 )
                    {
                        d = i ;
                        z = ans - a[a1[i]].d1 + max( a[a1[i]].d2,a[a1[i]].d3 ) ;
                    }
                }
                ans = z ;
                a1[d] = 0 ;
            }
        }
        else if ( z2 > n/2 )
        {
            for ( int j = 1 ; j <= z2-n/2 ; j ++)
            {
                int z = 0 , d ;
                for ( int i = 1 ; i <= z2 ; i ++)
                {
                    if ( ans - a[a2[i]].d2 + max( a[a2[i]].d1,a[a2[i]].d3 ) > z && a2[i] != 0 )
                    {
                        d = i ;
                        z = ans - a[a2[i]].d2 + max( a[a2[i]].d1,a[a2[i]].d3 ) ;
                    }
                }
                ans = z ;
                a2[d] = 0 ;
            }
        }
        else if ( z3 > n/2 )
        {
            for ( int j = 1 ; j <= z3-n/2 ; j ++)
            {
                int z = 0 , d ;
                for ( int i = 1 ; i <= z3 ; i ++)
                {
                    if ( ans - a[a3[i]].d3 + max( a[a3[i]].d2,a[a3[i]].d1 ) > z  && a3[i] != 0 )
                    {
                        d = i ;
                        z = ans - a[a3[i]].d3 + max( a[a3[i]].d2,a[a3[i]].d1 ) ;
                    }
                }
                ans = z ;
                a3[d] = 0 ;
            }
        }
        cout << ans << endl ;
    }
    return 0;
}
