#include <bits/stdc++.h>
#include <bits/c++config.h>
#include <bits/memoryfwd.h>
using namespace std;
int n,a[50000],m,z,s=0,x;
int main()
{
    freopen ("polygon.in"," r",stdin);
    freopen ("polygon.out"," w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    m=n;
    for(int i=1;i<=n;i++)
    {
        z=a[i];
        x=a[i];
        for(int j=1;j<=m-1;j++)
        {
            x=max(x,a[j]);
            z+=a[j];
        }
        if(z>x)
        {
            s++;

        }
    }
    cout<<(s+1);
    return 0;

}

