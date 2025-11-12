#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int u[1000010];
int v[1000010];
int w[2000010];
int a[20][10010];
int b[20];
int p;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>b[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=n;i<=m+n*k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int p=1;p<=n;p++)
            {

                w[i]=a[j][p];
            }
        }
    }
    sort(w+1,w+m+n*k+1);
    for(int i=1;i<=n-1;i++)
    {
        if(b[i]>30) ans=ans+w[i];
        else ans=ans+w[i]+b[i];
    }
    cout<<ans;
    return 0;
}


