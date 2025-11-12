#include<bits/stdc++.h>
using namespace std;
int fa[10020];
int findd(int x)
{
    if(x==fa[x])    return x;
    else   return fa[x]=findd(fa[x]);
}
struct node
{
    int u,v,w;
    bool operator < (const node&a)    const{return w>a.w;}
};
priority_queue<node> q;
struct ed
{
    int c;
    int d[10010];
}e[15];
int n,m,k;
long long ans;
void made()
{
    while(!q.empty())
    {
        int nowu=q.top().u,nowv=q.top().v,noww=q.top().w;
        q.pop();
        if(findd(fa[nowu])==findd(fa[nowv]))  continue;
        else
        {
            int father1=findd(fa[nowu]),father2=findd(fa[nowv]);
            //cout<<nowu<<" "<<father1<<" "<<nowv<<" "<<father2<<" "<<endl;
            fa[father1]=min(father1,father2);
            fa[father2]=min(father1,father2);
            ans+=noww;
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)   fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        node t;
        t.u=x;
        t.v=y;
        t.w=z;
        q.push(t);
    }
    if(k==0)
    {
        made();
    }
    else
    {
        int A=0;
        for(int i=1;i<=k;i++)
        {
            cin>>e[i].c;
            for(int j=1;j<=n;j++)
                cin>>e[i].d[j];
            if(e[i].c!=0)   A=1;
        }
        if(A==0)
        {
            for(int i=1;i<=k;i++)
            {
                for(int j=1;j<=n;j++)
                for(int u=j+1;u<=n;u++)
                {
                   node ls;
                   ls.u=j;ls.v=u;ls.w=e[i].d[j]+e[i].d[u];
                    q.push(ls);
                }
            }
            made();
        }
    }
    cout<<ans;
    return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 1 9 9

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
vector<node> last,now;
void dfs(int ans,int i)
{
    if(n==i+1)
    {
        while(!now.empty())
        {
            node t;
            t.u=now.top().
        }
    }
}*/
