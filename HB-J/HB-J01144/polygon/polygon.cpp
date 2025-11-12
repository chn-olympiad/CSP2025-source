#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[50000];
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    int m = 0;
    for(int i = 1;i <= n;i++)
    {
        sum += a[i];
        m = max(m,a[i]);
    }
    if(sum > m*2 && n >= 3)
        cout << 1;
    return 0;
}
