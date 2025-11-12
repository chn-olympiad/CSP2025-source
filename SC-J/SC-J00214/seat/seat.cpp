#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int f[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ts = 0;
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++)
    {
        cin >> f[i];
        if(f[i] > f[1])
            ts++;
    }
    int x = 1,y = 1;
    while(ts)
    {
        ts--;
        if(x&1)
        {
            y++;
            if(y == n+1)
                x++,y = n;
        }
        else
        {
            y--;
            if(y == 0)
                x++,y = 1;
        }
    }
    cout << x <<" " << y <<"\n";
    return 0;
}