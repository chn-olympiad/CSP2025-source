#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,sum=0;
    cin>>m>>n;
    for(int i=0;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]>=a[0])
        {
            sum++;

        }
    }
    if(sum<n)
    {
        cout<<1<<" "<<sum+1;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        if(sum>=i*n&&sum<(i+1)*n)
        {
            if(i%2==0)
            {
                cout<<i+1<<" "<<i*n-sum+1;
            }
            else
            {
                cout<<i+1<<" "<<n-(i*n-sum)-1;
            }

        }
    }

    return 0;
}

