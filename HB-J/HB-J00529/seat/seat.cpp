#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,u,w,kkk;
    cin>>n>>m;
    int dd;
    dd=n*m;
    int a[dd];
    for(int i=1;i<=dd;i++)
    {
        cin>>a[i];
    }
    w=a[1];
    for(int o=1;o<=dd;o++)
    {
        for(int r=o+1;r<=dd;r++)
        {
            if(a[o]<a[r])
            {
                u=a[o];
                a[o]=a[r];
                a[r]=u;
            }
        }
    }
    for(int q=1;q<=dd;q++)
    {
        if(a[q]==w)
        {
            kkk=q;
            break;
        }
    }
    int yy,jjw,xx;
    if(kkk%n!=0)
    {
        xx=kkk/n+1;

    }
    else
    {
        xx=kkk/n;

    }
    if(xx%2==1)
    {
        if(kkk%n==0)
        {
            yy=kkk;
        }
        else
        {
            yy=kkk%n;
        }
    }
    else
    {

        yy=kkk%n+1;
    }
    cout<<xx<<" "<<yy;
    return 0;
}
