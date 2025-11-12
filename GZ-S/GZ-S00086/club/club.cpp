//GZ-S00086 吴晨瑶 贵阳市第十八中学
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int n;
        cin >> n;
        int a[i + 5],b[i + 5],c[i + 5];
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i + 5] >> b[i + 5] >> c[i + 5];
        }
        cout << a[i + 5] << b[i + 5] << c[i + 5];
    }
    return 0;
}
