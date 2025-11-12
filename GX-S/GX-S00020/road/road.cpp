#include <bits/stdc++.h>
using namespace std;

struct ED{
    int w,ud=0;
};
ED a[1011][1011];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    memset(a,0x3f,sizeof(a));
    int n,m,cj,c;
    cin>>n>>m>>cj;
    int fm,dao,jz;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&fm,&dao,&jz);
        a[fm][dao].w=jz;a[fm][dao].ud=0;
        a[dao][fm].w=jz;a[dao][fm].ud=0;
    }
    for(int j=1;j<=k;j++)
    {
        cin>c;
        for(int i=1;i<=n;i++)
        {
            cin>>jz;
            a[n+j][i].w=jz;a[n+j][i].ud=0;
            a[i][n+j].w=jz;a[i][n+j].ud=0;
        }
    }

    for(int t=1;t<=n+k;t++)
    {
        a[t][t]=0;
        for(int i=1;i<=n+k;i++)
        {
            if(i==t)    continue;
            for(int j=1;j<=n+k;j++)
            {
                if(j==t || j==i)    continue;
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                a[j][i]=a[i][j];
            }
        }
    }

    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++) ans+=a[i][j];
    }
    cout<<ans<<endl;
    return 0;
}
