#include <bits/stdc++.h>
using namespace std;
int n,m,p,s[105],x = 1,y = 1,t;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
            cin >> s[i];
    p = s[1];
    sort(s + 1,s + n * m + 1,greater<int>());
    while(s[++t] != p)
    {
        if (y % 2)
            if (x < n) x++;
            else y++;
        else if (x > 1) x--;
        else y++;
    }
    cout << y << " " << x;
    return 0;
}
