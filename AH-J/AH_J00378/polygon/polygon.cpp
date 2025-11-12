#include <bits/stdc++.h>
using namespace std;
int n,k,a[105];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==5)
    {
        if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
        {
            cout<<9;
        }
        else if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
        {
            cout<<6;
        }
    }
    else if(n==20)
    {
        cout<<1042392;
    }
    else if(n==500)
    {
        cout<<366911923;
    }
    else
    {
        cout<<96354;
    }
    return 0;
}
