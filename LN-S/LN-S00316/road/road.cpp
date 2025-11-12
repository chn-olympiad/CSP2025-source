#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool co[10005];
long long ans=0;

struct road
{
    int u,v,w;
}r[1000005];
queue <road> q[10005];

struct city
{
    int fe;
    int w[10005];
}c[15];

bool cmp(road x,road y)
{
    return x.w<y.w;
}

void add(road x)
{
    if(!co[x.u] || !co[x.v])
    {
        ans+=x.w;
        co[x.u]=1;
        co[x.v]=1;
        q[x.u].push(x);
        q[x.v].push(x);
    }
    return ;
}

int f(int i)
{
    int a=0,b=c[i].fe;      //a->town  b->city
    int now;
    while(!q[i].empty())
    {
        now= q[i].begin().u==i ? q[i].begin().v : q[i].begin().u;
        a+=q[i].begin().w;
        b+=c[i].w[now];
        q[i].pop();
    }
    return a-b;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
    for(int i=1;i<=k;i++)
    {
        cin>>c[i].fe;
        for(int j=1;j<=n;j++)
        {
            cin>>c[i].w[j];
        }
    }
    sort(r+1,r+m+1,cmp);
    for(int i=1;i<=n-1;i++)
    {
        add(r[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int num=f(i);
        if(num>0)
            ans-=num;
    }
    cout<<ans;
    return 0;
}
