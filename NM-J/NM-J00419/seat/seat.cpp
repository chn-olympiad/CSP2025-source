#include <bits/stdc++.h>
using namespace std;
int a[105];
int x,y,l,r,sum;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>x>>y;
    for (int i=1;i<=x*y;i++)
    {
        cin>>a[i];
    }
    int maxn=a[1];
    for (int j=2;j<=x*y;j++)
    {
        if (a[j]>maxn)
        {
            sum++;
        }
    }
    l=((sum+1)/x)+1;
    if (l%2==1)
    {
        r=sum%x+1;
    }
    if (l%2==0)
    {
        r=y-(sum%y);
    }
    cout<<l<<" "<<r;
    return 0;
}
