#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int num=a[1],p=0;
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(a[j]<a[i])swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(num==a[i])
        {
            p=i;
        }
    }
    int l=(p-1)/n+1;
    int h=0;
    if(l%2!=0)
    {
        h=p%n;
        if(h==0)
        {
            h+=n;
        }
    }
    else
    {
        h=n-(p-1)%n;
    }
    cout<<l<<h;
    return 0;
}
