#include<bits/stdc++.h>
using namespace std;
struct bian
{
    int u,v,w;
};
vector <bian>b;
int c[20];
int x[11][11000],fa[11000];
int now[20];
int n,m,k;
long long ans=1e12;
int find(int x)
{
    if (fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void run()
{
    for (int i=1;i<=n+k;i++)fa[i]=i;
    long long sum=0;
    int fuc=n;
    for (int i=1;i<=k;i++)
    {
        if (now[i])sum+=c[i],fuc++;
    }
    int cnt=1;
    for (bian i:b)
    {
        if (i.u>n)
        {
            if (!now[i.u-n])continue;
        }
        if (i.v>n)if (!now[i.v-n])continue;
        int fu=find(i.u),fv=find(i.v);
        if (fu==fv)continue;
        cnt++;
        fa[fv]=fu;
        sum+=i.w;
        if (cnt==fuc)break;
    }
    ans=min(sum,ans);
}
void dfs(int step)
{
    if (step>=k)
    {
        run();
        return;
    }
    for (int i=0;i<=1;i++)
    {
        now[step+1]=i;
        dfs(step+1);
    }
}
bool cmp(bian x,bian y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        b.push_back({u,v,w});
    }
    for (int i=1;i<=k;i++)
    {
        cin >> c[i];
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&x[i][j]);
        }
        for (int j=1;j<=n;j++)
        {
            b.push_back({j,i+n,x[i][j]});
        }
    }
    sort(b.begin(),b.end(),cmp);
    dfs(0);
    cout << ans <<"\n";
    return 0;
}
