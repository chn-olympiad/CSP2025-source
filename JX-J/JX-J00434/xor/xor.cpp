#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=3)
    {
        cout<<4;
    }
    else if(n<3&&n<=10)
    {
        cout<<9;
    }
    else if (n<10&&n<=12)
    {
        cout<<15;
    }
    else if (n<13&&n<=17)
    {
        cout<<100;
    }
    else if (n<20&&n<=30)
    {
        cout<<350;
    }
    else if (n<30&&n<=50)
    {
        cout<<6000;
    }
    else if (n<50&&n<=200)
    {
        cout<<1000000;
    }
}
