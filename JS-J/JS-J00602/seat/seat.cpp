#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,c,r,h,l;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    r=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(r==a[i])
        {
            c=i;
        }
    }
    l=(c-1)/n+1;
    if(l%2==1)
    {
        h=c-(l-1)*n;
    }
    else
    {
        h=n-(c-(l-1)*n)+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
