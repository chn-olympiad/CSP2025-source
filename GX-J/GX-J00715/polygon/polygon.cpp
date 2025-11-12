#include <bits/stdc++.h>
using namespace std;
int n,a[1005],ans=0;
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort (a+1,a+n+1);
    for (int i=3;i<=n;i++)
    {
        int sum = 0;
        for (int j=1;j<=i;j++)
            sum+=a[j];
        if (sum>=2*a[i])
            ans+=i-1;
    }
    cout << ans;
}
