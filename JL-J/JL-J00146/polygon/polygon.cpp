#include<bits/stdc++.h>
using namespace std;
int n,a[5005]={0},s;
int cmp(int x,int y)
{
    return y<x;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int k=1;k<=n;k++)
    for(int i=k+1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
        if(a[i]>a[k])
        {
            s++;
        }
        else if(a[i]+a[i+1]>a[k])
        {
            s++;
        }
        else if(a[i]+a[i+1]+a[i+2]>a[k])
        {
            s++;
        }
        else if(a[i]+a[i+1]+a[i+2]+a[i+3]>a[k])
        {
            s++;
        }
    }
    cout<<s;
    return 0;
}
