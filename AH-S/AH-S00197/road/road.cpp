#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[2000][2000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0)
    {
        for(int i=1;i<=m;i++)
        {
            int u,v,w;cin>>u>>v>>w;
            a[u][v]=w;a[v][u]=w;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(a[i][j]>a[i][k]+a[k][j])
                    {
                        a[i][j]=a[i][k];
                    }
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n-1;i++)
        {
            sum+=a[i][i+1];
        }
        cout<<sum;
    }
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
