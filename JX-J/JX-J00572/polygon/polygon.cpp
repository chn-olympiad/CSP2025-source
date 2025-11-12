#include<bits/stdc++.h>
using namespace std;
long long n,a[10005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int c=0,d,e,f,g,h,m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c+=a[i];

    }
    d=2*a[1];
    e=2*a[2];
    f=2*a[3];
    g=max(d,e);
    h=max(e,f);
    m=max(g,h);
    if(n==3&&m<c)
    {

        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
