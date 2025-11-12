#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,cnt;
int a[10001][10001]={0};
int b[11][10001]={0};
bool c[10001][10001]={false};
int main()
{
    freopen("rode.in","r",stdin);
    freopen("rode.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    for(int j=1;j<=k;j++)
    {
        for(int i=0;i<=m;i++)
        {
            cin>>b[j][i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int z=1;z<=k;z++)
            {
                cnt+=min(a[i][j],min(b[z][j],b[z][i]));
            }

        }
    }
    cout<<cnt;
    return 0;
}
