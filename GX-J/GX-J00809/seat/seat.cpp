#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000],c=0;
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
            c=a[i];
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(i%2==0)
        {
            int b=0;
            b=n;
            for(int j=1;j<=n;j++)
            {
                if(a[i*n-(n-b)]==c)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                b--;
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i*n-(n-j)]==c)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
