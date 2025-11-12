#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[101];
int k,x;
int ans1,ans2;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n==1&&m==1)
    {
        cout<<1;
    }
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]<a[i+1])
        k=a[i];
        a[i]=a[i+1];
        a[i+1]=k;
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]=x)
        k=i;
        break;
    }
    if((k+n)%n==0)
    {
        ans2=n;
        ans1=k/n;
    }
    else
    {
        if(k<n)
        {
            ans2=(k+1)%n;
            ans1=1;
        }
        else
        {
            ans2=k%n;
            ans1=(k+n)/n-1;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}