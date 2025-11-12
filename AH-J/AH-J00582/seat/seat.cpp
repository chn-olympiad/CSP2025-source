#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[150];
    int c,r,s;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    s=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[j]>a[i])
            {
                int x=a[i];
                a[i]=a[j];
                a[j]=x;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            if(i%n==0)
            {
                c=i/n;
                if(c%2==0)
                {
                    r=1;
                }
                else r=n;
            }
            else
            {
                c=i/n+1;
                if(c%2==0)
                {
                    r=n+1-i%n;
                }
                else r=i%n;
            }

        }
    }
    cout<<c<<" "<<r;
    return 0;
}
