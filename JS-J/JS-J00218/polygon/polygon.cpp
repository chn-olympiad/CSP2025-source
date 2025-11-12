#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n,b;
    long long d=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]<a[j])
            {
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    if(a[0]<a[1]+a[2])
    {
        d++;
    }
    else{
        if(a[1]<a[0]+a[2])
        {
            d++;
        }
        else{
            if(a[2]<a[1]+a[0])
            {
                d++;
            }
        }
    }
    cout<<d;
    return 0;
}
