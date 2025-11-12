#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    long long a[5001];
    double m=n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(a[1]+a[2]<=a[3])
        {
            cout<<0;
        }
        else
        {
            cout<<1;
        }
    }
}
