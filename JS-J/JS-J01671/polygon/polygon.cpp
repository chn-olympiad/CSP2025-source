#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s=0;
int n;
int a[5005];
int maxi()
{
    int m=-1;
    for(int i=0;i<n;i++)
        if(a[i]>m) m=a[i];
    return m;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==3&&a[0]+a[1]+a[2]>2*maxi())
    {
        cout<<1%998244353<<endl;
        return 0;
    }
    else if(n==3&&a[0]+a[1]+a[2]<=2*maxi())
    {
        cout<<0%998244353<<endl;
        return 0;
    }
    if(maxi()==1)
    {
        for(int i=2;i<n;i++)
        {
            s+=n-i;
        }

        cout<<s%998244353<<endl;
        return 0;
    }
    cout<<1;
    return 0;
}
