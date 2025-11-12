#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long dp[10010]={};
long long sum=0;
struct nod{
    long long u,v,w;
}a[1001000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        //f[i]=i;
        dp[i]=1e10;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    }
    for(int i=1;i<=k;i++)
    {
        int x;
        for(int j=1;j<=n+1;j++)
        {
            cin>>x;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[a[i].v]=min(dp[i],a[i].w);
        //range(a[i].u,a[i].v);
        //cout<<a[i].u<<' '<<a[i].v<<endl;

    }
    for(int i=1;i<=n;i++)
    {
        //cout<<dp[i]<<endl;
        if(dp[i]!=1e10)
        {
            sum+=dp[i];
        }
    }
    cout<<sum;
    return 0;
}
