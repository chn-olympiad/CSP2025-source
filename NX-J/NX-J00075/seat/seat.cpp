#include<bits/stdc++.h>
using namespace std;
long long n,m,j[10005],r,o,p;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    cin >> j[1];
    r = 100 - j[1];
    j[1] = r;
    for(int i = 2; i <= n*m; i++)
    {
        cin >> p;
        j[i] = 100-p;
    }
    sort(j+1,j+(n*m)+1);
    for(int i = 1; i <= n*m; i++)
    {
        if(j[i] == r)
        {
            o = i;
            break;
        }
    }
    int y;
    if(o%n == 0)
    {
        y = o/n;
        cout << y << " ";

    }
    else
    {
        y = o/n+1;
        cout << y << " ";
    }
    if(y % 2 == 1)
    {
        if(o % m == 0)cout << m;
        else cout << o%m;
    }
    else
    {
        if(m - o % m  == 0)cout << m;
        else cout << m - o % m;
    }
    return 0;
}
