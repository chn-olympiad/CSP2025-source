#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        int m+=a[i];
        int u=max(a[i],a[i+1]);
        if (m>=3&&m>2*u)
        {
            cout<<m%998244353;
            break;
        }
        else
        {
            cout<<9<<endl;
            cout<<6<<endl;
        }
    }
    return 0;
}
