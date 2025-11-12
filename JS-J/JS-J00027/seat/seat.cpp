#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],d,k;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    d=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==d)
        {
            k=i;
            break;
        }
    }
    if(k%n==0)
    {
        cout<<k/n<<" ";
        if((k/n)%2==1)
        {
            cout<<n;
        }
        else
        {
            cout<<1;
        }
    }
    else
    {
        cout<<k/n+1<<" ";
        if((k/n+1)%2==1)
        {
            cout<<k%n;
        }
        else
        {
            cout<<n-(k%n)+1;
        }
    }
    return 0;
}
