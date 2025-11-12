#include <bits/stdc++.h>
using namespace std;
int n,k,a[1005],x[1005],ans;
int sum(int mid)
{
    int s=0;
    for (int i=1;i<=n;i++)
    {
        if (i!=mid)
            s+=x[i];
    }
    return s;
}
int main()
{
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        x[i]=a[i];
    }
    sort (x+1,x+n+1);
    int l=1,r=n;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (a[mid]==sum(mid)||a[mid]==sum(mid)/2)
        {
            ans = mid;
            l++;
        }
        else
        {
            r--;
        }
    }
    bool ok = 1;
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (a[i]==a[j])
                ok=0;
        }
    }
    if (ok==1)
        cout << ans;
    else
        cout << 1;
}
