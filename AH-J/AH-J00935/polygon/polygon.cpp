#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {
        if(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[1]+a[2]>a[0])
        {
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    int f=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        int z=0;
        for(int i=n-2;i>=1;i--)
        {
            z+=i;
        }
        cout<<z;
        return 0;
    }
    return 0;
}
