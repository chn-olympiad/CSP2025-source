#include<bits/stdc++.h>
using namespace std;
bool f;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    long long u[100000001],v[100000001],w[100000001];
    long long c[10000001];
    long long a[100000001][100000001];
    for(long long i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(long long i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0)
        {
            f=1;
        }
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                f=1;
            }
        }
    }
    if(f==0)
    {
        cout<<0;
    }
    else
    {
    long long mina=1000000001;
    long long suma=0;
    suma=suma+mina;
    mina=1000000001;
    for(long long i=1;i<=m;i++)
    {
        if(v[i]<mina)
        {
            mina=v[i];
        }
    }
    suma=suma+mina;
    mina=1000000001;
    for(long long i=1;i<=m;i++)
    {
        if(w[i]<mina)
        {
            mina=w[i];
        }
    }
    suma=suma+mina;
    mina=1000000001;
    for(long long i=1;i<=m;i++)
    {
        if(v[i]<mina)
        {
            mina=v[i];
        }
    }
    suma=suma+mina;
    mina=1000000001;
    for(long long i=1;i<=k;i++)
    {
        if(c[i]<mina)
        {
            mina=c[i];
        }
    }
    suma=suma+mina;
    mina=1000000001;
    for(long long i=1;i<=k;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            mina=a[i][j];
        }
    }
    suma=suma+mina;
    cout<<suma<<endl;
    }
    return 0;
}
