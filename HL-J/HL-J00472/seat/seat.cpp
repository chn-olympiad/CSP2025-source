#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a[105];
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {

        cin>>a[i];
    }
    int x=a[1];

    sort(a+1,a+m*n+1);
    for (int i=1;i<=n*m;i++)
    {
        if (a[i]==x)
        {
            if (i%n!=0)
            {
                if ((i/n+1)%2!=0)
                {
                    cout<<m-(i/n+1)+1<<" ";
                    cout<<n-(i%n)+1<<" ";

                }
                if ((i/n+1)%2==0)
                {
                    cout<<m-(i/n+1)+1<<" ";
                    cout<<n-(n-(i%n)+1)+1<<" ";

                }
            }
            else
            {
                if ((i/n)%2!=0)
                {
                    cout<<m-(i/n)+1<<" ";
                    cout<<n-n+1<<" ";
                }
                if ((i/n)%2==0)
                {
                    cout<<m-(i/n)+1<<" ";
                    cout<<n-1+1<<" ";

                }
            }
            break;
        }

    }
    return 0;
}

