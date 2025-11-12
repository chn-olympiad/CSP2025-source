#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    if (k==0)
    {
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            if (a[i]==0)
            {
                ans++;
            }
            if (a[i]==1)
            {
                if (a[i-1]==1)
                {
                    a[i-1]=0;
                    a[i]=0;
                    ans++;
                }
            }
        }
    }
    else if (k==1)
    {
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            if (a[i]==1)
            {
                ans++;
            }
        }
    }
    else
    {
        int x;
        int point=1;
        for (int i=1;i<=n;i++)
        {
            cin >> x;
            a[i]=a[i-1]^x;
            //cout << a[i] << ' ';
            for (int j=i;j>=point;j--)
            {
                if ((a[i]^a[j-1])==k)
                {
                    //cout << i << ' ' << j << '|';
                    ans++;
                    point=i+1;
                    break;
                }
            }
        }
    }
    cout << ans;
}
