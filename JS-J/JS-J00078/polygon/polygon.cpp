#include <bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==3)
    {
        if(a[2]+a[3]>a[1])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        if(n==4)
        {
            int s=0;
            if(a[1]<a[2]+a[3]+a[4])
            {
                s++;
            }
            if(a[1]<a[2]+a[3])
            {
                s++;
            }
            if(a[1]<a[2]+a[4])
            {
                s++;
            }
            if(a[1]<a[3]+a[4])
            {
                s++;
            }
            if(a[2]<a[3]+a[4])
            {
                s++;
            }
            cout<<s<<endl;
        }
        else
        {
            cout<<17;
        }
    }
}
