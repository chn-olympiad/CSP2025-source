#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans,q[5005],sum;
int main()
{
    freopen('polygon.in','r',stdin);
    freopen('polygon.out','w',stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        q[i]=q[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for (int j=3;j<=n;j++)
    {
        if (a[1]+a[2]>=a[j])
        {
            ans+=1<<n-1;
            if (a[1]+a[2]==a[j])
            {
                ans--;
            }
            if (ans>=998244353)
            {
                ans%=998244353;
            }
            continue;
        }
        if (q[j-1]<=a[j])
        {
            continue;
        }
        for (int i=1;i<=1<<(j-1)-1;i++)
        {
            sum=0;
            for (int k=j-2;k>=0;k--)
            {
                if (i&1<<k==1)
                {
                    sum+=a[k];
                }
            }
            if (sum>a[j])
            {
                ans+=sum;
                if (ans>=998244353)
                {
                    ans%=998244353;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
