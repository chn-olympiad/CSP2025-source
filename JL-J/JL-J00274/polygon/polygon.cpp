#include <bits/stdc++.h>
using namespace std;
int n,a[5006];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(n<=3)
        {
            if(n<=2)
            {
                cout<<0;
                break;
            }
            else
            {
                if(a[i]+a[i+1]>a[i+2] &&a[i]-a[i+1]<a[i+2])
                {
                    cout<<1;
                    break;
                }
                else
                {
                    cout<<0;
                    break;
                }
            }
        }
    }
    return 0;
}
