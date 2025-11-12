#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, ans = 0, x;
    cin>>n>>m;
    for(int i = 0;i < n * m;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i < n * m;i++)
    {
        if(a[i] > a[0])
        {
            ans++;
        }
    }
    ans++;
    if(ans % n == 0)
    {
        x = ans / n;
        if(x % 2 == 0)
        {
            cout<<x<<" "<<1;
        }
        else
        {
            cout<<x<<" "<<n;
        }
    }
    else
    {
        x = ans / n + 1;
        if(x % 2 == 0)
        {
            cout<<x<<" "<< n -ans % n + 1;
        }
        else
        {
            cout<<x<<" "<<ans % n;
        }
    }
    return 0;
}
