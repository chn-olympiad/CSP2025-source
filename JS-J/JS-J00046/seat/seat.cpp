#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int t=1;
    int f=0;
    int h=1;
    int n,m,x,d;
    cin>>n>>m;
    x=n*m;
    cin>>a[1];
    for(int i=2;i<=x;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])
            t++;
    }
    while(t)
    {
        if(t>n)
        {
            if(f==0)
                f=1;
            else if(f==1)
                f=0;
            t=t-n;
            h++;
        }
        else
        {
            if(f==0)
            d=t;
            if(f==1)
                d=n-t+1;
            t=0;
        }
    }
    cout<<h<<" "<<d;
    return 0;
}
