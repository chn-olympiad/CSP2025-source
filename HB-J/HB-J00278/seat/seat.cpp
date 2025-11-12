#include <bits/stdc++.h>
using namespace std;
int n,m,a[100],b[100],i,j,max0,a1,o=0,a2,x,y;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<m*n;i++)cin>>a[i];
    a1=a[0];
    for(i=0;i<m*n;i++)
    {
        max0=0;
        for(j=0;j<m*n;j++)
        {
            if(a[j]>max0&&a[j]!=0)
            {
            max0=a[j];
            o=j;
            }
        }
        a[o]=0;
        b[i]=max0;
        if(b[i]==a1)a2=i+1;
    }
    if(a2%m==0)y=a2/m;
    else y=a2/m+1;
    if(y%2==0)
    {
        if(a2%m==0)x=1;
        else x=n-a2%m+1;
    }
    else
    {
        if(a2%m==0)x=n;
        else x=a2%m;
    }
    cout<<y<<' '<<x;
    return 0;
}