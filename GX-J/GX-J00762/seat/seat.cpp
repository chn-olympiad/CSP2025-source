#include<bits/stdc++.h>
using namespace std;
long long a[105],b[15][15],c[15][15],d[15][15];
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    long long q=a[1];
    sort(a+1,a+1+n*m,cmp);
    long long o=0;
    for(long long j=1;j<=m;j++)
    {
        for(long long i=1;i<=n;i++)
        {
            o++;
            b[i][j]=a[o];
        }
    }
    o=0;
    for(long long j=1;j<=m;j++)
    {
        for(long long i=n;i>=1;i--)
        {
            o++;
            c[i][j]=a[o];
        }
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            if(j%2==0)
            {
                if(q==c[i][j])
                {
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
            else
            {
                if(q==b[i][j])
                {
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
