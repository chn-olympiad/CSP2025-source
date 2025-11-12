#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int ans=1;
    for (int i=2;i<=m*n;i++)
    {
        if(a[i]>a[1])
            ans++;
    }
    int h,l;
    if (ans%n==0)
    {
        l=ans/n;
    }
    else{
        l=ans/n+1;
    }
    if(l%2==1)
    {
        if(ans%n==0)
        {
            h=n;
        }
        else{
            h=ans%n;
        }
    }
    if(l%2==0)
    {
        if(ans%n==0)
        {
            h=1;
        }
        else{
            h=n-ans%n+1;
        }
    }
    cout<<l<<' '<<h;
    return 0;
}
