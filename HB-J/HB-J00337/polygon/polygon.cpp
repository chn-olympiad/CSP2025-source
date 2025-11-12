#include<bits/stdc++.h>
//Only for triangles(points 1-3)
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[5005];
    for(int j=1;j<=n;j++)
    {
        cin>>a[j];
    }
    if(a[1]>=a[2]&&a[1]>=a[3])
    {
        if(a[1]+a[2]+a[3]>a[1]*2)
        {
            cout<<1;
        }
        else cout<<0;
    }
    else if(a[2]>=a[1]&&a[2]>=a[3])
    {
        if(a[1]+a[2]+a[3]>a[2]*2)
        {
            cout<<1;
        }
        else cout<<0;
    }
    else if(a[3]>=a[2]&&a[3]>=a[1])
    {
        if(a[1]+a[2]+a[3]>a[3]*2)
        {
            cout<<1;
        }
        else cout<<0;
    }
    return 0;
}

