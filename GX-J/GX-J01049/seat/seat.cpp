#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1000],l=0,k=0,p=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    l=a[1];
    for(int i=1;i<=n*m-1;i++)
    {
        for(int j=1;j<=n*m-1;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }

    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==l)
        {
            k=i;
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(k%n!=0)
        {
            p=k/n+1;
        }
        else if(k%n==0)
        {
            p=k/n;
        }
        if(p%2==0)
        {
            k-=n*(k/n);
            if(k==0)
            {
                cout<<p<<" "<<1;
                return 0;
            }
            if(k==3)
            {
                cout<<p<<" "<<2;
                return 0;
            }
            if(k==2)
            {
                cout<<p<<" "<<3;
                return 0;
            }
            if(k==1)
            {
                cout<<p<<" "<<4;
                return 0;
            }
        }
        if(p%2!=0 and k<=n)
        {
            cout<<p<<" "<<k;
            return 0;
        }
        else if(p%2!=0 and k>n)
        {
            cout<<p<<" "<<k-(k/n)*n;
            return 0;
        }
    }
    return 0;
}
