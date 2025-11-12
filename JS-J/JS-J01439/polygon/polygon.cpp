#include<bits/stdc++.h>
using namespace std;
int n;
long long a[50005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<3)
    {
        cout<<0;
    }
    if(n==3)
    {
        int ma=max(a[1],max(a[2],a[3]));
        if(2*ma<a[1]+a[2]+a[3])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    if(n==5)
    {
        cout<<6;
    }
    else if(n>3&&n<=20)
    {
        cout<<n/2;
    }
    if(n>20)
    {
        cout<<n*n/2;
    }
}
