#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    if (n == 3)
    {
        for(int i = 1; i <= n;i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a+1,a+n+1,greater<int>());
        if(sum > 2*a[1]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else cout << 0 << endl;
    return 0;
}