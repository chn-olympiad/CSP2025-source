#include<bits/stdc++.h>
using namespace std;
int a[1000],n,m,s,h;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            s=a[i];
        }
        for(int i=1;i<=n*m;i++)
        {
            for(int j=1;j<=n*m-1;j++)
            {
                if(a[j]<a[j+1])
                {
                    int k;
                    k=a[j];
                    a[j]=a[j+1];
                    a[j+1]=k;
                }

            }
        }

    }
    for(int i=1;i<=n*m;i++)
    {

        if(a[i]==s)
        {
            h=i;
        }
    }
    if(h%n==0)
    {
        if(h/n%2==0)
        {
            cout<<h/n<<" "<< 1;
        }
        else
        {
            cout<<h/n<<" "<<n;
        }
    }
    else
    {
        if(h/n%2==0)
        {
            cout<<h/n+1<<" "<<h%n;
        }
        else
        {
            cout<<h/n+1<<" "<<n-h%n+1;
        }
    }
}
