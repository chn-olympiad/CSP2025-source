#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--)
    {
        int n,a[200001],b[200001],c[200001];
        long long sum = 0;
        cin >> n;
        for (int i = 1;i <= n;i++)
            cin >> a[i] >> b[i] >> c[i];
        sort(a + 1,a + n + 1);
        for (int i = n / 2 + 1;i <= n;i++)
            sum += a[i];
        cout << sum;
    }
    return 0;
}
