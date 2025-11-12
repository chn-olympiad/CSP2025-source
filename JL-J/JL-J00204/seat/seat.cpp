#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c[120],a1,ab,pt=0,z=0,a1w,l,h;
    cin>>a;
    cin>>b;
    ab=a*b;
    for(int i=0;i<ab;i++)
    {
        cin>>c[i];
    }
    a1=c[0];
    for(int i=0;i<ab;i++)
    {
        for(int n=0;n<ab;n++)
        {
            z=0;
            if(c[pt]<c[pt+1])
            {
                z=c[pt];
                c[pt]=c[pt+1];
                c[pt+1]=z;
            }
            pt++;
        }
        pt=0;
    }
    for(int i=0;i<ab;i++)
    {
        if(a1=c[i])
        {
            a1w=i+1;
        }
    }
    l=a1w/a;
    if(l%2==1)
    {
        h=a1w%a;
    }
    if(h==0)
    {
        l--;
        h=2;
    }
    else if(h+1==3)
    {
        l++;
        h=0;
    }
    if(h==1)
    {
        h++;
    }
    cout<<l<<" "<<h;
}
