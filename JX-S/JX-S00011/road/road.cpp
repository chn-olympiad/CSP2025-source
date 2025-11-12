#include<bits/stdc++.h>
using namespace std;
struct road{
    int u,v;
    int w;
};
int arr[3015][3015];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(arr,0x3f,sizeof arr);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        arr[u][v]=arr[v][u]=w;
    }
    bool b=true;
    for(int i=1;i<=k;++i)
    {
        int r;
        scanf("%d",&r);
        for(int j=1;j<=n;++j)
        {
            int h;
            scanf("%d",&h);
            if(j==1) arr[n+i][j]=arr[j][n+i]=r+h;
            else
            arr[n+i][j]=arr[j][n+i]=h;
        }
    }
    for(int s=1;s<=(n+k);++s)
    {
        for(int i=1;i<=(n+k);++i)
        {
            for(int j=1;j<=(n+k);++j)
            {
                if(arr[i][s]+arr[s][j]<arr[i][j]) arr[i][j]=arr[i][s]+arr[s][j];
            }
        }
    }
    long long ans=(long long)1e15,sum=0;
    for(int i=1;i<=(n+k);++i)
    {
        for(int j=1;j<=n;++j) sum+=arr[i][j];
        ans=min(ans,sum);
        sum=0;
    }
    printf("%lld\n",ans);
    return 0;
}
