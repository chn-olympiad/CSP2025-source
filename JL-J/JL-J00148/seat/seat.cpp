#include<bits/stdc++.h>
using namespace std ;

int a[310] ;
int b[15][15] ;

bool cmp(int p, int q)
{
    return p > q ;
}

int main()
{
    freopen("seat.in", "r", stdin) ;
    freopen("seat.out", "w", stdout) ;

    int m, n ;
    cin >> n >> m ;
    for(int i=0; i<n*m; i++)
    {
        cin >> a[i] ;
    }
    int R = a[0] ;
    sort(a, a+m*n, cmp) ;
    int t = 0 ;
    for(int i=0; i<m; i++)
    {
        if(i % 2 != 0)
        {
            for(int j=n-1; j>=0; j--)
            {
                b[j][i] = a[t] ;
                if(b[j][i] == R)
                {
                    cout << i+1 << " " << j+1 ;
                    return 0 ;
                }
                t++ ;
            }
        }
        else
        {
            for(int j=0; j<n; j++)
            {
                b[j][i] = a[t] ;
                if(b[j][i] == R)
                {
                    cout << i+1 << " " << j+1 ;
                    return 0 ;
                }
                t++ ;
            }
        }
    }
    return 0 ;
}
