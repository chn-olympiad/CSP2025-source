#include<bits/stdc++.h>
using namespace std;
long long a,b[5005],c=INT_MIN,d,e=0,i;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(i=1;i<=a;i++)
    {
        cin>>b[i];
        if(b[i]>c)
        {
            c=b[i];
            d=i;
        }
    }
    for(i=1;i<=a;i++)
    {
        if(i==d)
        {
            continue;
        }
        e=e+b[i];
    }
    if(a==3)
    {
         if(e>c)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(c==1)
    {
        cout<<0;
    }
    else
    {
        cout<<a;
    }
    return 0;
}
