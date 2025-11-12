#include<bits/stdc++.h>
using namespace std;
int a[1000001],c[1000001],b[1000001];
int f[10001][10001];
int n,m,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
            if(f[a[i]][b[i]]==0)
            {
                f[a[i]][b[i]]=c[i];
                for(int j=1;j<=n;j++)
                {
                    if(f[b[i]][j]!=0)
                    {
                        f[a[i]][j]=c[i]+f[b[i]][j];
                    }
                }
            }
            else{
                f[a[i]][b[i]]=min(f[a[i]][b[i]],c[i]);
            }
    }
    cout<<f[1][n];
    return 0;

}