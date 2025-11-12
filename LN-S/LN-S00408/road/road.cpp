#include <bits/stdc++.h>

using namespace std;
int i,j,g[10011],F,t,c,d[11],e[10011],f[10011],h[11],ans=0x3f,k,m,n;
struct bian{
    int f2,cost;
}b,v;
vector<bian> a[10011];
bool operator<(bian a,bian b)
{
    return a.cost>b.cost;
}
priority_queue<bian> q;
int J()
{
    int i,an=0;
    b.f2=1;
    b.cost=0;
    q.push(b);
    while(!q.empty())
    {
        b=q.top();
        q.pop();
        if(e[b.f2])continue;
        an+=b.cost;e[b.f2]=1;
        for(i=0;i<a[b.f2].size();i++)
        {
            if(!e[a[b.f2][i].f2]&&!g[a[b.f2][i].f2])
            {
                q.push(a[b.f2][i]);
            }
        }
    }
    return an;
}
int Q(int x,int r)
{    int i,y=0;
    if(!x)
    {
        y=J();
        ans=min(ans,y+r);
        memset(e,0,sizeof(e));
        return 0;
    }

    for(i=1;i<=k;i++)
    {
        if(!h[i])
        h[i]=1;
        g[n+i]=0;
        r=r+d[i];
        Q(x-1,r);
        h[i]=0;
        g[n+i]=1;
        r=r-d[i];
    }
    return 0;
}
void S()
{
    int i;
    for(i=0;i<=k;i++)
    {
        Q(i,0);
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
    {
        cin>>F>>t>>c;
        b.f2=t;b.cost=c;
        a[F].push_back(b);
        b.f2=F;
        a[t].push_back(b);
    }
    for(i=1;i<=k;i++)
    {
        cin>>d[i];
        g[n+i]=1;
        for(j=1;j<=n;j++)
        {
            cin>>c;
            b.f2=j;b.cost=c;
            a[i+n].push_back(b);
            b.f2=i+n;
            a[j].push_back(b);
        }
    }
    S();
    cout<<ans;
    return 0;
}
