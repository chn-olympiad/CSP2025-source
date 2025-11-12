#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    freopen("seat.in","r",stdin) ;
    freopen("seat.out","w",stdout) ;
    long long n , m , a[10086] , s[101][101] , sum=0 , ans=0 ;
    cin >> n >> m ;
    for (int i=1 ; i<=n*m ; i++)
        cin >> a[i] ;
        sum=a[1] ;
        ans=n*m ;
    sort(a+1 , a+n*m+1) ;
    for (int i=1 ; i<=n ; i++)
    {
        if (i%2!=0)
        {
            for (int j=1 ; j<=m ; j++)
            {
                if (a[ans]==sum)
                {
                    cout << i << " " << j ;
                    return 0 ;
                }
                ans-- ;
            }
        }
        else
        {
            for (int j=m ; j>=1 ; j--)
            {
                if (a[ans]==sum)
                {
                    cout << i << " " << j ;
                    return 0 ;
                }
                ans-- ;
            }
        }

    }
    return 0 ;
}
