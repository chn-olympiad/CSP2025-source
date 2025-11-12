#include <bits/stdc++.h>
using namespace std;
int n,m,a[150],k,ans;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n>> m;
    for (int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
        if (i == 1)
        {
            k = a[i];
        }
    }
    sort(a+1,a+n*m+1);
    for (int i = 1;i <= n*m;i++)
    {
        if (a[i] == k)
        {
            k = i;
        }
    }
    k = n*m-k+1;
    if (k % n == 0)
    {
        ans = k/n;
        cout << ans << " ";
        if (ans % 2 == 1)
        {
            cout << n;
        }
        else{
            cout << 1;
        }
    }
    else
    {
        ans = k/n+1;
        cout << ans << " ";
        if (ans % 2 == 1)
        {
            cout << k%n;
        }
        else{
            cout << n-k%n+1;
        }
    }

}
