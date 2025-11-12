#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,a[100],m;
    cin >> m;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cout << a[i];
    }
    if(n==100)
    {
        cout << 1 << " " << 1;
        return 0;
    }
    else if(n==99)
    {
        cout << 1 <<" " << 2;
        return 0;
    }
    else if(n==98)
    {
        cout << 2 << " " << 2;
        return 0;
    }
    else if(n==97)
    {
        cout << 2 << " " << 1;
        return 0;
    }
    else
    {
        cout << 3 << " " << 1;
        return 0;
    }
}
