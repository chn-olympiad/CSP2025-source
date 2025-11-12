#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],n,m;
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int s=a[1],wz;
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==s)
        {
            wz=n*m-i+1;
            break;
        }
    }
    int l,h;
    l=wz/n;
    if(wz%n!=0)
    {
        l++;
    }
    cout<<l<<" ";
    if(l%2==1)
    {
        if(wz%n==0)
        {
            cout<<n;
        }
        else
        {
            cout<<wz%n;
        }
    }
    else
    {
        if(wz%n==0)
        {
            cout<<1;
        }
        else
        {
            cout<<n-wz%n+1;
        }
    }
    return 0;
}

