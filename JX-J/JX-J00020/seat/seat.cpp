#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],ans = 0;
    cin >> n >> m;
    int num = n*m;
    for(int i = 1;i <= num;i++)
    {
        cin >> a[i];
    }
    int xiaor = a[1];
    sort(a+1,a+num+1);
    reverse(a+1,a+num+1);
    for(int i = 1;i <= num;i++)
    {
        if(a[i] == xiaor)
        {
            ans = i;
            break;
        }
    }
    if(ans%(2*n) == 0)
    {
        cout << ans/n << ' ' << 1;
    }
    else
    {
        if(ans%(2*n) < n)
        {
            cout << ans/n+1 << ' ' << ans%n;
        }
        else if(ans % n == 0)
        {
            cout << ans/n << ' ' << n;
        }
        else
        {
            cout << ans/n+1 << ' ' << n-(ans%n)+1;
        }
    }
    return 0;
}
