#include <bits/stdc++.h>
using namespace std;
int n,a[5009],ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);

    int b = a[1]+a[2];
    if (b > a[3])
    {
        cout << ans;
    }
    else
    {

        ans++;
        cout << ans;
    }
}

