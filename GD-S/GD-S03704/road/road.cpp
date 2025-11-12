#include<bits/stdc++.h>
#define cin fin
#define cout fout
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!

using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
struct edge
{
    int u,v,w;
    bool operator <(const edge &x) const
    {
        return w<x.w;
    }
}e[100001];
int n,m,k;
int fa[100001];
int find(int x)
{
    return (x==fa[x]?x:x=find(fa[x]));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int u,v,w;
    int ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)
    {
        int x=find(e[i].u),y=find(e[i].v);
        if(x==y)
            continue;
        fa[find(e[i].u)]=find(e[i].v);
        fa[find(e[i].v)]=find(e[i].u);
        ans+=e[i].w;
    }
    cout<<ans;
    fin.close();
    fout.close();
    return 0;
}
