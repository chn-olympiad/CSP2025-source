#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if (k==1)
    {
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]==1)
            {
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    if (k==0)
    {
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]==0)
            {
                ans++;
            }
        }
        for (int i=1;i<=n;i++)
        {
            if (a[i]==1 && a[i+1]==1)
            {
                ans++;
                i++;
            }
        }
        cout << ans;
        return 0;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==k)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
