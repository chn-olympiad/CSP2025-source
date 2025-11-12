#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int x, y, a = 1, b = 1, n, m, cnt = 0;
    cin >> x >> y >> n;
    while(cin >> m) if(m > n) cnt++;
    for(;cnt > 0;cnt--)
    {
        if(((b%2) && (a==x)) || (!(b%2) && (a==1))) b++;
        else if(b%2) a++;
        else a--;
    }
    cout << b << ' ' << a;
    return 0;
}
