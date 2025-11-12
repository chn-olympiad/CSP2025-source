#include<bits/stdc++.h>
using name space std;
int m,n,b[505],sum,k,ans;
string a;
int mian()
{
    freopen("employ.in","r",open)
    freopen("employ.out","w",out);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            k++;
        }
        else
        {
            if(b[i]>k)
            {
                ans++;
                k=0;
            }
        }
        if(ans>=m)
        {
            ans++;
            k=0;
            break;
        }
    }
    cout<<ans%998244353;
    return 0;
}
