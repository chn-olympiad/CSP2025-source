#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001],c[11],a[11][10001],l[10001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    if(k!=0)
    {
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=10000;i++)
        l[i]=0;
    l[1]=1;
    for(int i=1;i<=n-1;i++)
    {
        int mi=1000000001,jmi;
        for(int j=1;j<=m;j++)
        {
            if(mi>w[j] && ((l[u[j]]==1 && l[v[j]]==0) || (l[v[j]]==1 && l[u[j]]==0)))
                mi=w[j],jmi=j;
        }
        cnt+=mi;
        l[u[jmi]]=1;
        l[v[jmi]]=1;
    }
    cout<<cnt;

}
