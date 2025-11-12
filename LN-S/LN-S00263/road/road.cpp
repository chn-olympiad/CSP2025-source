#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int n,m,k,c[N];
array<int,3> e[N];
vector<int> st[11];
vector<int> ed[1<<10];
bool cmp(int x,int y)
{return e[x][0]<e[y][0];}
int uno[N];int fd(int x)
{
    if(x==uno[x])return x;
    return uno[x]=fd(uno[x]);
}vector<int> mg(vector<int> v1,vector<int> v2)
{
    for(int t:v2)v1.push_back(t);
    sort(v1.begin(),v1.end(),cmp);
    for(int i=1;i<=n+k;i++)uno[i]=i;
    vector<int> rs;for(int t:v1)
    {
        int x=fd(e[t][1]),y=fd(e[t][2]);
        if(x^y)uno[x]=y,rs.push_back(t);
    }return rs;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    cin>>e[i][1]>>e[i][2]>>e[i][0];
    vector<int> bl,al;
    for(int i=1;i<=m;i++)
    al.push_back(i);ed[0]=mg(al,bl);
    for(int u=n+1;u<=n+k;u++)
    {
        cin>>c[u-n];
        for(int v=1,w;v<=n;v++)
        {
            cin>>w;e[++m]={w,u,v};
            st[u-n].push_back(m);
        }
    }for(int s=1;s<(1<<k);s++)
    {
        int c=-1;for(int i=1;i<=k;i++)
        if(s&(1<<i-1)){c=i;break;}
        ed[s]=mg(ed[s^(1<<c-1)],st[c]);
    }ll ans=1e18+7;
    for(int s=0;s<(1<<k);s++)
    {
        ll vl=0;
        for(int i=1;i<=k;i++)
        if(s&(1<<i-1))vl+=c[i];
        for(int t:ed[s])vl+=e[t][0];
        ans=min(ans,vl);
    }cout<<ans<<'\n';return 0;
}
