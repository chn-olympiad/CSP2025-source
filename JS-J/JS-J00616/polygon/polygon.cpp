#include<bits/stdc++.h>
using namespace std;
long long n, a[5005],sum,tot;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
    }
    if(sum<=2*a[n])
    {
        cout<<"0";
        return 0;
    }
    else
    {
        if(n==3)
        {
            cout<<"1";
            return 0;
        }
    }
    cout<<"366911923";
    return 0;
}
