#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,a[x*y],cj,pm=1,c,r;
    cin>>x>>y;
    for(int i=1;i=x*y;i++)
    {
        cin>>a[i];
    }
    cj=a[1];
    sort(a+1,a+x*y+1);
    for(int i=1;i<=x*y;i++)
    {
        if(a[i]==cj)
        {
            break;
        }else
        {
            pm+=1;
        }
    }
    if(pm%x==0)
    {
        c=pm%x;
    }else
    {
        c=pm%x+1;
    }
    if(c%2==1)
    {
       r=pm%x;
       if(r==0)
       {
           r=x;
       }
    }else
    {
        r=x-pm%x;
    }
    cout<<c<<" "<<r;
    return 0;
}
