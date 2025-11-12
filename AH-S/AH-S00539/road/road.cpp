#include<bits/stdc++.h>
using namespace std;
const long long inf=1145141919810;
long long n,m,kk,a[10005][10005],v[10005],ans;
int main(void){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&kk);
    for(int i=1;i<=m;i++)
    {
        long long u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        a[u][v]=w;a[v][u]=w;
    }
    v[1]=1;
    for(int i=1;i<n;i++)
    {
        long long minu=inf,minv=inf,minw=inf;
        for(int j=1;j<=n;j++)
        {
            if(v[j]==1)
            {
                for(int k=1;k<=n;k++)
                {
                    if(a[j][k]!=0 && !v[k])
                    {
                        if(minw>a[j][k])
                        {
                            minw=a[j][k];
                            minu=j;
                            minv=k;
                        }
                    }
                }
            }
        }
        v[minv]=1;
        ans+=minw;
    }
    printf("%lld",ans);
    return 0;
}
