#include<bits/stdc++.h>
using namespace std;
long long a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,k=0;
    cin>>n>>m;
    for(long long i=1; i<=n*m; i++)
    {
        cin>>a[i];
        k=a[1];
    }
    sort(a,a+n*m);
    for(long long i=1; i<=n; i++)
    {
        if(i%2!=0)
        {
            for(long long j=1; j<=m; j++)
            {
                if(a[i*j]==k)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for(long long j=m; j>=1; j--)
            {
                if(a[i*j]==k)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
