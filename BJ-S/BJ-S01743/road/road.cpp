#include<bits/stdc++.h>
using namespace std;
int flag[10010][10010],d[10002],d2[10002],l[10010][10010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        d[i]=1000000009;
        for(int j=1;j<=i;j++)
        {
            l[i][j]=-1;
            l[j][i]=-1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        l[a][b]=c;
        l[b][a]=c;
    }
    long long z=0;
    for(int i=1;i<=n;i++)
    {
        int fl;
        for(int j=1;j<=i;j++)
        {
            if(l[i][j]!=-1 && l[i][j]<d[i] && flag[i][j]==0)
            {
                d[i]==l[i][j];
                fl=j;
            }
        }
        flag[i][fl]++;
        flag[fl][i]++;
        z+=d[i];
    }
    while(k--)
    {
        int c,z2=z;
        cin>>c;
        for(int j=1;j<=n;j++)
        {
            cin>>d2[j];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(l[i][j]!=-1&&l[i][j]>d2[i]+d2[j])
                {
                    if(l[i][j]==d[i])
                    {
                        z2=z2-d[i]+d2[i]+d2[j];
                    }
                }
            }
        }
        z2+=c;
        if(z2<z)
        {
            z=z2;
        }
    }
    cout<<z;
    return 0;
}
