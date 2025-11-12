#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
bool f[10005];


struct sth
{
    int pl,mon;
};
vector<sth> ve[10005];


struct lu
{
    int u,v,w;
}b[20005];

void dfs(int place,int money,int sum)
{
    if(sum>=n)
        ans=min(ans,sum);
    for(int i=0;i<ve[place].size();++i)
    {
        if(f[ve[place][i].pl]==1)
            continue;
        f[ve[place][i].pl]=1;
        dfs(ve[place][i].pl,money+ve[place][i].mon,sum+1);
        f[ve[place][i].pl]=0;
    }
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
        sth s1,s2;
        s1.pl=b[i].v;
        s2.pl=b[i].u;
        s1.mon=b[i].w;
        s2.mon=b[i].w;
        ve[b[i].u].pl.push_back(b[i].v);
        ve[b[i].v].pl.push_back(b[i].u);
        ve[b[i].v].mon.push_back(b[i].w);
        ve[b[i].u].mon.push_back(b[i].w);
    }
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<=n;++j)
        {
            int x;
            scanf("%d",&x);
        }
    }
    for(int i=0;i<n;++i)
    {
        f[i]=1;
        dfs(i,0,1);
        f[i]=0;
    }
    cout<<ans;
    return 0;
}
