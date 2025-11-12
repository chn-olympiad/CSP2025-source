#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],m,sum=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        m=max(a[i],m);
    }
    sum-=m;
    if(sum>2*m)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }

    return 0;
}
