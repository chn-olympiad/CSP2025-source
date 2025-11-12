#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m,c,r,l=1,b[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>a[i];
        b[i]=i;
    }
    for(long long i=1;i<=n*m;i++)
    {
        for(long long j=1;j<n*m;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
        }
    }
    for(long long i=1;i<=n*m;i++)
    {

        if(b[i]==1)
        {
            l=i;
            break;
        }
    }

    if(l%m==0)
    {
        if((l/m)%2==0)
        {
            r=1;
        }
        else
        {
            r=m;
        }

    }

    else
    {
        if((l/m+1)%2==0)
        {
            r=m-l%m+1;
        }
        else
        {
            r=l%m;
        }


    }

     if(l%m==0)
    {
        c=l/m;

    }
    else
    {
        c=l/m+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
