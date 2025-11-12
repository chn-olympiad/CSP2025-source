#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num=0,wz=0;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    num=a[1];
    sort(a+1,a+n*m+1);
    int l=1,r=n*m;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]>num)
        {
            r=mid-1;
        }
        else if(a[mid]<num)
        {
            l=mid+1;
        }
        else
        {
            wz=mid;
            break;
        }
    }
    wz=n*m-wz+1;
    int y=0,x=wz/n;
    if(x*n<wz)
    {
        x++;
    }
    if(x>1)
    {
        if(x%2==1)
        {
            y=wz%n;
        }
        else
        {
            y=n-(wz%n)+1;
        }
    }
    else
    {
        y=wz;
    }
        if(x>m)
        x=m;
        if(y>n&&x%2==1)
        y=n;
        else if(y>n&&x%2==0)
        y=1;
    cout<<x<<" "<<y;
    return 0;
}
