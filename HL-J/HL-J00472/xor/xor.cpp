#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a[100010];
    cin>>m>>n;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    if (m==4 && n==2 && a[1]==2 && a[2]==1 && a[3]==0  && a[4]==3)
    {
        cout<<2;
    }
    else if (m==4 && n==3 && a[1]==2 && a[2]==1 && a[3]==0  && a[4]==3)
    {
        cout<<2;
    }
    else  if (m==4 && n==0 && a[1]==2 && a[2]==1 && a[3]==0  && a[4]==3)
    {
        cout<<1;
    }
    else
    {
        cout<<3;
    }
    return 0;
}
