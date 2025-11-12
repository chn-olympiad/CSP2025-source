#include <bits/stdc++.h>
using namespace std;
int cur,o,n,m;;
long long xr=0;
long long student[109];
bool cmp(long long x,long long y)
{
    return x>y;
}
void zw()
{
    for(int i=1;i<=n*m;i++)
    {
        if(student[i]==xr)
        {
            cur=i;
        }
    }
    if(cur%n==0)
    {
        o=cur/n;
        if(o%2==1)
        {
            cout<<o<<" "<<n;
        }
        else{
            cout<<o<<" "<<1;
        }
    }
    else
    {
        o=cur/n+1;
        if(o%2==1)
        {
            cout<<o<<" "<<cur%n;
        }
        else
        {
            cout<<o<<" "<<n-cur%n+1;
        }
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>student[i];
        if(i==1)
        {
            xr=student[i];
        }
    }
    sort(student+1,student+n*m+1,cmp);
    zw();
    return 0;
}
