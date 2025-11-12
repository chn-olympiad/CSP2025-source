#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
int s[105] ;
int a[15][15] ;
int main()
{
    freopen("seat.in", "r", stdin) ;
    freopen("seat.out", "w", stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int m , n ;
    cin >> n >> m ;
    int k = n * m ;
    for(int i = 1 ; i <= k ; i ++)
        cin >> s[i] ;
    int xiaor = s[1] ;
    sort(s+1 , s+1+k) ;

    for(int j = 1 ; j <= m ; j ++)
    {
        for(int i = 1 ; i <= n ; i ++)
        {
            a[i][j] = s[k];
            k-- ;
        }
    }
    for(int j = 2 ; j <= m ; j += 2)
    {
        for(int i = 1 ; i <= m/2 ; i ++)
            swap(a[i][j] , a[n+1-i][j]) ;
    }

    for(int i = 1 ; i <= n ; i ++)
    {

        for(int j = 1 ; j <= m ; j ++)
        {
            if(a[i][j] == xiaor)
                cout << j << ' ' << i ;
        }
    }
    return 0 ;
}

