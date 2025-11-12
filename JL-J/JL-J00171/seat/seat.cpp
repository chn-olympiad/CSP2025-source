#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c,aa,ren=1,l,p;
    cin>>a>>b;
    cin>>c;
    for(int i=a*b-1;i>0;i--)
    {
        cin>>aa;
        if(aa>c)
        {
            ren++;
        }

    }
    if(ren%a==0)
    {
        cout<<ren/a<<' ';
    }
    else
    {
        cout<<ren/a+1<<' ';
    }
    bool z=true;
    for(int i=ren;i>0;i=i-b)
    {
        if(i<=b)
        {
            if(z==true)
            {
                cout<<i;
            }
            else
            {
                cout<<b-i+1;
            }
        }
        if(z==true)
        {
            z=false;
        }
        else
        {
            z=true;
        }
    }
    return 0;
}
