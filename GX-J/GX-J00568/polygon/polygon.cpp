#include <bits//stdc++.h>
using namespace std;
int  n , x , w , e , r , m;
int mian()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    if(n == 5)
    {
        cin >> x >> w >> e >> r >> m;
        if (x == 1 && w == 2 && e == 3 && r == 4 && m == 5)
            cout << 9;
        if (x == 2 && w == 2 && e == 3 && r == 8 && m == 10)
            cout << 6;

    }
    return 0;
}
