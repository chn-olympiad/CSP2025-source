#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,c,r,d;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        b=a[1];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(b==a[i])
        {
            d=i;
            break;
        }
    }
    if(d<=m)
    {
        c=1;
        r=d;
    }
    else if(d>m)
    {
        if(d%m!=0)
        {
            c=d/m+1;
            if(c%2==1)
            {
                r=d%m;
            }
            else
            {
                r=m-d%m+1;
            }
        }
        if(d%m==0)
        {
            c=d/m;
            if(c%2==1)
            {
                r=m;
            }
            else
            {
                r=1;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
