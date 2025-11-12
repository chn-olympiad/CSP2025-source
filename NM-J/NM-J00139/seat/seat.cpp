#include <iostream>
using namespace std ;
int main()
{
    //freopen("seat.in" , "r" , "std.in") ;
    //freopen("seat.out" , "w" , "std.out") ;
    int m , n , a[100];
    cin >> n >> m ;
    for (int i = 1 ; i <= n*m ; i++)
    {
        cin >> a[i] ;
    }
    int c = a[1] ;
    for (int i = 1 ; i <= n*m ; i++)
    {
        for (int j = i ; j <= n*m-1 ; j++)
        {
            if (a[j] < a[j+1])
            {
                int b = a[j] ;
                a[j] = a[j+1] ;
                a[j+1] = b ;
            }
        }
    }
    for (int d = 1 ; d <= m*n ; d++)
    {
        for (int i = 1 ; i <= m; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                if(a[d] == c)
                {
                    cout << m << n ;
                    break;
                }
            }
        }
    }
    return 0 ;
}
