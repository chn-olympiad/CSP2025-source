#include <bits/stdc++.h>
using namespace std;
int n,v[10010],a[10010],he,d;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    for (int i=1;i<n;i++)
    {
        cin>>v[i];
        he+=v[i];
    }
    int minx=1000000;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        minx=min(a[i],minx);
    }
    if (minx==a[1])
    {
        if (double(he/d)/1!=0)
        {
            cout<<(he/d+1)*a[1];
            return 0;
        }
        cout<<(he/d)*a[1];
    }
    else
    {
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            ans+=v[i]/d*a[i];
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
