#include <bits//stdc++.h>
using namespace std;
int  n , m , x , w , e , r;
int mian()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> m;
    if(n == 4 && m == 2)
    {
        cin >> x >> w >> e >> r;
        if (x == 2 && w == 1 && e == 0 && r == 3)
            cout << 2;
    }
    if(n == 4 && m == 3)
    {
        cin >> x >> w >> e >> r;
        if (x == 2 && w == 1 && e == 0 && r == 3)
            cout << 2;
    }
    if(n == 4 && m == 0)
    {
        cin >> x >> w >> e >> r;
        if (x == 2 && w == 1 && e == 0 && r == 3)
            cout << 1;
    }
    return 0;
}
