// T2 = 100pts
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+5;
int n, m;
int a[N];
bool cmp(int x, int y)
{
    return x > y;
}
signed main()
{
     freopen("seat.in", "r", stdin);
     freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++)
    {
        cin >> a[i];
    }
    int s = a[1], ans = -1;
    sort(a+1, a+n*m+1, cmp);
    for(int i = 1; i <= n*m; i++)
    {
        if(a[i] == s)
        {
            ans = i;
            break;
        }
    }
    int x = 0, y = (ans-1)/n+1;
    if(y % 2 == 0)
    {
        x = y*n-ans+1;
    }
    else
    {
        x = ans - (y-1)*n; 
    }
    cout << y << " " << x;
    return 0;
}

//T1 + T2 + T3 + T4 = 100+100+30+36 = 266pts