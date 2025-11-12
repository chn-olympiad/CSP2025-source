#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1005];
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1);
    int l=1,r=n*m,mid=(l+n)/2;
    while (l<=n)
    {
        if (a[mid]>a[mid-1]&&a[mid]<a[mid+1])
        {
            cout<<mid/(n+1)+1<<" "<<mid%n;
            break;
        }
        if (a[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
        mid=(l+n)/2;
    }
    return 0;
}
