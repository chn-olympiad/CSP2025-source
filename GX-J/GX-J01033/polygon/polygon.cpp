#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,b=0,c=0,d=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            b+=a[j];
            if(a[j]>c)
            {
                c=a[j];
            }
            if(b>c*2)
            {
                d++;
                d=d%998244353;
                cout<<b<<" ";
            }
        }
        b=0;
        c=0;
    }
    cout<<d;
    return 0;
}
