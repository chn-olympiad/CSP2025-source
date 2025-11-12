#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,gs,ans=1e17,book[200100],type[2000100],k,c[20][100100],cs[2000100],tim,book2[1000100],book3[100];
struct T
{
    int to,s,b;
};
vector<T>mp[1000010];
void dfs(int x)
{
    tim++;
    if(tim>100010)
    {
        return;
    }
    if(gs==n)
    {
        ans=min(ans,s);
        return;
    }
    for(int i=0;i<mp[x].size();i++)
    {
        T to=mp[x][i];
        if(book[to.to]==1)
        {
            continue;
        }
        if(book[to.to]==0&&type[to.to]==0)
        {
            gs++;
        }
        if(type[to.to]==1)
        {
            if(book[to.to]==0)
            {
                s+=cs[to.to];
            }
        }
        if(book2[to.b]==0)
        {
            s+=to.s;
        }
        book[to.to]++;
        book2[to.b]++;
        dfs(to.to);
        book[to.to]--;
        book2[to.b]--;
        if(type[to.to]==1)
        {
            if(book[to.to]==0)
            {
                s-=cs[to.to];
            }
        }
        if(book2[to.b]==0)
        {
            s-=to.s;
        }
        if(book[to.to]==0&&type[to.to]==0)
        {
            gs--;
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        T te;
        te.to=y;
        te.s=z;
        te.b=i;
        mp[x].push_back(te);
        te.to=x;
        te.s=z;
        mp[y].push_back(te);
    }
    for(int i=n+1;i<=k+n;i++)
    {
        cin>>cs[i];
        for(int u=1;u<=n;u++)
        {
            int t;
            cin>>t;
            int b=2000000+(i-n)*u;
            mp[i].push_back((T){u,t,b});
            mp[u].push_back((T){i,t,b});
            type[i]=1;
        }
    }
    gs=1;
    s=0;
    book[1]=1;
    dfs(1);
    cout<<ans;
}
