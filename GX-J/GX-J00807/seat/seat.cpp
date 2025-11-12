#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],R,t,x;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    R=a[1];
    for (int i=1;i<n*m;i++)
    {
        for (int j=i+1;j<=n*m;j++)
        {
            if (a[i]<a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for (int i=1;i<=n*m;i++)
    {
        if (a[i]==R)
        {
            if(i%n==0)
            {
                x=i/n;
                cout<<i/n<<" ";
            }
            else
            {
                x=i/n+1;
                cout<<i/n+1<<" ";
            if (x%2==1)
            {
                if(i%n==0)
                {
                    cout<<n;
                }
                else
                {
                    cout<<i%n;
                }
            }
            else
            {
                if(i%n==0)
                {
                    cout<<1;
                }
                else
                {
                    cout<<n-i%n+1;
                }
            }
        }

    }
    return 0;
}
