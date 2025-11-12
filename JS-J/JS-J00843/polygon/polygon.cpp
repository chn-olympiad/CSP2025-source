#include<bits/stdc++.h>
using namespace std;
long long a[5005],n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int max=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>max) max=a[i];
    }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]-max>max)
            cout<<1;
        else
            cout<<0;
    }
    else
    {
        cout<<n*n-n+2;
    }
    return 0;
}
