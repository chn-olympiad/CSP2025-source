#include<bits/stdc++.h>
using namespace std;
int v[10005];
int fa[10005],c[10005],o[10005];
int cc[15][10005];
pair<int,int>w[15][10005];
pair<int,pair<int,int> >d[2000006];
int fd(int x)
{
    return fa[x]==x?x:fa[x]=fd(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    int tot=m;
    for(int i=1;i<=m;i++)
    {
        cin>>d[i].second.first>>d[i].second.second>>d[i].first;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>v[i];
        for(int j=1;j<=n;j++)
        {
            cin>>w[i][j].first;
            w[i][j].second=j;
        }
        o[i]=1;
        // sort(w[i]+1,w[i]+1+n);
    }
    sort(d+1,d+1+m);
    long long ans=0;
    if(k==0)
    for(int i=1;i<=m;i++)
    {
        int val=d[i].first,u=d[i].second.first,t=d[i].second.second,tg=0;
        // for(int j=1;j<=k;j++)
        // {
        //     for(;o[j]<=n;o[j]++)
        //     {
        //         int v1=w[j][o[j]].second;
        //         int u1=j;
        //         if(fd(u1)==fd(v1))continue;
        //         int val2=0;
        //         if(c[j]==0)
        //         {
        //             val2=w[j][o[j]].first+v[j];
        //         }
        //         else
        //         {
        //             val2=w[j][o[j]].first;
        //         }
        //         if(val2>val)break;
        //         ans+=val2;
        //         cout<<u1<<' '<<v1<<' '<<val2<<endl;
        //         c[j]=1;
        //         fa[fd(u1)]=fd(v1);
        //     }
        // }
        if(fd(u)==fd(t))continue;
        // for(int j=1;j<=k;j++)
        // {
        //     int val2=0;
        //     if(c[j]!=1)
        //     {
        //         val2+=v[j];
        //     }
        //     if(cc[j][u]!=1)
        //     {
        //         val2+=w[j][u].first;
        //     }
        //     if(cc[j][t]!=1)
        //     {
        //         val2+=w[j][t].first;
        //     }
        //     if(val2<val)
        //     {
        //         tg=j;
        //         val=val2;
        //     }
        // }
        // cout<<u<<' '<<t<<' '<<val<<endl;
        ans+=val;
        // cc[tg][u]=1;
        // cc[tg][t]=1;
        // if(tg!=0&&c[tg]!=1)
        // {
        //     c[tg]=1;
        //     ans+=v[tg];
        // }
        fa[fd(u)]=fd(t);
    }
    cout<<ans<<'\n';
    return 0;
}
