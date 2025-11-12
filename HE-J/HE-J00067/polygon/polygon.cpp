#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    if(n==3)
    {
        int x,y,z,t=0;
        cin >> x >> y >> z;
        t=max(t,x);
        t=max(t,y);
        t=max(t,z);
        if(x+y+z>t*2)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    return 0;
}
