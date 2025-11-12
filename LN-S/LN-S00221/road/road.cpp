#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0;
queue<int> q;
struct vertex
{
    int iv;
    vector<int> nb,vl;
}vt[10001];
struct edge
{
    int u,v,w;
}eg[1000001];
int ic(int x,int y)
{
    q.push(x);
    vt[x].iv=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(t==y)
        {
            return 1;
            break;
        }
        for(int i=0;i<vt[t].nb.size();i++)
        {
            if(vt[vt[t].nb[i]].iv==0)
            {
                vt[vt[t].nb[i]].iv=1;
                q.push(vt[t].nb[i]);
            }
        }
    }
    while(!q.empty())
    {
        q.pop();
    }
    for(int i=0;i<n;i++)
    {
        vt[i].iv=0;
    }
    return 0;
}
int main()
{
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>eg[i].u>>eg[i].v>>eg[i].w;
    }
    for(int i=0;i<k;i++)
    {
       int x;
       cin>>x;
       for(int i=0;i<n;i++)
       {
           cin>>x;
       }
    }
    for(int i=0;i<m;i++)
    {
        if(ic(eg[i].u,eg[i].v)==0)
        {
            vt[eg[i].u].nb.push_back(eg[i].v);
            vt[eg[i].v].nb.push_back(eg[i].u);
            vt[eg[i].u].vl.push_back(eg[i].w);
            vt[eg[i].v].vl.push_back(eg[i].w);
        }
    }
    q.push(1);
    vt[1].iv=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0;i<vt[t].nb.size();i++)
        {
            if(vt[vt[t].nb[i]].iv==0)
            {
                vt[vt[t].nb[i]].iv=1;
                ans+=vt[t].vl[i];
                q.push(vt[t].nb[i]);
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
