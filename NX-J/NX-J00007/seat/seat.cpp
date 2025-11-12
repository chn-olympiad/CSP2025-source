#include<bits/stdc++.h>
using namespace std;
int a[10005];
int cpp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n,m, s, s1;
    cin >> n >> m;
    for(int i = 0; i < n * m; i++)
    {
        cin >> a[i];
    }
    s = a[0];
    sort(a, a+n*m, cpp);
    for(int i = 0; i < n * m; i++)
    {
        if(a[i] == s)
        {
            s1 = i+1;
        }
    }
    cout << (s1-1)/n+1 << " ";
    if(((s1-1)/n+1)% 2 == 0)
    {
        if(s1 % n == 0)
        {
            cout << 1;
        }
        else
        {
            cout << n - s1 % n+1;
        }
    }
    else
    {
        if(s1 % n == 0)
        {
            cout << n;
        }
        else
        {
            cout << s1 % n;
        }
    }
    return 0;
}
