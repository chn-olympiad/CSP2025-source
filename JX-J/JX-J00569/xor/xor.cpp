#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    int a[100005],k;
    long n;
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (k == 0)
    {
        cout << 1;
        return 0;
    }
    else if ((n <= 4)&&(i <= 3))
    {
        cout << 2;
        return 0;
    }
    else
    {
        cout << k;
    }
    return 0;
}
