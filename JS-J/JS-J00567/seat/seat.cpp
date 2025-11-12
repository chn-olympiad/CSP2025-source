#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,c,d,e;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    sort(a,a+m*n);
    for(int i=m*n;i>0;i--)
    {
        if(a[i]==b)
        {
            c=m*n-i;
            break;
        }
    }
    d=c/n+1;
    if(d%2==0)
    {
        if(c%n!=0)
        {
            e=(n+1)-c%n;
        }
        else
        {
            e=1;
        }
    }
    else
    {
        if(c%n!=0)
        {
            e=c%n;
        }
        else
        {
            e=n;
        }
    }
    cout<<d<<' '<<e;
    return 0;
}
