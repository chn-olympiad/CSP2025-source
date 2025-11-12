#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,ri;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    r=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++)
    {
        if(a[i]==r)
        {
            ri=i;
            break;
        }
    }
    r=ri%n;
    ri-=ri%n;
    ri/=n;
    if(r!=0)
    {
        ri+=2;
    }
    cout<<ri<<" ";
    if(ri%2==1)
    {
        if(r==0)
        {
            cout<<n;
        }
        else
        {
            cout<<r+1;
        }
    }
    else
    {
        if(r==0)
        {
            cout<<1;
        }
        else
        {
            cout<<n-r+1;
        }
    }
    return 0;
}
