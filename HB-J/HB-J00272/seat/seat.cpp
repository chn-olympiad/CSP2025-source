#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int s=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[j]>a[i])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            b=i;
            break;
        }
    }
    int h,l;
    if(b/n==0)
    {
        l=b/n;
        if(l%2==0)
        {
            h=1;
        }
        else
        {
            h=m;
        }
    }
    else
    {
        l=b/n+1;
        if(l%2==0)
        {
            h=n-(b-(l-1)*n)+1;
        }
        else
        {
            h=b-(l-1)*n;
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
