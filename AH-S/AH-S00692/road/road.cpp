#include <bits/stdc++.h>
using namespace std;
long long u[1000000];
long long v[1000000];
long long w[1000000];
long long a[11][90000];
long long c[1000000];
bool d[1000][1000];
long long n,m,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(long long i=1;i<=k;i++)
    {
        cin>>c[i];
        for(long long j=1;j<=m;k++)
        {
            cin>>a[i][j];
        }
    }
    for(long long i=1;i<=m;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            if(w[i]>w[j])
            {
                long long c1=u[i];
                u[i]=u[j];
                u[i]=c1;
                c1=v[i];
                v[i]=v[j];
                v[i]=c1;
                c1=w[i];
                w[i]=w[j];
                w[i]=c1;
            }
        }
    }
    long long sum=0;
    for(long long i=1; ;i++)
    {
        d[u[i]][v[i]]=true;
        sum+=w[i];
        for(long long j=1;j<=m;j++)
        {
            if(d[u[i]][m]==true)
            {
                d[v[i]][m]=true;
            }
        }
        long long ans=true;
        for(long long j=1;j<=m;j++)
        {
            for(long long k=1;k<=m;k++)
            {
                if(!d[i][j])
                {
                    ans=false;
                    break;
                }
            }
            if(ans)
            {
                cout<<sum;
            }
        }
    }
    return 0;
}
