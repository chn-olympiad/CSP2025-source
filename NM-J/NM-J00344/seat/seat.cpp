#include<bits/stdc++.h>
using namespace std;
int n,a,b,x[110],xb,f;
int cmp(int c,int d)
{
    return c>d;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a*b;i++)
    {
        cin>>x[i];
    }
    n=x[1];
    sort(x+1,x+a*b+1,cmp);
    for(int i=1;i<=a*b;i++)
    {
        if(x[i]==n)
        {
        xb=i;
        break;
        }
    }
    xb-=1;
    if(((xb/a)+1)%2==0)
    {
    xb+=1;
       f=xb%a+1;
       cout<<f<<" "<<a-xb%a+1;
       return 0;
    }
    else if(((xb/a)+1)%2==1)
    {
        f=xb%a+1;
        cout<<xb/a+1<<" "<<f;
        return 0;
    }

    return 0;
}
