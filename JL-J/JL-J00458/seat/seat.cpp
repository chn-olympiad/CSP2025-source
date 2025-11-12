#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,k[1000],l,c,h,al;
    cin>>a>>b;
    int x=a*b;
    for(int i=1;i<=x;i++)
    {
       cin>>k[i];
    }
    al=k[1];
    sort(k+1,k+x+1);
    reverse(k+1,k+x+1);
    for(int i=1;i<=x;i++)
    {
        if(k[i]=al)
        {
            al=i;
            break;
        }
    }
    if(a==1) l=1;
    if(b==0) h=1;
    if(al/a!=1.0*al/a)
    {
        h=al/a+1;
    }
    else
    {
        h=al/a;
    }
    if(h%2!=0)
    {
        if(al%a==0)
        {
            l=a;
        }
        else
        {
            l=al%a;
        }
    }
    else
    {
        l=a-(a%a)+1;
    }
    cout<<h<<" "<<l;
    return 0;
}
