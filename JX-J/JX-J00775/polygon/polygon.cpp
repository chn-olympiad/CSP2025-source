#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cup=0,s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i+1]>a[i])
        {
            cup=a[i];
            a[i]=a[i+1];
            a[i+1]=cup;
        }
    }
    max=a[1];
    return 0;
}