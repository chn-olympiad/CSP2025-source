#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,xr,num=1,c,r;
    cin>>n>>m;
    int seat[n*m];
    cin>>seat[1];
    xr=seat[1];
    for( int i = 2; i <= n * m; i ++ ) cin >> seat[ i ];

    for( int i = 2; i <= n * m; i ++ )
        if( xr < seat[ i ] ) num ++;

    if( num <= n )
    {
        cout<< "1 " << num;
        return 0;
    }
    c = num / n + 1;
     if( c % 2 == 0 )
    	r = (n + 1) - (num % n) ;
    else
    	r = num % n;
    cout << c << " " << r;
    return 0;
}
